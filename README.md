# Remote Patient Monitoring System

**Arduino-based project for tracking vital signs like temperature and heart rate, with real-time alerts sent via SMS for continuous healthcare monitoring.**

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Components Used](#components-used)
- [System Design](#system-design)
- [Installation](#installation)
- [Usage](#usage)
- [Future Improvements](#future-improvements)

---

## Overview

This project implements a **Remote Patient Monitoring System** that uses sensors to track key health indicators such as temperature and heart rate. The system alerts medical personnel when the patient's health conditions cross critical thresholds. It provides a robust solution for continuous patient monitoring in hospitals and remote care settings.

---

## Features

- **Remote Monitoring**: The system sends SMS alerts to a registered mobile number when patient conditions exceed critical thresholds.
- **Data Logging**: Patient data (name, NHS number, date, time, temperature, and heart rate) is stored locally on an SD card for record-keeping.
- **Real-time Display**: Health data is displayed on an OLED screen, including the patient's name, NHS number, temperature, and heartbeat.
- **System Reset**: After receiving alerts, the monitoring station can remotely reset the system to avoid further alerts.

---

## Components Used

- **Arduino Mega**
- **RTC Module (DS3231)**
- **Temperature Sensor (DS18B20)**
- **Heartbeat Sensor**
- **GSM Module**
- **SD Card Module**
- **OLED Display**
- **Breadboard, Jumper Wires**

---

## System Design

The system is based on an Arduino Mega microcontroller. The sensors are connected to the Arduino, which collects data such as temperature and heart rate. The data is displayed on an OLED screen, and in case of critical conditions, an alert message is sent via a GSM module. All the data is also stored on an SD card for future reference.

Thresholds for alerts:
- **Temperature** > 20°C (for testing purposes)
- **Heartbeat** > 50 bpm (for testing purposes)

---

## Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-repo/Remote-Patient-Monitoring-System.git

2. **Upload the Code**
   - Use the Arduino IDE to upload the code to the Arduino Mega.




---

## Future Improvements

- Extend Threshold Range: Adjust threshold values based on actual patient conditions.
- Integrate Additional Sensors: Include sensors like oxygen levels or blood pressure for more comprehensive monitoring.
- Web Dashboard: Add a web-based dashboard for remote monitoring and data visualization.
