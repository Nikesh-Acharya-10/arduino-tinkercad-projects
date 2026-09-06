# Automatic Street Light System using Arduino

An automated street light control system built with an Arduino Uno and a Photoresistor (LDR). The system reads ambient light levels in real time and automatically turns on the light during low-ambient or nighttime conditions and turns it off during daylight.

---

## 📌 Project Overview

Traditional street lights often operate on manual schedules, leading to unnecessary energy consumption. This project solves that efficiency problem by using a Light Dependent Resistor (LDR) to dynamically detect surround brightness and automate the power state of the lamp (simulated via an LED).

---

## 🛠️ Components & Tools

* **Microcontroller:** Arduino Uno R3
* **Sensor:** LDR (Photoresistor)
* **Output:** LED (Standard 5mm)
* **Resistors:**
  * $10\text{k}\Omega$ Resistor (Pull-down for LDR voltage divider)
  * $220\Omega$ Resistor (Current-limiting for LED)
* **Prototyping:** Breadboard & Jumper Wires
* **Simulation Software:** Tinkercad Circuits

---

## 🔌 Circuit Diagram & Connections

The circuit design was created and verified inside Tinkercad Circuits.

![Automatic Street Light Circuit](circuit/circuit.png)

### Pin Mapping

| Component | Component Pin | Arduino Pin / Rail |
| :--- | :--- | :--- |
| **LDR** | Leg 1 | 5V Power Rail |
| **LDR** | Leg 2 | Analog Pin **A0** |
| **10kΩ Resistor** | Top Leg | Analog Pin **A0** (Junction) |
| **10kΩ Resistor** | Bottom Leg | GND Rail |
| **LED** | Anode (+) | Digital Pin **13** |
| **LED** | Cathode (-) | $220\Omega$ Resistor |
| **220Ω Resistor** | Bottom Leg | GND Rail |

---

## ⚙️ Working Principle

1. **Voltage Divider Setup:** The LDR and the $10\text{k}\Omega$ resistor form a voltage divider network connected to analog input pin **A0**.
2. **Analog Signal Processing:** As ambient light drops, the LDR’s electrical resistance increases. This alters the voltage reading at pin **A0** (analog range: 0–1023).
3. **Control Logic:** The Arduino constantly compares the analog input against a predefined light threshold:
   * **`Light Level < Threshold` (Dark):** Set Digital Pin 13 to `HIGH` $\rightarrow$ **LED ON**
   * **`Light Level >= Threshold` (Bright):** Set Digital Pin 13 to `LOW` $\rightarrow$ **LED OFF**

```text
       [ Start ]
           │
           ▼
    Read Analog A0 (LDR)
           │
           ▼
   Is Light Level < Threshold?
         /   \
  (Yes) /     \ (No)
       ▼       ▼
    LED ON   LED OFF