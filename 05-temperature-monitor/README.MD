# Arduino Security Alarm System with PIR Sensor

An automated intruder detection and security alarm system built using an Arduino Uno, a PIR (Passive Infrared) motion sensor, a piezo buzzer, and a visual LED indicator. The system continuously monitors for movement and triggers simultaneous audible and visual alerts upon motion detection.

---

## 📌 Project Overview

Traditional perimeter security systems rely on continuous human monitoring or constant power draw. This project implements an event-driven security system using a PIR sensor to detect thermal changes and motion. Upon detection, it triggers a 1000 Hz sound alarm via a piezo buzzer, lights up a red warning LED, and logs real-time security alerts over Serial communication.

---

## 🛠️ Components & Tools

* **Microcontroller:** Arduino Uno R3
* **Sensor:** PIR Motion Sensor (HC-SR501 / Tinkercad PIR)
* **Visual Output:** 🔴 Red LED (Standard 5mm)
* **Audible Output:** Piezo Buzzer
* **Resistor:** $220\Omega$ Resistor (Current-limiting for LED)
* **Prototyping:** Breadboard & Jumper Wires
* **Simulation Software:** Tinkercad Circuits

---

## 🔌 Circuit Diagram & Connections

The circuit was designed, wired, and verified in Tinkercad Circuits.

<p align="center">
  <img src="circuit/circuit-diagram.png" alt="Arduino Security Alarm Circuit Output" width="600"/>
</p>

### Pin & Breadboard Mapping

| Component | Component Pin / Terminal | Breadboard Hole | Arduino Pin / Rail |
| :--- | :--- | :--- | :--- |
| **Arduino Power** | 5V | — | Red (+) Power Rail |
| **Arduino Ground** | GND | — | Black (-) GND Rail |
| **PIR Sensor** | VCC | — | Red (+) Power Rail |
| **PIR Sensor** | GND | — | Black (-) GND Rail |
| **PIR Sensor** | OUT (Signal) | — | Digital Pin **2** |
| **Piezo Buzzer** | Positive (+) | **a12 / c12** | Digital Pin **8** |
| **Piezo Buzzer** | Negative (-) | **a14 / c14** | Black (-) GND Rail |
| **Red LED** | Anode (+) | **f18 / j18** | Digital Pin **13** |
| **Red LED** | Cathode (-) | **e18** | Connected to $220\Omega$ Resistor (**d18**) |
| **220Ω Resistor** | Top Leg | **d18** | Connected to LED Cathode (**e18**) |
| **220Ω Resistor** | Bottom Leg | — | Black (-) GND Rail |

---

## ⚙️ Working Principle

1. **Sensor Calibration:** Upon startup, the system initializes serial logging (9600 baud) and allows 2 seconds for the PIR sensor infrared baseline to stabilize.
2. **Signal Polling:** Digital Pin **2** reads the PIR sensor output (`HIGH` for motion detected, `LOW` for standby).
3. **Alert Triggering:**
   * **`Motion Detected (HIGH)`:** Sets Digital Pin **13** `HIGH` to turn on the Red LED, calls `tone(8, 1000)` to play a 1000 Hz tone on the buzzer, and logs `⚠️ MOTION DETECTED! ALARM ACTIVATED!` to the Serial Monitor.
   * **`No Motion (LOW)`:** Sets Digital Pin **13** `LOW` to extinguish the LED, invokes `noTone(8)` to silence the buzzer, and logs `Motion ended. System armed and quiet.` to indicate standby mode.

```text
         [ System Start ]
                │
                ▼
        Calibrate Sensor (2s)
                │
                ▼
       Read PIR Sensor (Pin 2)
                │
      Is Motion Detected?
           /        \
    (Yes) /          \ (No)
         ▼            ▼
    • LED ON       • LED OFF
    • Tone 1000Hz  • Silent (noTone)
    • Log Alert    • Standby Mode
