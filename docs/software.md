# Software Documentation

# Aegis AI Software Architecture

Version: **1.0**

---

# Overview

Aegis AI uses a modular software architecture that connects artificial intelligence, automation, hardware control, sensor processing, and the web dashboard.

The software is designed so that the AI, backend, automation system, and hardware controllers can communicate through clearly defined interfaces.

The v1.0 software focuses on a reliable **online AI system** and real-time smart-home control.

---

# Programming Languages

- **JavaScript (ES Modules )** — Backend, AI, automation, and dashboard communication
- **C++** — Arduino firmware
- **JSON** — Sensor data, commands, configuration, and system state
- **VITE.JS** — Web Dashboard Interface & Aegis Website

---

# Development Environments

## Arduino IDE

Used for developing firmware for:

- Arduino UNO Q
- Arduino Nano

## Node.js

Used for:

- AI backend
- AI routing
- Sensor processing
- Automation
- Serial communication
- Device control
- System state management

## Web Dashboard

Used as the primary interface for:

- Monitoring the house
- Controlling devices
- Viewing sensor data
- Interacting with Aegis AI
- Viewing system and security status

---

# Software Architecture

The main software flow is:

```text
Sensors
   ↓
Arduino Nano
   ↓
Node.js Backend
   ↓
AI / Automation
   ↓
Command Generator
   ↓
Hardware Controller
   ↓
Physical Device
   ↓
Dashboard / Status
```

The system can therefore complete a full cycle from **sensor input to intelligent decision to physical action**.

---

# Software Components

## Arduino Firmware

Arduino firmware controls the connected hardware.

Responsibilities:

- Read sensors
- Control lights
- Control buzzer
- Control garage servo
- Send sensor data
- Receive hardware commands
- Communicate through Serial

The Arduino Nano primarily acts as the **I/O expansion controller**, while the Arduino UNO Q remains the primary competition controller.

---

## Node.js Backend

The Node.js backend connects the hardware, AI, automation system, and dashboard.

Responsibilities:

- Receive live sensor data
- Process JSON sensor messages
- Maintain current sensor state
- Communicate with hardware
- Execute device commands
- Run automation logic
- Provide data to the dashboard
- Manage system state

Live sensor information is stored and made available to other software components.

---

# AI System

Aegis v1.0 uses an **online AI system** for natural-language understanding and intelligent interaction.

The AI system includes:

- AI Router
- Online AI integration
- Prompt Builder
- Conversation Memory
- House Status Interpreter
- Natural-language command processing
- Hardware command generation

### AI Router

The AI Router manages communication between Aegis and the online AI service.

It determines how user requests are processed and passes the required home information to the AI.

### Prompt Builder

The Prompt Builder provides the AI with relevant system information, including live sensor information and available hardware capabilities.

This allows Aegis to answer questions using the current state of the house rather than inventing values.

### Conversation Memory

Conversation memory allows Aegis to understand references from recent conversations, making interactions more natural.

Examples include:

- "Turn it on again."
- "What about the bedroom?"
- "Turn that off."

### House Status Interpreter

The House Status system converts raw sensor values into useful information such as:

- Temperature status
- Humidity status
- Room brightness
- Motion status
- Gas/air-quality status
- Device status
- Security status

---

# AI v1.0 Scope

Aegis v1.0 currently focuses on **online AI**.

The current release includes:

- Natural-language understanding
- Natural-language device control
- Sensor-aware responses
- House-status questions
- Command generation
- Conversation memory
- Home-mode awareness

### Offline AI

Offline/local AI is **not part of v1.0**.

It is intentionally planned for a future version so that the competition release can concentrate on the reliability of the current online AI system.

---

# Automation Engine

The Automation Engine handles automatic smart-home behaviour without requiring every action to come from the AI.

Current automation areas include:

- Motion-based lighting
- Light-based automation
- Day/night awareness
- Gas-warning behaviour
- Buzzer control
- Manual override
- Home operating modes

The automation system is designed to work alongside AI control.

---

# Home Modes

Aegis supports different operating modes:

## Normal

Normal daily smart-home operation.

## Night

Lighting and security behaviour are adjusted for night time operation.

## Away

Security monitoring is prioritized when the home is assumed to be empty.

## Manual

Automatic behaviour is reduced while allowing direct user control.

---

# Command System

Aegis uses structured commands to control hardware.

Examples include:

```text
LIGHT ON
LIGHT OFF

BUZZER ON
BUZZER OFF

GARAGE OPEN
GARAGE CLOSE
```

Commands generated by the AI or automation system are passed to the hardware-control layer for execution.

Structured commands reduce ambiguity between the AI software and physical hardware.

---

# Communication Layer

The communication layer connects:

- Arduino Nano
- Arduino UNO Q
- Node.js Backend
- AI System
- Dashboard

Communication uses:

- **Serial communication**
- **JSON data**
- Structured hardware commands

Example sensor data:

```json
{
  "temperature": 27.2,
  "humidity": 81,
  "gas": 384,
  "ldr": 41
}
```

This allows live hardware information to be transferred to the software system.

---

# Live Sensor Processing

The backend receives sensor information and maintains the latest known state of the home.

The system can process:

- Temperature
- Humidity
- Gas sensor values
- LDR brightness values
- PIR motion states
- Device states

The AI and automation systems can then use this information when making decisions.

---

# Web Dashboard

The Aegis web dashboard provides the main user interface for the system.

The dashboard can provide:

- Live sensor values
- Device status
- Backend status
- AI status
- Security status
- Home mode controls
- Automation controls
- Event information
- Manual device controls
- AI chat
- Garage control
- Buzzer control
- Lighting control

The dashboard communicates with the backend rather than directly controlling the sensors.

---

# Project Structure

```text
Aegis/

├── ai/
│   ├── router.js
│   ├── online.js
│   ├── prompt.js
│   ├── memory.js
│   └── system_prompt.txt
│
├── automation/
│   ├── automation.js
│   ├── rules.json
│   └── state.json
│
├── house/
│   └── houseStatus.js
│
├── server/
│   └── index.js
│
├── utils/
│
├── latest.json
│
├── docs/
│
└── firmware/
```

The v1.0 structure does **not** require an offline AI module.

---

# Libraries and Dependencies

## Arduino

- DHT sensor library
- Servo library
- Arduino UNO Q communication libraries where required

## Node.js

- `serialport`
- `@serialport/parser-readline`
- `fs`
- `path`
- `readline`

Additional dependencies may be used by the dashboard and AI integration.

---

# Data Flow

A typical sensor-to-AI flow is:

```text
DHT11 / LDR / PIR / MQ-2
            ↓
      Arduino Nano
            ↓
      JSON over Serial
            ↓
      Node.js Backend
            ↓
      latest sensor state
            ↓
     House Status System
            ↓
       AI / Automation
            ↓
      Decision / Command
            ↓
       Hardware Control
            ↓
      Physical Response
```

---

# Example AI Interaction

User:

```text
Turn on the hall light.
```

Aegis processes the request and generates the appropriate hardware command.

```text
Natural Language
      ↓
AI
      ↓
Command Generator
      ↓
Hall Light Command
      ↓
Hardware
      ↓
Hall Light ON
```

For information requests, the AI can use the current sensor state.

Example:

```text
User: What is the temperature?
```

Aegis reads the current sensor information and responds using the available live value.

---

# Design Principles

The software is designed to be:

- Modular
- Scalable
- Maintainable
- Expandable
- Hardware-aware
- AI-ready
- Real-time
- Reliable

The system separates **sensing, communication, intelligence, automation, and physical control** so that individual components can be improved without redesigning the entire project.

---

# Current Software Features — v1.0

- Online AI integration
- AI Router
- Natural-language commands
- Conversation memory
- Live sensor monitoring
- House-status interpretation
- Motion-based automation
- Light-based automation
- Gas monitoring
- Gas-warning logic
- Home modes
- JSON communication
- Hardware command system
- Device control
- Garage control
- Buzzer control
- Serial communication
- Web dashboard
- AI chat interface
- Live system status

---

# Planned Software Features

Future versions may include:

- Offline/local AI
- Advanced event logging
- Automation history
- User-customizable automation rules
- Voice interaction
- Speech-to-text
- Text-to-speech
- Push notifications
- Remote access
- Energy analytics
- Predictive automation
- User preference learning
- Occupancy prediction
- Self-learning automation
- Multi-user support
- Vision-based intelligence

---

# Software Version Direction

```text
v1.0
Online AI + Smart Home Core
        ↓
v1.1
Advanced Automation + Event System
        ↓
v1.2
Offline / Local AI
        ↓
v1.3+
Voice + Advanced Intelligence
        ↓
v2.0
Advanced Autonomous Smart Home Platform
```

---

# Conclusion

Aegis AI v1.0 combines an online AI system, real-time sensor processing, automation, hardware control, and a web dashboard into a single smart-home platform.

The software architecture is designed around a complete intelligent loop:

```text
SENSE
  ↓
UNDERSTAND
  ↓
DECIDE
  ↓
ACT
  ↓
VERIFY
```

The current release focuses on making this core loop reliable and competition-ready, while more advanced capabilities such as offline AI, voice interaction, predictive automation, and self-learning are reserved for future versions.

**Aegis AI v1.0 — From Sensors to Intelligence to Physical Action.**