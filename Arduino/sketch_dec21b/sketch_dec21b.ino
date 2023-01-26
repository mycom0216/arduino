int ledPin1 = 18;
int ledPin2 = 19;
int ledPin3 = 23;

void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  Serial.begin(115200);

}

void loop() {
  if(Serial.available()){
    char c = Serial.read();
    Serial.println(c);

    if(c == '1'){
      digitalWrite(ledPin1,1);
    }else if(c == '2'){
      digitalWrite(ledPin2,1);
    }else if(c == '3'){
      digitalWrite(ledPin3,1);
    }else if(c == '0'){
      digitalWrite(ledPin1,0);
      digitalWrite(ledPin2,0);
      digitalWrite(ledPin3,0);
    }






  }
}

