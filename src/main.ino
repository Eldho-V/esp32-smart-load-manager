// --- Pin Definitions ---
const int solarSensorPin = 34; // Potentiometer (Still on the right side)
const int solarRelayPin = 21;  // Moved to the left side!
const int gridRelayPin = 22;   // Moved to the left side!

void setup() {
  // Start the serial monitor so we can see the data
  Serial.begin(115200); 

  // Configure the relay pins to send power OUT
  pinMode(solarRelayPin, OUTPUT);
  pinMode(gridRelayPin, OUTPUT);
  
  // Make sure both relays start in the OFF position
  digitalWrite(solarRelayPin, LOW);
  digitalWrite(gridRelayPin, LOW);
  
  Serial.println("Smart Load Manager Initialized.");
}

void loop() {
  // Read the simulated solar voltage
  int solarPower = analogRead(solarSensorPin);
  
  // Print the raw sensor value
  Serial.print("Current Solar Generation: ");
  Serial.print(solarPower);
  
  // --- THE SMART LOAD LOGIC ---
  if (solarPower >= 2000) {
    // We have enough solar power!
    digitalWrite(solarRelayPin, HIGH); // Green LED ON
    digitalWrite(gridRelayPin, LOW);   // Red LED OFF
    Serial.println("  --> Running on Solar Power.");
  } else {
    // Solar power is too low, switch to grid!
    digitalWrite(solarRelayPin, LOW);  // Green LED OFF
    digitalWrite(gridRelayPin, HIGH);  // Red LED ON
    Serial.println("  --> Low Solar! Switched to Grid.");
  }
  
  // Wait half a second before reading again
  delay(500); 
}
