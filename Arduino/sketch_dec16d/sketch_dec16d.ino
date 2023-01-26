void setup() {
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  int btn1 = digitalRead(2);
  int btn2 = digitalRead(4);
  int btn3 = digitalRead(7);
  Serial.println(btn3);

  if(btn1 == 1){
    digitalWrite(3,HIGH);
  }else{
    digitalWrite(3,LOW);
  }

  if(btn2 == 1){
    digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }

  if(btn3 == 1){
    digitalWrite(6,HIGH);
  }else{
    digitalWrite(6,LOW);
  }
}
