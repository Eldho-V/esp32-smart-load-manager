# ESP32 Smart Energy Load Manager 🌍⚡

An IoT-enabled sustainable power management system built on the ESP32. This project monitors simulated renewable energy voltages and automatically switches between primary (solar) and secondary (grid) power sources using relay control, ensuring continuous power while shedding non-essential loads during low-generation periods.

## System Architecture
* **Microcontroller:** ESP32 (Dual-core, built-in Wi-Fi & ADC)
* **Inputs:** Analog voltage reading (simulating renewable generation)
* **Outputs:** GPIO-controlled Relays for load switching
* **IoT Dashboard:** Asynchronous web server serving live system metrics

## Repository Structure
* `/src` - Contains the Arduino C++ source code.
* `/docs` - Contains circuit diagrams and logic flowcharts.
