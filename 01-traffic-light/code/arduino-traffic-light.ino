// Pin Assignments
const int RED_PIN = 11;
const int YELLOW_PIN = 10;
const int GREEN_PIN = 9;
const int BUTTON_PIN = 2;

// Traffic Light States
enum State {
  STATE_GREEN,
  STATE_YELLOW,
  STATE_RED
};

State currentState = STATE_GREEN;
unsigned long stateStartTime = 0;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    
    case STATE_GREEN:
      setLEDs(LOW, LOW, HIGH); // Green ON
      // If button is pressed, switch to Yellow phase
      if (digitalRead(BUTTON_PIN) == LOW) {
        currentState = STATE_YELLOW;
        stateStartTime = currentMillis;
      }
      break;

    case STATE_YELLOW:
      setLEDs(LOW, HIGH, LOW); // Yellow ON
      // Hold Yellow for 2000 ms (2 seconds)
      if (currentMillis - stateStartTime >= 2000) {
        currentState = STATE_RED;
        stateStartTime = currentMillis;
      }
      break;

    case STATE_RED:
      setLEDs(HIGH, LOW, LOW); // Red ON
      // Hold Red for 5000 ms (5 seconds)
      if (currentMillis - stateStartTime >= 5000) {
        currentState = STATE_GREEN;
      }
      break;
  }
}

// Helper function to handle LED states cleanly
void setLEDs(int red, int yellow, int green) {
  digitalWrite(RED_PIN, red);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(GREEN_PIN, green);
}