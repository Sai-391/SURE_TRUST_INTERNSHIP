// C++ code
//
int ldrPin = A0;
int potPin = A1;
int bulb1Pin = 8;
int bulb2PwmPin = 9;

void setup() {
  pinMode(bulb1Pin, OUTPUT);
  pinMode(bulb2PwmPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int potValue = analogRead(potPin);
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Brightness: ");
  Serial.println(pwmValue);

  // Auto ON/OFF based on light level
  if (ldrValue < 500) {  
  digitalWrite(bulb1Pin, HIGH);
  } 
  else {
  digitalWrite(bulb1Pin, LOW);
  }


  // Brightness control of second bulb
  analogWrite(bulb2PwmPin, pwmValue);

  delay(200);
}

