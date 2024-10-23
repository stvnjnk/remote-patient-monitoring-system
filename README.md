# Remote Patient Monitoring System

**Arduino-based project for tracking vital signs like temperature and heart rate, with real-time alerts sent via SMS for continuous healthcare monitoring.**

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Components](#components)
- [Libraries Used](#libraries-used)
- [Installation](#installation)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)
---

## Overview

This project implements a **Remote Patient Monitoring System** that uses sensors to track key health indicators such as temperature and heart rate. The system alerts medical personnel when the patient's health conditions cross critical thresholds. It provides a robust solution for continuous patient monitoring in hospitals and remote care settings.

---

## Features

- **Real-Time Monitoring:** Tracks patient’s heart rate and temperature.
- **Local Display:** Shows patient name, NHS number, temperature, heart rate, date, and time on an OLED screen.
- **Remote Alerts:** Sends SMS alerts via GSM when critical thresholds are exceeded.
- **Data Storage:** Logs all health data (temperature, heart rate, etc.) to a micro-SD card for reference.
- **Remote Reset and Set:** Allows remote resetting of the system after an alert and re-enables for further monitoring.

---

## Components

- **Microcontroller:** Arduino Mega
- **Sensors:**
  - Heartbeat sensor
  - Temperature sensor (DS18B20)
- **Modules:**
  - RTC Module (DS3232)
  - GSM Module (SIM900)
  - SD Card Module
  - OLED Display
- **Additional Components:** Breadboard, wires, SIM card, power supply.

---

## Libraries Used

- **Adafruit GFX Library** (for OLED display)
- **Adafruit SSD1306 Library** (for OLED display)
- **OneWire Library** (for DS18B20 temperature sensor)
- **DallasTemperature Library** (for DS18B20 sensor)
- **RTClib** (for DS3232 RTC)
- **SD Library** (for data storage)
- **SoftwareSerial** (for GSM communication)

---

## System Design

The system is based on an Arduino Mega microcontroller. The sensors are connected to the Arduino, which collects data such as temperature and heart rate. The data is displayed on an OLED screen, and in case of critical conditions, an alert message is sent via a GSM module. All the data is also stored on an SD card for future reference.

Thresholds for alerts:
- **Temperature** > 20°C (for testing purposes)
- **Heartbeat** > 50 bpm (for testing purposes)

---

## Installation

To install and set up the project:

1. **Clone the Repository:**
    ```bash
    git clone https://github.com/stvnjnk/remote-patient-monitoring-system
    ```

2. **Open the Project in Arduino IDE:**
    - Ensure you have Arduino IDE installed. Download it from [here](https://www.arduino.cc/en/software).
    - Open the `.ino` file in the Arduino IDE.

3. **Install Required Libraries:**
    - Navigate to **Sketch > Include Library > Manage Libraries**.
    - Search and install the following libraries:
      - Adafruit GFX
      - Adafruit SSD1306
      - OneWire
      - DallasTemperature
      - RTClib
      - SD
      - SoftwareSerial

4. **Upload the Code:**
    - Connect the Arduino Mega to your computer.
    - Select the correct board (**Arduino Mega 2560**) and port from **Tools > Board** and **Tools > Port**.
    - Click **Upload** to upload the code to the Arduino.

5. **Assemble the Circuit:**
    - Follow the wiring diagram included in the repository to connect the sensors and modules to the Arduino Mega.

---

## Future Improvements

- Integrate additional sensors (e.g., oxygen saturation, blood pressure) for more comprehensive health monitoring.
- Implement a more user-friendly mobile application interface for receiving alerts and reviewing logs.
- Improve data storage capabilities and add cloud integration for long-term monitoring and analysis.
- Enhance power efficiency for better use in real-life healthcare environments.

---

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for improvements or bug fixes.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

