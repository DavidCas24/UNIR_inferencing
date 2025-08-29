# 💡 Adaptive Telework Environment with AI-based Smart Lighting / Entorno de Teletrabajo Adaptativo con Iluminación Inteligente

## 🌍 Overview / Descripción General

**EN**  
This project, developed as part of the Master's Thesis in IoT at UNIR, presents the design and implementation of a **cyber-physical system** in the form of a smart lamp.  
The lamp integrates **environmental sensors, AI models, and IoT connectivity** to monitor and classify workspace conditions, enhancing **comfort, productivity, and well-being** for remote and hybrid workers.  

**ES**  
Este proyecto, desarrollado como parte del **Trabajo de Fin de Máster en IoT de la UNIR**, consiste en el diseño e implementación de un **sistema ciberfísico** en forma de lámpara inteligente.  
La lámpara integra **sensores ambientales, modelos de IA y conectividad IoT** para monitorizar y clasificar las condiciones del entorno laboral, mejorando el **confort, la productividad y el bienestar** de los trabajadores en remoto o modalidad híbrida.

---

## 🔧 Key Features / Características Principales

- **EN**: Custom PCB integrating multiple sensors (temperature, humidity, light spectrum, noise, CO₂, VOCs).  
- **ES**: PCB personalizada que integra múltiples sensores (temperatura, humedad, espectro lumínico, ruido, CO₂, VOCs).  

- **EN**: Based on open-source **WLED** for dynamic lighting control.  
- **ES**: Basada en **WLED** de código abierto para control dinámico de iluminación.  

- **EN**: Edge AI model (TinyML with Edge Impulse) classifies environmental conditions into: *good, moderate, bad*.  
- **ES**: Modelo de IA en el borde (TinyML con Edge Impulse) que clasifica las condiciones ambientales en: *buenas, moderadas, malas*.  

- **EN**: Real-time data visualization with [Datacake](https://datacake.co).  
- **ES**: Visualización de datos en tiempo real con [Datacake](https://datacake.co).  

---

## 📦 Repository Structure / Estructura del Repositorio

/hardware          → PCB designs, schematics, Gerber files
/firmware          → Source code for microcontrollers (ESP32-C3, Particle Argon)
/docs              → Documentation, diagrams, reports
/enclosure         → 3D design of the lamp enclosure
/datacake-dashboard→ Dashboard configuration & screenshots

---

## 📊 Dashboard Example / Ejemplo de Dashboard

👉 [Datacake Public Dashboard Example](https://datacake.co/blog/public-links-for-device-dashboards-how-to-share-lorawan-mqtt-devices-on-datacake-iot-platform)

---

## 🚀 Getting Started / Cómo Empezar

**EN**  
1. Clone this repository.  
2. Open `/firmware` with PlatformIO or Arduino IDE.  
3. Flash the firmware to your ESP32-C3 or Particle Argon.  
4. Configure Wi-Fi / LoRa / MQTT credentials.  
5. Connect to Datacake to visualize real-time data.  

**ES**  
1. Clona este repositorio.  
2. Abre `/firmware` con PlatformIO o Arduino IDE.  
3. Carga el firmware en tu ESP32-C3 o Particle Argon.  
4. Configura credenciales de Wi-Fi / LoRa / MQTT.  
5. Conéctate a Datacake para visualizar datos en tiempo real.  

---

## 🖥️ System Architecture / Arquitectura del Sistema

![System Architecture](./docs/images/system_architecture.png)  
*(Add your diagram here / Agrega tu diagrama aquí)*

---

## 🙌 Acknowledgments / Agradecimientos

- 👨‍🏭 **SEEEDSTUDIO Fusion PCB Service** for manufacturing the custom PCB.  
- 📊 **Datacake** for IoT device dashboards and remote monitoring.  
- 🛠️ **Adafruit & Edge Impulse** for sensor libraries and TinyML tools.  
- 🎓 **UNIR – Universidad Internacional de La Rioja** for academic guidance.  

---

## 📄 License / Licencia

This project is released under the [MIT License](LICENSE).  
Este proyecto se distribuye bajo la [Licencia MIT](LICENSE).  

---

✍️ Developed by / Desarrollado por:  
**David Felipe Castiblanco Cantor** & **Óscar Martínez Cueto**  
Master in IoT – UNIR, 2025
