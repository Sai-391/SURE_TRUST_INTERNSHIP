#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0); 

int gasPin = A0;
int greenLed = 8;
int redLed = 9;
int buzzer = 10;

int threshold = 300; // Default threshold

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("Gas Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasValue = analogRead(gasPin);
  float voltage = gasValue * (5.0/1023.0);
  int ppm = map(gasValue, 0, 1023, 0, 1000);

  // Allow threshold change from Serial
  if (Serial.available()) {
    threshold = Serial.parseInt();
    Serial.print("Threshold updated to: ");
    Serial.println(threshold);
  }

  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(gasValue);
  lcd.print("    ");

  if (gasValue < threshold) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE    ");
  } else {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Status: DANGER  ");
  }

  delay(500);
}


