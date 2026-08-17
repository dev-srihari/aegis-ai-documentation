# Aegis AI

# Autonomous Smart Home Guardian

**Version:** v1.0

Aegis AI is an intelligent smart home system developed by **Sri Hari S A** for the **Arduino Physical AI Challenge India 2026**.

Aegis combines embedded hardware, artificial intelligence, home automation, and a custom software platform to create a safer, smarter, and more energy-aware home.

Unlike traditional automation systems, Aegis can understand natural-language commands, monitor the current state of the home, interpret live sensor data, and automatically respond to events such as motion, darkness, and gas detection.

---

# Project Goals

- Improve home safety
- Automate daily tasks
- Reduce unnecessary energy usage
- Monitor environmental conditions
- Detect potentially dangerous conditions
- Assist users through AI
- Create an expandable smart home platform

---

# Current Features — v1.0

## Artificial Intelligence

- AI Router
- Natural Language Understanding
- Natural Language Device Control
- JSON Command Generation
- Conversation Memory
- Live Sensor Awareness
- Real-Time Home Status Responses
- House Status Interpretation
- Home Mode Awareness

> **Note:** Offline AI is planned for a future version and is not part of the current v1.0 release.

## Home Automation

- Motion-Based Smart Lighting
- Day/Night Lighting
- Gas Leak Detection
- Emergency Alarm
- Manual Override
- Home Modes:
  - Normal
  - Night
  - Away
  - Manual

## Monitoring

- Temperature Monitoring
- Humidity Monitoring
- Air Quality Monitoring
- Motion Detection
- Room Brightness Detection
- Device Status Monitoring

## Hardware Control

- Hall Light
- Bedroom Light
- Buzzer
- Garage Servo Integration

---

# Hardware

## Main Controller

- Arduino UNO Q

## I/O Expansion

- Arduino Nano

The Arduino Nano is used as an auxiliary I/O controller for additional sensors and output devices. AI decision-making remains part of the main Aegis software architecture.

## Sensors

- DHT11 Temperature & Humidity Sensors
- MQ-2 Gas Sensor
- PIR Motion Sensors
- LDR Light Sensors
- IR Sensors

## Output Devices

- White LEDs / Room Lights
- Servo Motor
- Buzzer

## Planned Expansion

- TTP223 Touch Sensors
- Additional Environmental Sensors
- Camera Module

---

# Software Stack

- Arduino IDE
- C++
- Node.js
- JavaScript (ES Modules)
- JSON
- Serial Communication
- AI Router
- Automation Engine

---

# Current Project Status

## Completed

### Artificial Intelligence

- AI Router
- Natural Language Commands
- Conversation Memory
- Live Sensor Awareness
- Real Sensor Responses
- JSON Command System
- House Status Interpretation

### Hardware

- Arduino UNO Q
- Arduino Nano I/O Expansion
- DHT11
- MQ-2
- PIR Sensors
- LDR Sensors
- Hall Lighting
- Bedroom Lighting
- Buzzer

### Communication

- Serial Communication
- Node.js Backend
- Live Sensor Updates
- Device Command Execution
- JSON-Based Communication

### Automation

- Motion-Based Lighting
- Day/Night Detection
- Gas Leak Alarm
- Manual Override
- Home Modes

---

## In Progress

- Final Hardware Integration
- Garage Automation
- IR Sensor Integration
- Event Logging
- Web Dashboard
- Final Documentation
- System Testing

---

## Planned

- Offline AI
- Mobile Application
- Voice Commands
- Push Notifications
- Remote Monitoring
- Learning AI
- Energy Analytics
- Camera Integration
- Advanced Automation

---

# Architecture

```text
                    ┌──────────────────┐
                    │    User / AI     │
                    │ Natural Language  │
                    └────────┬─────────┘
                             │
                             ▼
                    ┌──────────────────┐
                    │    AI Router     │
                    └────────┬─────────┘
                             │
                             ▼
                    ┌──────────────────┐
                    │ Automation /     │
                    │ House Status     │
                    └────────┬─────────┘
                             │
                    ┌────────┴─────────┐
                    │                  │
                    ▼                  ▼
             ┌─────────────┐    ┌──────────────┐
             │ Arduino UNO │    │ Node.js      │
             │ Q           │◄──►│ Backend      │
             └──────┬──────┘    └──────┬───────┘
                    │                  │
                    │                  │ Serial
                    │                  ▼
                    │           ┌──────────────┐
                    │           │ Arduino Nano │
                    │           │ I/O Expansion│
                    │           └──────┬───────┘
                    │                  │
                    └──────────┬───────┘
                               ▼
                    Sensors & Devices
```

---

# Documentation

Detailed technical documentation is available in the **docs/** directory.

Current documentation includes:

- Project Overview
- Hardware Documentation
- Wiring Guide
- AI System
- Software Architecture
- Automation System
- Development Roadmap
- Changelog
- Installation Guide
- User Guide

---

# Competition

This project is being developed for:

**Arduino Physical AI Challenge India 2026**

The current **v1.0** release focuses on demonstrating the core AI, hardware, communication, monitoring, and automation capabilities of Aegis.

---

# Links

### Website

https://aegis-ai-arduino.vercel.app/

### GitHub

https://github.com/dev-srihari/aegis-ai-documentation

### YouTube

(Add YouTube Channel)

### Portfolio

https://sri-hari.vercel.app/

---

# Creator

**Sri Hari S A**

Kerala, India

Arduino Physical AI Challenge India 2026 Participant

---

# Version

**Aegis AI v1.0**

**Competition Release**

Under Active Development