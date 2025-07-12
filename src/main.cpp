#include <Particle.h>               // Librería principal de Particle (manejo del hardware y conectividad)
#include <Wire.h>                   // Para comunicación I2C (sensores)
#include <Adafruit_AS7341.h>       // Librería para controlar el sensor espectral AS7341
#include <UNIR_inferencing.h>      // Librería generada por Edge Impulse para ejecutar inferencias

SYSTEM_THREAD(ENABLED);            // Permite que el sistema ejecute procesos de red en paralelo al loop
SerialLogHandler logHandler(LOG_LEVEL_ERROR); // Solo muestra errores en el log serial

Adafruit_AS7341 as7341;            // Instancia del sensor AS7341

unsigned char buf[20];             // Buffer para guardar los datos del sensor AmbiMate
unsigned long lastSampleTime = 0;  // Control de tiempo de última muestra
float sampPeriod = 30000;          // Periodo de muestreo: cada 30 segundos

#define NORMALIZE(val, min, range) ((val - min) / range)  // Macro para normalizar un valor

const float mins[6]   = {20.00, 30.14, 103.00, 0.00, 403.00, 0.00};     // Valores mínimos de calibración
const float ranges[6] = {13.95, 49.30, 691.00, 9.00, 1595.00, 299.00};  // Rangos de cada variable

static float features[16];         // Arreglo con 16 entradas: 6 ambientales + 10 espectrales

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) { // Función que usa el clasificador para obtener los datos del array features
    memcpy(out_ptr, features + offset, length * sizeof(float));          // Copia los datos de features al puntero de salida
    return 0;                                                             // Retorna 0 indicando éxito
}

void setup() {
    Serial.begin(115200);                                 // Inicia comunicación Serial
    waitFor(Serial.isConnected, 15000);                   // Espera a que el puerto esté conectado
    delay(2000);                                          // Espera adicional de 2 segundos

    if (!as7341.begin()) {                                // Inicializa el AS7341
        Particle.publish("Error", "AS7341 no encontrado"); // Publica un error si no se detecta
        while (1) delay(10);                              // Detiene ejecución
    }

    as7341.setATIME(100);                                 // Configura tiempo de integración
    as7341.setASTEP(999);                                 // Configura pasos de integración
    as7341.setGain(AS7341_GAIN_256X);                     // Configura ganancia

    Wire.begin();                                         // Inicia I2C
    Particle.publish("Inicio", "Dispositivo inicializado"); // Mensaje de inicialización
}

void recolectarDatos() {
    Wire.beginTransmission(0x2A);                         // Dirección del sensor AmbiMate
    Wire.write(byte(0xC0)); Wire.write(byte(0x7F));       // Comando de disparo
    Wire.endTransmission();                               // Finaliza transmisión
    delay(100);                                           // Espera para adquisición
    Wire.beginTransmission(0x2A);                         // Nueva transmisión para lectura
    Wire.write(byte(0x00));                               // Dirección para leer datos
    Wire.endTransmission();                               // Finaliza transmisión
    Wire.requestFrom(0x2A, 15);                           // Solicita 15 bytes de datos
    for (int i = 0; i < 15; i++) buf[i] = Wire.read();    // Lee y guarda en buf

    float tempC = (buf[1] * 256.0 + buf[2]) / 10.0;        // Temperatura (°C)
    float hum = (buf[3] * 256.0 + buf[4]) / 10.0;          // Humedad relativa (%)
    float light = (buf[5] * 256.0 + buf[6]);               // Luz ambiental (lux)
    float audio = (buf[7] * 256.0 + buf[8]);               // Nivel de sonido (unidad relativa)
    float co2 = (buf[11] * 256.0 + buf[12]);               // CO2 (ppm)
    float voc = (buf[13] * 256.0 + buf[14]);               // Compuestos orgánicos volátiles (ppb)

    features[0] = NORMALIZE(tempC, mins[0], ranges[0]);    // Normaliza y asigna temperatura
    features[1] = NORMALIZE(hum,    mins[1], ranges[1]);   // Normaliza y asigna humedad
    features[2] = NORMALIZE(light,  mins[2], ranges[2]);   // Normaliza y asigna luz
    features[3] = NORMALIZE(audio,  mins[3], ranges[3]);   // Normaliza y asigna sonido
    features[4] = NORMALIZE(co2,    mins[4], ranges[4]);   // Normaliza y asigna CO2
    features[5] = NORMALIZE(voc,    mins[5], ranges[5]);   // Normaliza y asigna VOC

    uint16_t readings[12];                                // Lecturas RAW del espectro
    float counts[12];                                     // Lecturas convertidas a basic counts
    if (as7341.readAllChannels(readings)) {               // Si la lectura fue exitosa
        for (int i = 0; i < 12; i++) {
            counts[i] = as7341.toBasicCounts(readings[i]); // Conversión de lectura a unidad básica
        }

        features[6]  = counts[0];   // 415nm (violeta)
        features[7]  = counts[1];   // 445nm (azul)
        features[8]  = counts[2];   // 480nm (cyan)
        features[9]  = counts[3];   // 515nm (verde)
        features[10] = counts[6];   // 555nm (amarillo)
        features[11] = counts[7];   // 590nm (naranja)
        features[12] = counts[8];   // 630nm (rojo-naranja)
        features[13] = counts[9];   // 680nm (rojo)
        features[14] = counts[10];  // Intensidad total del espectro
        features[15] = counts[11];  // Infrarrojo cercano (NIR)
    } else {
        Particle.publish("Error", "Lectura AS7341 fallida"); // Publica error si la lectura falla
    }
}

void ejecutarInferencia() {
    ei_impulse_result_t result = { 0 };                   // Estructura donde se guarda el resultado
    signal_t features_signal;                             // Señal que representa los datos de entrada
    features_signal.total_length = sizeof(features) / sizeof(features[0]); // Largo del vector
    features_signal.get_data = &raw_feature_get_data;     // Función que proporciona los datos al modelo

    EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false); // Ejecuta inferencia
    if (res != EI_IMPULSE_OK) {                           // Si hay error en la inferencia
        ei_printf("Error de inferencia: (%d)\n", res);    // Muestra el error por consola
        return;                                           // Sale de la función
    }

    String msg = "Inferencia: ";                          // Mensaje base
    for (uint16_t i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) { // Recorre cada categoría
        msg += String(ei_classifier_inferencing_categories[i]) + ": "; // Agrega nombre de categoría
        msg += String(result.classification[i].value, 5);  // Agrega valor de probabilidad
        if (i < EI_CLASSIFIER_LABEL_COUNT - 1) msg += ", "; // Agrega coma si no es la última
    }

    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        msg += ", Anomalía: ";                            // Si el modelo detecta anomalías
        msg += String(result.anomaly, 3);                 // Agrega valor de anomalía
    #endif

    Particle.publish("Inferencia_Resultados", msg, PRIVATE); // Publica resultados en la nube (modo privado)
}

void loop() {
    if (millis() - lastSampleTime >= sampPeriod) {        // Verifica si ha pasado el tiempo de muestreo
        lastSampleTime = millis();                        // Actualiza la marca de tiempo
        recolectarDatos();                                // Llama a función de recolección
        ejecutarInferencia();                             // Ejecuta la inferencia con los datos
    }
}
