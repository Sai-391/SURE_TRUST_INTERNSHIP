void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() == 1) {
    char a = Serial.read();

    if (a == 'R') {
      digitalWrite(2, HIGH);
      delay(1000);
    }
    else if (a == 'B') {
      digitalWrite(7, HIGH);
      delay(1000);
    }
    else if (a == 'G') {
      digitalWrite(4, HIGH);
      delay(1000);
    }
    else if (a == 'O') {
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
    }
 
  }
}

