int buttonPin = 8;
int redPin = 2;
int greenPin = 5;
int bluePin = 4;

unsigned long pressStart = 0;
unsigned long pressDuration = 0;
unsigned long lastPressTime = 0;
bool buttonPressed = false;
int pressCount = 0;

void setup() {
  pinMode(buttonPin, INPUT);  // Using external pull-down resistor
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static bool lastButtonState = LOW;
  bool currentButtonState = digitalRead(buttonPin);
  unsigned long currentTime = millis();

  // Detect button press (LOW → HIGH)
  if (lastButtonState == LOW && currentButtonState == HIGH) {
    pressStart = currentTime;
    Serial.println(pressStart);
    buttonPressed = true;
  }

  // Detect button release (HIGH → LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println(currentTime);
    Serial.println(pressStart);
    pressDuration = currentTime - pressStart;
    buttonPressed = false;

    if (pressDuration > 500) {
      // Long press → GREEN
      setColor(0, 255, 0);
      delay(500);
      clearColor();
    } else {
      // Short press (maybe part of double press)
      pressCount++;
      lastPressTime = currentTime;
    }
  }

  // If one short press and no second press after 250 ms → RED
  if (pressCount == 1 && (currentTime - lastPressTime > 250)) {
    setColor(255, 0, 0);  // Red
    delay(500);
    clearColor();
    pressCount = 0;
  }

  // If two quick short presses → BLUE
  if (pressCount == 2) {
    setColor(0, 0, 255);  // Blue
    delay(500);
    clearColor();
    pressCount = 0;
  }

  lastButtonState = currentButtonState;
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void clearColor() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

