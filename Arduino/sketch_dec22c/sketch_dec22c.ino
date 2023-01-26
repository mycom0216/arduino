#include <ArduinoJson.h>

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "AndroidHotspot9760"; // WIFI ID
const char* password = "09301031"; // WIFI PW

int ledPin = 18;

// Server 요청 주소
String address = "http://nayeho.ngrok.io/welcome?name=nayeho";

String result = ""; // 응답 결과 저장
HTTPClient http; // 통신 객체

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200); // Baud rate

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
}

void loop() {
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

    http.begin(address);

    int httpCode = http.GET(); // 응답코드
    if (httpCode > 0) {

      Serial.println(httpCode); // 응답코드 출력
      result = http.getString(); // 응답 결과 저장
      Serial.println(result); // 응답 결과 출력

      // result : {"led":"1"}
      // 우리는 1이라는 결과를 받아오자!!
      // 문자열 -> json 형식으로 바꾸기 위한 메모리 공간이 필요하다!!
      // 공간은 정적으로 만들거나 동적으로 만들 수 있다
      DynamicJsonBuffer jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(result);
      String led = root["led"];
      Serial.print("led : ");
      Serial.println(led);

      if(led == "1"){
        digitalWrite(ledPin,1);
      }else if(led == "0"){
        digitalWrite(ledPin,0);
      }

      // 18번과 연결된 led를 켜주세요


    }


    http.end(); //Free the resources
  } else {
    Serial.println("Error on HTTP request");
  }
  delay(500);
}