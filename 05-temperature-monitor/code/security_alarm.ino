const int PIR_PIN = 2;     
const int BUZZER_PIN = 8; 
const int LED_PIN = 13;    


// System State Tracking

int pirState = LOW;       
void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);     
  Serial.println("Security System Initializing...");
  delay(2000);             
  Serial.println("Security System Active!");
}

void loop() {
  int sensorValue = digitalRead(PIR_PIN);

  if (sensorValue == HIGH) {
    // --- Motion Detected Phase ---
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000); // 1000 Hz sound frequency
    
    if (pirState == LOW) {
      Serial.println("⚠️ MOTION DETECTED! ALARM ACTIVATED!");
      pirState = HIGH;
    }
  } else {
    // --- Standby / Quiet Phase ---
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    
    if (pirState == HIGH) {
      Serial.println("Motion ended. System armed and quiet.");
      pirState = LOW;
    }
  }
}