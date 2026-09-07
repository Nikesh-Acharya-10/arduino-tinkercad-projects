// Pin Definitions
const int TRIG_PIN = 2;
const int ECHO_PIN = 3;
const int BUZZER_PIN = 4;
const int GREEN_LED = 5;
const int YELLOW_LED = 6;
const int RED_LED = 7;

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo duration
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0344 / 2; // Convert duration to cm

  // Reset indicator outputs
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER_PIN);

  // Distance Logic
  if (distance > 30) {
    // Safe distance: Green LED ON, No Buzzer
    digitalWrite(GREEN_LED, HIGH);
  } else if (distance > 15 && distance <= 30) {
    // Warning distance: Yellow LED ON, Slow Beep
    digitalWrite(YELLOW_LED, HIGH);
    tone(BUZZER_PIN, 1000);
    delay(100);
    noTone(BUZZER_PIN);
    delay(200);
  } else if (distance <= 15 && distance > 0) {
    // Danger distance: Red LED ON, Continuous Beep
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER_PIN, 2000);
  }

  delay(100);
}