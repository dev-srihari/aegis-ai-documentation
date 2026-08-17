# Wiring Guide

Version: **1.0**

This document describes the hardware connections used in the **Aegis AI Smart Home System**.

---

# Controller Overview

## Arduino UNO Q

The **Arduino UNO Q** is the primary controller and main competition board.

Responsibilities:

* Main system controller
* AI integration
* Automation control
* Communication with the backend
* Coordination of the Aegis system

---

## Arduino Nano

The **Arduino Nano** is used as an I/O expansion controller.

Responsibilities:

* Read sensor inputs
* Control output devices
* Send sensor data to the backend
* Execute hardware commands

The Arduino Nano does **not** perform AI decision-making.

---

# Arduino Nano Pin Mapping

## Hall

| Device                              | Pin |
| ----------------------------------- | --: |
| DHT11 Temperature & Humidity Sensor |  D2 |
| PIR Motion Sensor                   |  D3 |
| White Light                         |  D5 |
| LDR Light Sensor                    |  A1 |

---

## Bedroom

| Device            | Pin |
| ----------------- | --: |
| PIR Motion Sensor |  D4 |
| White Light       |  D6 |
| LDR Light Sensor  | TBD |

---

## Kitchen

| Device           | Pin |
| ---------------- | --: |
| MQ-2 Gas Sensor  |  A0 |
| LDR Light Sensor | TBD |
| White Light      | TBD |

> The DHT11 currently documented for Aegis is installed in the **Hall**.

---

## Main Door

| Device    | Pin |
| --------- | --: |
| IR Sensor | TBD |

---

## Garage

| Device      | Pin |
| ----------- | --: |
| IR Sensor   | TBD |
| Servo Motor | TBD |

---

## Alarm

| Device | Pin |
| ------ | --: |
| Buzzer | TBD |

---

# Pin Summary

| Pin | Device      | Location |
| --- | ----------- | -------- |
| D2  | DHT11       | Hall     |
| D3  | PIR         | Hall     |
| D4  | PIR         | Bedroom  |
| D5  | White Light | Hall     |
| D6  | White Light | Bedroom  |
| A0  | MQ-2        | Kitchen  |
| A1  | LDR         | Hall     |

Pins marked **TBD** will be assigned and documented after the remaining hardware connections are finalized.

---

# Communication

The Arduino Nano communicates with the Aegis backend through USB Serial.

```text
Sensors
    │
    ▼
Arduino Nano
    │
    │ USB Serial
    ▼
Node.js Backend
    │
    ▼
Aegis AI / Automation
    │
    ▼
Hardware Commands
```

Sensor readings are transmitted as structured data to the backend, where they are processed by the Aegis software system.

---

# Smart Home Model

The hardware is installed in a miniature smart-home model containing:

* Hall
* Bedroom
* Kitchen
* Main Door
* Garage

Each area contains sensors or devices appropriate to its function.

---

# Current Hardware Connections

### Hall

* DHT11
* PIR Motion Sensor
* LDR
* White Light

### Bedroom

* PIR Motion Sensor
* LDR
* White Light

### Kitchen

* MQ-2 Gas Sensor
* LDR
* White Light

### Main Door

* IR Sensor

### Garage

* IR Sensor
* Servo Motor

### Alarm

* Buzzer

---

# Wiring Status

| Area      | Status      |
| --------- | ----------- |
| Hall      | Connected   |
| Bedroom   | Connected   |
| Kitchen   | In Progress |
| Main Door | In Progress |
| Garage    | In Progress |
| Alarm     | In Progress |

---

# Future Documentation

After the final hardware integration, the following will be added:

* Complete Wiring Diagram
* Final Pin Mapping
* Circuit Schematic
* Breadboard Layout
* Power Distribution Diagram
* Smart Home Model Wiring Layout
* Final Hardware Photographs

---

# Design Principle

The Arduino UNO Q remains the **primary controller and competition board**, while the Arduino Nano provides additional I/O capability for the connected sensors and output devices.
