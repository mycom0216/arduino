void setup() {
  pinMode(10, OUTPUT);

}

void loop() {
 
 analogWrite(10,100);
 delay(500);
 analogWrite(10,255);
 delay(500);
 analogWrite(10,0);
 delay(500);

 
}
