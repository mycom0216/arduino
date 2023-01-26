void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(2);
  Serial.println(buttonState);

    if(buttonState == 1) {
      digitalWrite(13,1);
    }else if(buttonState == 0){
      digitalWrite(13,0);
    }
}
