// Java의 Scanner처럼 라이브러리 지정
#include <Servo.h>

Servo myServo;

void setup() {
  // Servo Motor를 제어하기 위한 핀 번호
  myServo.attach(8);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int mapValue = map(sensorValue,0,1023,0,180); 

  myServo.write(mapValue);

  Serial.println(mapValue);
  delay(10);

}
