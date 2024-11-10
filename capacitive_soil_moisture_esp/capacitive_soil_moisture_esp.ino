#include <Arduino.h>
#define soilMoisturePin 32
int sensorvalue = 0;
// void setup() {
//   Serial.begin(9600);
//   pinMode(soilMoisturePin, INPUT);
// }

// void loop() {
//   int val = analogRead(soilMoisturePin);
//   Serial.println(val);
//   delay(1000);
// }



const int valAir = 1437;
const int valWater = 1106;

void setup() {
  Serial.begin(9600);               // Initialize serial communication
  pinMode(soilMoisturePin, INPUT);  // Set the soil moisture sensor pin as input
}

void loop() {
  // Read the analog value from the soil moisture sensor
  sensorvalue = analogRead(soilMoisturePin);

  // Convert the analog value to percentage
  float moisturePercent = map(sensorvalue, valAir, valWater, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Soil Moisture pin Value: ");
  Serial.println(sensorvalue);

  Serial.print("Soil Moisture Percentage: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(5000);
}
