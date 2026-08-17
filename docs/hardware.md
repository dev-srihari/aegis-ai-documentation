# Hardware Documentation

This document describes the hardware architecture, sensors, actuators, communication system, and physical smart-home model used in the **Aegis AI Smart Home System v1.0**.

---

# 1. System Hardware Architecture

Aegis uses a distributed hardware architecture consisting of:

- Arduino UNO Q — primary competition board and main system controller
- Arduino Nano — I/O expansion controller
- Environmental sensors
- Security sensors
- Lighting devices
- Garage servo motor
- Alarm buzzer

The architecture separates the high-level intelligence and system coordination from the large number of physical sensor and actuator connections.

---

# 2. Main Controller

## Arduino UNO Q

The **Arduino UNO Q** is the primary competition board and central controller of the Aegis system.

It provides the main hardware platform around which the Aegis system is built and coordinates communication between the physical hardware and the software system.

The UNO Q is responsible for the system-level hardware architecture, including:

- Coordinating connected hardware
- Communicating with the software/backend system
- Receiving and forwarding system commands
- Supporting the Aegis control architecture
- Providing the primary competition-board platform

The AI decision-making layer is integrated with the software/backend architecture rather than being treated as a simple sensor-level program running independently on the Nano.

The UNO Q therefore remains the **main board of the project**, while the Nano is used to expand the available hardware I/O.

---

# 3. I/O Expansion Controller

## Arduino Nano

The **Arduino Nano** is used as an auxiliary I/O expansion controller.

The Aegis smart home contains multiple sensors and output devices. Using the Nano allows these devices to be connected and managed without placing all sensor and actuator connections directly on the UNO Q.

The Nano is responsible for:

- Reading connected sensors
- Collecting sensor measurements
- Controlling connected lights
- Controlling the alarm buzzer
- Communicating sensor data through serial communication
- Receiving and executing hardware commands
- Providing hardware-state information to the software system

The Nano **does not perform the main AI reasoning**.

It acts as a hardware interface between the connected sensors/actuators and the rest of the Aegis system.

This separation allows the AI and software architecture to remain independent from low-level GPIO operations.

---

# 4. Sensors

Aegis v1.0 uses multiple sensors distributed across the miniature home.

## 4.1 Hall

The Hall contains:

- DHT11 Temperature & Humidity Sensor
- LDR Light Sensor
- PIR Motion Sensor
- Light LED

### DHT11

The DHT11 provides:

- Temperature
- Relative humidity

The Hall DHT11 is used as the environmental reference sensor for the current Aegis model.

### LDR

The LDR measures the amount of ambient light.

Aegis interprets the reading into meaningful environmental states such as:

- Dark
- Dim
- Bright

This information can be used by the automation system when deciding whether lighting should be activated.

### PIR Motion Sensor

The Hall PIR detects movement in the Hall.

Motion information can be used for:

- Occupancy awareness
- Automatic lighting
- Security monitoring
- Automation decisions

---

# 4.2 Bedroom

The Bedroom contains:

- LDR Light Sensor
- PIR Motion Sensor
- Light LED

The LDR provides bedroom brightness information.

The PIR provides bedroom motion information.

Together, these sensors allow Aegis to determine whether the bedroom is dark and whether movement is currently detected.

This information can be used by the automation engine for intelligent lighting and security-related decisions.

---

# 4.3 Kitchen

The Kitchen contains:

- Light LED
- MQ-2 Gas Sensor


### MQ-2

The MQ-2 is used to detect potentially unsafe gas/smoke conditions.

Aegis processes the sensor reading and converts it into a higher-level safety state rather than requiring the user to interpret the raw analog value.

The gas monitoring system can be integrated with the alarm system so that a dangerous condition can trigger an appropriate warning.

---

# 4.4 Main Entrance

The current v1.0 hardware configuration does **not depend on the previously planned IR obstacle sensor** for the main-door system.

The security architecture is designed to be expandable, allowing additional entrance sensors to be added in future versions.

This keeps the current prototype focused on the core demonstrated capabilities while leaving room for additional security hardware.

---

# 4.5 Garage

The Garage contains the garage-door actuator:

- Servo Motor

The servo represents the garage door mechanism in the miniature smart-home model.

Aegis can control the garage using high-level commands such as:

`GARAGE OPEN`

and

`GARAGE CLOSE`

The command is translated by the hardware-control layer into the appropriate servo operation.

---

# 5. Output Devices

The Aegis prototype contains the following primary actuators:

- Hall White Light
- Bedroom White Light
- Kitchen White Light
- Garage Door Servo Motor
- Alarm Buzzer

---

# 5.1 Smart Lights

Three white lights are installed in the:

- Hall
- Bedroom
- Kitchen

Each light can be controlled individually.

The lights can be operated through:

- Dashboard controls
- Natural-language AI commands
- Automation rules

For example:

**User request:**

"Turn on the Hall light."

**Hardware command:**

`LIGHT ON`

The software system determines the requested device and action before the command reaches the hardware controller.

---

# 5.2 Garage Servo

The garage servo represents an automated garage door.

The AI/software system uses dedicated commands:

`GARAGE OPEN`

`GARAGE CLOSE`

The Nano controls the physical servo mechanism according to the received command.

The dashboard can also display the garage state.

---

# 5.3 Alarm Buzzer

The buzzer acts as the primary audible warning actuator.

The hardware command interface uses:

`BUZZER ON`

`BUZZER OFF`

The buzzer can be activated manually through the dashboard or as part of safety/security automation.

For example:

**Gas danger detected → Buzzer ON**

The buzzer provides a physical indication of an important safety or security condition.

---

# 6. Communication Architecture

The Aegis system uses serial communication between the hardware and software components.

The general architecture is:

```text
        PHYSICAL SENSORS
              │
              ▼
       Arduino Nano
      I/O Expansion
              │
              │ Serial Data
              ▼
       Aegis Backend
       / Node.js Layer
              │
       ┌──────┴──────┐
       │             │
       ▼             ▼
   AI Decision    Automation
      Engine        Engine
       │             │
       └──────┬──────┘
              ▼
       Command Layer
              │
              ▼
       Hardware Controller
              │
       ┌──────┼──────────┐
       ▼      ▼          ▼
     Lights  Buzzer     Servo
```

The backend receives live sensor information and maintains the current state of the house.

When a user or automation rule requests an action, the command is passed through the control layer to the appropriate hardware.

---

# 7. Sensor Data Processing

The Nano collects raw sensor values.

The software system then converts these values into meaningful information.

For example:

```text
LDR raw value
      ↓
Aegis interpretation
      ↓
Dark / Dim / Bright
```

Similarly:

```text
MQ-2 sensor reading
      ↓
Aegis safety processing
      ↓
Gas Safe / Gas Warning
```

This allows the user to interact with meaningful information instead of having to understand raw electrical sensor readings.

---

# 8. Hardware Feedback

Aegis is designed as a feedback-based system.

Commands are not treated as the final state of a device.

The system maintains device information such as:

- Light state
- Buzzer state
- Garage state
- Sensor readings
- Hardware communication status

This allows the dashboard and AI system to display the current house state.

The overall process is:

```text
Sense
  ↓
Transmit
  ↓
Interpret
  ↓
Decide
  ↓
Command
  ↓
Actuate
  ↓
Verify / Update State
```

This feedback architecture connects the AI software with the physical smart-home model.

---

# 9. Smart Home Model

All hardware is installed inside a miniature smart-home model representing a real residential environment.

The model contains:

- Hall
- Bedroom
- Kitchen
- Main Entrance
- Garage

Each area demonstrates a different aspect of smart-home automation and security.

### Hall

Demonstrates:

- Temperature monitoring
- Humidity monitoring
- Light detection
- Motion detection
- Smart lighting

### Bedroom

Demonstrates:

- Light detection
- Motion detection
- Smart lighting

### Kitchen

Demonstrates:

- Light detection
- Gas/smoke monitoring
- Smart lighting

### Garage

Demonstrates:

- Automated garage-door control
- Servo-based physical actuation

### Main Entrance

Represents the security-entry area and provides space for future expansion of entrance security sensors.

---

# 10. Hardware Summary

|    Component  |      | Quantity|   |                    Purpose                        |
|---------------|      |---------|   |---------------------------------------------------|
| Arduino UNO Q           | 1 |      |   Primary competition board and system controller |
| Arduino Nano            | 1 |      |   I/O expansion and hardware control              |
| DHT11                   | 1 |      |   Hall temperature and humidity monitoring        |
| PIR Motion Sensor       | 2 |      |   Hall and Bedroom motion detection               |
| LDR Sensor              | 3 |      |   Hall, Bedroom and Kitchen brightness detection  |
| MQ-2 Gas Sensor         | 1 |      |   Kitchen gas/smoke monitoring                    |
| Servo Motor             | 1 |      |   Garage door mechanism                           |
| White Lights            | 3 |      |   Hall, Bedroom and Kitchen lighting              |
| Buzzer                  | 1 |      |   Safety and security alarm                       |

---

# 11. Hardware Design Philosophy

Aegis uses a **distributed hardware architecture**.

The Arduino UNO Q remains the primary competition board and central system platform.

The Arduino Nano is used specifically as an **I/O expansion controller**, allowing Aegis to connect multiple sensors and actuators while keeping the main system architecture organized.

The hardware is intentionally modular.

This means additional components can be introduced without redesigning the complete system.

For example, future versions could add:

- Additional security sensors
- More room sensors
- Door sensors
- Camera systems
- Additional actuators
- More environmental sensors

The current prototype therefore demonstrates the core architecture while leaving the system open for expansion.

---

# 12. Current v1.0 Hardware Scope

The current Aegis prototype focuses on five major capabilities:

1. **Environmental Monitoring**
2. **Motion Detection**
3. **Smart Lighting**
4. **Gas Safety Monitoring**
5. **Physical Device Automation**

These capabilities demonstrate how AI, sensors, software, and physical actuators can work together as one intelligent smart-home system.

---

# 13. Future Hardware Expansion

Future versions of Aegis can expand the physical system with additional hardware such as:

- Dedicated door sensors
- Additional PIR sensors
- More environmental sensors
- Camera-based monitoring
- Additional rooms
- Energy-monitoring hardware
- Additional smart appliances
- More advanced actuators

The architecture is designed so that new hardware can be integrated without changing the fundamental Aegis concept.

---

# 14. Final Architecture

The final v1.0 hardware concept can be summarized as:

```text
                 AEGIS AI SYSTEM
                       │
                       ▼
                Arduino UNO Q
              Primary Competition
                    Board
                       │
                       │
              System Communication
                       │
                       ▼
                 Aegis Backend
                       │
              ┌────────┴────────┐
              │                 │
              ▼                 ▼
          AI Engine       Automation Engine
              │                 │
              └────────┬────────┘
                       ▼
                Command Layer
                       │
                       ▼
                 Arduino Nano
                I/O Expansion
                       │
       ┌───────────────┼────────────────┐
       │               │                │
       ▼               ▼                ▼
    Sensors         Lights           Actuators
       │               │                │
   DHT11/LDR       3 Lights       Servo + Buzzer
   PIR/MQ-2
```

The architecture allows Aegis to connect **physical sensing, artificial intelligence, automation, and physical actuation** into a single smart-home system.

**Aegis v1.0 — Sense → Understand → Decide → Act → Verify**