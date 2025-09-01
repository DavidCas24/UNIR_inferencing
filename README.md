# 💡 Adaptive Telework Environment with AI-based Smart Lighting / Entorno de Teletrabajo Adaptativo con Iluminación Inteligente

---

##  Overview / Descripción General

**EN**  
This project, developed as part of the Master's Thesis in IoT at UNIR, presents the design and implementation of a cyber-physical system embodied in a smart lamp. The lamp integrates environmental sensors, an AI model on the edge, IoT connectivity, and dynamic lighting control to monitor and classify workspace conditions—enhancing comfort, productivity, and well-being for remote and hybrid workers.

**ES**  
Este proyecto, desarrollado como parte del Trabajo de Fin de Máster en IoT de la UNIR, presenta el diseño e implementación de un sistema ciber-físico en forma de lámpara inteligente. La lámpara integra sensores ambientales, un modelo de IA en el borde, conectividad IoT y control dinámico de iluminación para monitorizar y clasificar condiciones del espacio de trabajo—mejorando confort, productividad y bienestar para trabajadores remotos o en modalidad híbrida.

---

##  Key Features / Características Principales

- **EN**: Custom PCB integrating multiple sensors (temperature, humidity, light spectrum, noise, CO₂, VOCs).  
- **ES**: PCB personalizada que integra múltiples sensores (temperatura, humedad, espectro lumínico, ruido, CO₂, COVs).

- **EN**: Based on open-source **WLED** for dynamic lighting control.  
- **ES**: Basada en **WLED** de código abierto para control dinámico de iluminación.

- **EN**: Edge AI model (TinyML with Edge Impulse) classifies environmental conditions into: *good, moderate, bad*.  
- **ES**: Modelo de IA en el borde (TinyML con Edge Impulse) que clasifica las condiciones en: *buenas, moderadas, malas*.

- **EN**: Real-time data visualization with [Datacake].  
- **ES**: Visualización de datos en tiempo real con [Datacake].

---

##  Repository Structure / Estructura del Repositorio

.vscode/ → IDE configuration files.
Hardware/ → PCB designs, schematics, Gerber files.
Diseño Lampará - Lamp Design.zip → 3D model files of the lamp.
examples/static_buffer/ → Code examples (static_buffer).
lib/ → External libraries.
src/ → Source code.
target/6.2.1/argon/ → Compiled output for Argon.
firmware.bin → Compiled firmware binary.
memory-use.log → Memory usage log.
project.properties → Project properties.
README.md → This file.


---

##  Model 3D / 3D Model

- **EN**: Explore the interactive 3D model of the smart lamp online here:  
  👉 [3D Lamp Model](https://lurmis.vercel.app/en)

- **ES**: Explora el modelo 3D interactivo de la lámpara inteligente aquí:  
  👉 [Modelo 3D de la lámpara](https://lurmis.vercel.app/es)

---

##  Dashboard Example / Ejemplo de Dashboard

[Public Datacake Dashboard Example](https://datacake.co/blog/public-links-for-device-dashboards-how-to-share-lorawan-mqtt-devices-on-datacake-iot-platform)

---

##  Getting Started / Cómo Empezar

**EN**  
1. Clone this repository.  
2. Navigate to the `src/` or `Hardware/` folders as needed for code or PCB design.  
3. Open `/firmware` (if existing) with PlatformIO or Arduino IDE, or use `firmware.bin` to flash directly.  
4. Configure Wi-Fi / LoRa / MQTT credentials if applicable.  
5. Deploy or view the project dashboard using Datacake.

**ES**  
1. Clona este repositorio.  
2. Navega a las carpetas `src/` o `Hardware/` según necesites para código o diseño PCB.  
3. Abre `/firmware` (si existe) con PlatformIO o Arduino IDE, o usa `firmware.bin` para flashear directamente.  
4. Configura las credenciales Wi-Fi / LoRa / MQTT si aplica.  
5. Despliega o visualiza el dashboard del proyecto usando Datacake.

---

##  System Architecture / Arquitectura del Sistema

<img width="945" height="484" alt="image" src="https://github.com/user-attachments/assets/d104de6f-2ce4-4e7b-86a0-59acdf961c03" />


---

##  Acknowledgments / Agradecimientos

- **EN**: **SEEEDSTUDIO Fusion PCB Service** for manufacturing the custom PCB.  
- **ES**: **Servicio Fusion PCB de SEEEDSTUDIO** por fabricar la PCB personalizada.

- **EN**: **Datacake** for IoT device dashboards and remote monitoring.  
- **ES**: **Datacake** por proporcionar dashboards IoT y monitoreo remoto.

- **EN**: **Adafruit & Edge Impulse** for sensor libraries and TinyML tools.  
- **ES**: **Adafruit y Edge Impulse** por las bibliotecas de sensores y herramientas TinyML.

- **EN**: **UNIR – Universidad Internacional de La Rioja** for academic guidance.  
- **ES**: **UNIR – Universidad Internacional de La Rioja** por la orientación académica.

---

##  License / Licencia

This project is released under the [MIT License].  
Este proyecto se distribuye bajo la [Licencia MIT].

---

✍️ **Developed by / Desarrollado por:**  
David Felipe Castiblanco Cantor & Óscar Martínez Cueto  
Master in IoT – UNIR, 2025
