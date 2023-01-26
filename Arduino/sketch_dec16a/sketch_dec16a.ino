void setup() {
  pinMode(13,INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i<=255; i++){
    analogWrite(11,i);
    delay(10);
  }
for(int i = 255; i>=0; i--){
  analogWrite(11,i);
  delay(10);
}
}

