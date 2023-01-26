//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int ledPin = 18;

void setup() {
  pinMode(ledPin,OUTPUT);

  Serial.begin(115200);
  SerialBT.begin("ESP32USER"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    // 시리얼 모니터 -> 핸드폰
    char c = Serial.read();
    SerialBT.write(c);
  }
  if (SerialBT.available()) {
    // 핸드폰 -> 시리얼 모니터
    char c = SerialBT.read();

    if(c == '1'){
      digitalWrite(ledPin,1);
    }else if(c == '0'){
      digitalWrite(ledPin,0);
    }

    Serial.write(c);
  }
  delay(20);
}