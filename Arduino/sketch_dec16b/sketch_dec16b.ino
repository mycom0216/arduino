void setup() {
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  
}

int cnt=0;
bool check = true;
void loop() {
  int btnState = digitalRead(2);
  Serial.println(btnState);
  if(btnState == 1){
    if(check == true){
      cnt++;
      check = false;
      if(cnt == 1){
        analogWrite(11, 100);
      }else if(cnt == 2){
        analogWrite(11, 255);
      }else if(cnt == 3){
        analogWrite(11, 0);
        cnt = 0;
      }
    }
  }else if(btnState == 0){
    check = true;
  }
}