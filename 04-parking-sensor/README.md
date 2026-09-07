# Project 04: Ultrasonic Parking Sensor

An Arduino-based vehicle reverse parking assistant using an HC-SR04 Ultrasonic Distance Sensor, visual LED indicators, and a Piezo buzzer.


## 📸 Circuit Diagrams

### 1. Idle / Initial Setup (Before Code)

![Idle / Initial Setup](./circuit/circuit%20diagram%20before%20code.png)

### 2. Safe State (> 30 cm) — Green LED ON

![Safe State](./circuit/circuit%20diagram%20in%20safestate.png)

### 3. Danger State (≤ 15 cm) — Red LED ON & Buzzer Alarm

![Danger State](./circuit/circuit%20diagram%20in%20dangerstate.png)

### 4. Schematic Diagram

![Schematic Diagram](./circuit/schematic%20diagram.png)
---
## 📌 Pinout Mapping

| Component | Pin / Terminal | Arduino Pin |
| :--- | :--- | :--- |
| **Ultrasonic Sensor** | TRIG | Digital Pin 2 |
| **Ultrasonic Sensor** | ECHO | Digital Pin 3 |
| **Piezo Buzzer** | Positive (+) | Digital Pin 4 |
| **Green LED** | Anode (+) | Digital Pin 5 |
| **Yellow LED** | Anode (+) | Digital Pin 6 |
| **Red LED** | Anode (+) | Digital Pin 7 |

---

## 🚀 How It Works
- **Safe Zone (> 30 cm)**: Green LED lights up; Buzzer remains silent.
- **Warning Zone (15 cm – 30 cm)**: Yellow LED lights up; Buzzer emits a periodic slow tone.
- **Danger Zone (≤ 15 cm)**: Red LED lights up; Buzzer emits a continuous high-pitch alarm.

---

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
