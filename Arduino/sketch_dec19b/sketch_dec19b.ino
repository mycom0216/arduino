int pinRed = 8;
int pinBlue = 9;
int pinGreen = 10;
int button1 = 5;
int button2 = 6;
int button3 = 7;



int pinRed = 7;





void setup() {
  // 연결 모듈들 -> pinMode
  pinMode(8, OUTPUT); // 빨간색
  pinMode(9, OUTPUT); // 파란색
  pinMode(10, OUTPUT); // 초록색
  pinMode(A0, INPUT); // 가변저항 
  pinMode(5, INPUT);  // 버튼1
  pinMode(6, INPUT);  // 버튼2
  pinMode(7, INPUT);  // 버튼3
  Serial.begin(9600); // 9600 : Baud rate
}

int pinNum = 0;

void loop() {
  int btn1 = digitalRead(5);
  int btn2 = digitalRead(6);
  int btn3 = digitalRead(7);

  int sensorValue = analogRead(A0); 
  
  // 0 ~ 1023 해상도 : 10bit

  int mapValue = map(sensorValue, 0, 1023, 0, 255);
  // 0 ~ 255 해상도 : 8bit

  if(btn1 == 1){
    pinNum = 8;
  }else{
    analogWrite(8,0);
  }

  if(btn2 == 1){
    pinNum = 9;
  }else{
    analogWrite(9,0);
  }

  if(btn3 == 1){
    pinNum = 10;
  }else{
    analogWrite(10,0);
  }

  analogWrite(pinNum, mapValue);

  delay(10);


  Serial.println(sensorValue);
  Serial.println(btn1);
  Serial.println(btn2);
  Serial.println(btn3);
  
}
