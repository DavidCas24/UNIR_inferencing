# 🌿 Proyecto IoT de Monitoreo Ambiental

Este proyecto consiste en el diseño y despliegue de un sistema IoT de monitoreo ambiental utilizando sensores, una PCB personalizada, comunicación inalámbrica y visualización de datos mediante Datacake.

## 📦 Estructura del Proyecto

- `/hardware`: Archivos de diseño de la PCB (KiCad / Gerber).
- `/firmware`: Código fuente para el microcontrolador.
- `/enclosure`: Diseño de la carcasa para impresión 3D.
- `/docs`: Documentación y manuales técnicos.
- `/datacake-dashboard`: Capturas y configuraciones del panel Datacake.

## 🔧 Componentes Principales de la PCB

- Microcontrolador: [especificar modelo, ej. ESP32-C3]
- Sensor ambiental: [ej. BME280, SHT31, etc.]
- Sensor espectral: Adafruit AS7341
- Conectores: Grove / JST / Terminales de tornillo
- Fuente de alimentación: [ej. USB-C, Lipo, Regulador 3.3V]

Ver archivos en `/hardware` para más detalles de diseño.

## 📡 Visualización en Tiempo Real

Este proyecto utiliza la plataforma [Datacake](https://datacake.co) para visualizar los datos de sensores.

👉 Puedes ver un ejemplo público de dashboard aquí:  
[https://datacake.co/blog/public-links-for-device-dashboards-how-to-share-lorawan-mqtt-devices-on-datacake-iot-platform](https://datacake.co/blog/public-links-for-device-dashboards-how-to-share-lorawan-mqtt-devices-on-datacake-iot-platform)

## 🚀 Cómo Usar

1. Clona el repositorio
2. Abre `/firmware` con PlatformIO o Arduino IDE.
3. Carga el firmware en la placa.
4. Asegúrate de configurar correctamente las credenciales Wi-Fi / LoRa / MQTT.
5. Accede al dashboard público o privado en Datacake.

## 🙌 Agradecimientos

- 👨‍🏭 **SEEEDSTUDIO** por el servicio [Fusion PCB](https://www.seeedstudio.com/fusion.html), que permitió la fabricación rápida y precisa de nuestras placas.

## 📄 Licencia

[MIT License](LICENSE)

---

_Proyecto desarrollado como parte del máster en IoT - 2025_

## ✍️ Autores

•	Desarrolladores principales: David Felipe Castiblanco y Óscar Martínez Cueto.
•	Tutor académico: Iván Arakistain Markina – Máster en IoT


