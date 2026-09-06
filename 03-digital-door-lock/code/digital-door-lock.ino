#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// LCD Pin configuration: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(11, 12, A0, A1, A2, A3);

// Servo motor setup
Servo lockServo;
const int SERVO_PIN = 9;

// Keypad Configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 10};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Secret Password Configuration
const String SECRET_CODE = "1234";
String inputCode = "";

void setup() {
  lcd.begin(16, 2);
  lockServo.attach(SERVO_PIN);
  
  // Lock position initially (0 degrees)
  lockServo.write(0);
  
  showPrompt();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // '#' acts as Enter key
      checkPassword();
    } else if (key == '*') { // '*' acts as Clear key
      inputCode = "";
      showPrompt();
    } else {
      inputCode += key;
      lcd.setCursor(0, 1);
      lcd.print("    "); // Clear prior line segment
      lcd.setCursor(0, 1);
      for (int i = 0; i < inputCode.length(); i++) {
        lcd.print("*"); // Mask password entry
      }
    }
  }
}

void showPrompt() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

void checkPassword() {
  lcd.clear();
  if (inputCode == SECRET_CODE) {
    lcd.setCursor(0, 0);
    lcd.print("Access Granted!");
    lockServo.write(90); // Unlock position
    delay(4000);         // Keep unlocked for 4 seconds
    lockServo.write(0);  // Re-lock
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Wrong Password!");
    delay(2000);
  }
  inputCode = "";
  showPrompt();
}