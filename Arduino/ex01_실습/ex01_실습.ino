
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(10,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(10);

  if(sensorValue<500){
    digitalWrite(10,1);
  }else{
    digitalWrite(10,0);
  }
}
