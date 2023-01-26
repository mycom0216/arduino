int ch = 2; // 채널 0 ~ 15까지 사용 가능
int freq = 5000; // PWM의 진동수
int res = 10;
int ledPin1 = 18;
int ledPin2 = 19;
int ledPin3 = 23;

void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  ledcSetup(ch, freq, res);
  ledcAttachPin(ledPin1, ch);
  ledcAttachPin(ledPin2, ch);
  ledcAttachPin(ledPin3, ch);
}

void loop() {
  for(int i = 0; i < 1024; i = i + 10){
    ledcWrite(ch,i);
    delay(10);
  }


  ledcWrite(ch,0);
  delay(200);
  ledcWrite(ch,512);
  delay(200);
  ledcWrite(ch,1023);
  delay(200);
}
