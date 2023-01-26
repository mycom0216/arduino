#define TRIG 2
#define ECHO 3

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

}

void loop() {
  // 1. TRIG를 통해 초음파를 출력
  digitalWrite(TRIG, HIGH);
  // 2. 엄청 짧은 시간 이후에 초음파 출력을 멈춤
  delay(10);
  digitalWrite(TRIG, LOW);
  // 3. ECHO가 LOW -> HIGH가 되는 시간을 측정
  int duration = pulseIn(ECHO, HIGH);
  // -> duraion에 저장!!
  // 4. 시간-거리-속력 공식을 통해 거리 계산!!
  int distance = duration / 29.1 / 2;

  if(distance >= 5 && distance <= 500){
    Serial.print(distance);
    Serial.println("cm");

    if(distance <= 20){
      tone(8,330,200);
    }

    delay(300);
  }
}
