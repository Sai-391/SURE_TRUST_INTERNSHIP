int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // Fade In
  for (int duty = 0; duty <= 100; duty += 5) {
    Serial.print("Fading In - Brightness: ");
    Serial.println(duty);

    for (int i = 0; i < 100; i++) {
      digitalWrite(ledPin, HIGH);
      delayMicroseconds(duty * 50);
      digitalWrite(ledPin, LOW);
      delayMicroseconds((100 - duty) * 50);
    }
  }

  // Fade Out
  for (int duty = 100; duty >= 0; duty -= 5) {
    Serial.print("Fading Out - Brightness: ");
    Serial.println(duty);

    for (int i = 0; i < 100; i++) {
      digitalWrite(ledPin, HIGH);
      delayMicroseconds(duty * 50);
      digitalWrite(ledPin, LOW);
      delayMicroseconds((100 - duty) * 50);
    }
  }
}

