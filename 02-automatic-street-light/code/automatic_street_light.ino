const int ldrPin = A0;      // LDR sensor input pin
const int ledPin = 13;      // LED output pin
const int threshold = 500;  // Switch light ON below this reading

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);       // Initialize Serial Monitor
}

void loop() {
  int lightLevel = analogRead(ldrPin);
  
  // Print light value to Serial Monitor for testing
  Serial.print("Current Light Level: ");
  Serial.println(lightLevel);

  // Control street light based on ambient light level
  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH); // Dark outside -> Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Bright outside -> Turn LED OFF
  }

  delay(200); // Small delay for stable readings
}
