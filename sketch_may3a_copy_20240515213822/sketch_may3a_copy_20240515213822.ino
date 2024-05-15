FINAL WORKING ARDUINO IDE CODE
const int analogInPin = A0;
int sensorValue = 0;
const int buzzerPin = 7;  // Buzzer connected to pin 6

void setup() {
  pinMode(2,OUTPUT); //green
  pinMode(3,OUTPUT); //blue
  pinMode(4,OUTPUT);  // Red LED
  pinMode(buzzerPin,OUTPUT);  // Buzzer
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(2);

  if((sensorValue>=100)&&(sensorValue<=500)){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    delay(100);
  }
  else if((sensorValue>=525)&&(sensorValue<=620)){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    delay(100);
  } 
  else if((sensorValue>=621)){  // Sensor value to activate red LED and buzzer
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);  // Red LED on
    digitalWrite(buzzerPin,HIGH);
    // tone(buzzerPin, 1000); // Buzzer on at 1000Hz
    delay(500);            // Adjust duration as needed
    digitalWrite(buzzerPin,LOW);
    // noTone(buzzerPin);      // Buzzer off
  }
  else{
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    delay(100);
  }
}


