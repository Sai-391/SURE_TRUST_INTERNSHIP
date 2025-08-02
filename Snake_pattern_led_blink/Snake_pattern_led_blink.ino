int ledPins[] = {2, 3, 4, 5, 6, 7,8,9,10,11,12,13}; // 12 LEDs
int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); 

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Forward snake (one LED ON at a time)

  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200); // faster delay
    digitalWrite(ledPins[i], LOW);
    
  }

  // Backward snake
  for (int i = numLeds - 2; i >= 0; i--) {
    
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
  }
}




