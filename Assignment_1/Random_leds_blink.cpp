const int led1 = 8;
const int led2 = 9;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
 //randomSeed(analogRead(A0)); 
}

void loop() {
  int state = random(0, 3); 
  if (state == 0) {
    // Turn ON LED1, OFF LED2
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else if (state == 1) {
    // Turn ON LED2, OFF LED1
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  } else {
    // Both LEDs OFF
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

  // Random delay between 200ms and 1000ms
  delay(random(1000, 2000));
}

