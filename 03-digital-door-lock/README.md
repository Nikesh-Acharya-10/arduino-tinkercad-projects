# Project 03: Digital Door Lock

An Arduino-based digital security door lock system utilizing a 4x4 Keypad, Servo Motor, and a 16x2 LCD display to grant or deny access based on password input.

---

## 📸 Circuit Diagrams

### Before Entering Password (Locked State)
![Circuit Diagram Before Password](./circuit/circuit%20diagram%20before%20password.png)

### After Entering Password (Unlocked State)
![Circuit Diagram After Password](./circuit/circuit%20diagram%20after%20password.png)

---

## 🛠 Components Used
- Arduino Uno R3
- 4x4 Keypad
- Micro Servo Motor
- 16x2 LCD Display
- 220Ω Resistor
- Breadboard & Jumper Wires

---

## 📌 Pinout Mapping

| Component | Component Pin | Arduino Pin / Connection |
| :--- | :--- | :--- |
| **Servo Motor** | Signal | Digital Pin 9 |
| **Servo Motor** | VCC / GND | 5V / GND Rail |
| **Keypad** | Rows 1 – 4 | Digital Pins 2, 3, 4, 5 |
| **Keypad** | Columns 1 – 4 | Digital Pins 6, 7, 8, 10 |
| **LCD Display** | RS, E | Digital Pins 11, 12 |
| **LCD Display** | Data Pins (D4 – D7) | Analog Pins A0, A1, A2, A3 |
| **LCD Display** | VSS, VDD, V0, RW | GND, 5V, GND, GND |
| **LCD Backlight** | LED+ (Anode) | 5V via 220Ω Resistor |
| **LCD Backlight** | LED- (Cathode) | GND |

---

## 🚀 How It Works
1. The system defaults to a **Locked** state with the Servo at **0°**.
2. The LCD displays `Enter Password:`.
3. The user inputs keys via the 4x4 Keypad:
   - Typing digits masks the output on the LCD with `*`.
   - Pressing `#` acts as **Enter** to verify the password.
   - Pressing `*` acts as **Clear** to reset the input buffer.
4. **Correct Password (`1234`)**:
   - LCD displays `Access Granted!`.
   - Servo motor rotates to **90°** to open the lock.
   - Remains unlocked for 4 seconds before re-locking automatically.
5. **Incorrect Password**:
   - LCD displays `Wrong Password!`.
   - System prompts for re-entry.

---

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details.
