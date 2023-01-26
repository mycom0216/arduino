#include <WiFi.h>
#include <HTTPClient.h>

#include <ArduinoJson.h>

const char* ssid = "AndroidHotspot9760"; // WIFI ID
const char* password = "09301031"; // WIFI PW

// Server 요청 주소
String address = "https://api.openweathermap.org/data/2.5/weather?q=Germany&appid=1caa58292efe74a7db9e43c83cecbad5";

String result = ""; // 응답 결과 저장
HTTPClient http; // 통신 객체

void setup() {
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
      // Serial.println(result); // 응답 결과 출력

      DynamicJsonBuffer jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(result);
      /*
      기온 main -> temp
      체감온도 main -> feels_like
      날씨 상태 weather -> main
      풍속 wind -> speed
      */

      JsonArray& weathers = root["weather"];
      JsonObject& weather = weathers[0];
      String weather_main = weather["main"];


      Serial.print("날씨 상태 : ");
      Serial.println(weather_main);










      JsonObject& main = root["main"];
      JsonObject& wind = root["wind"];
      float speed = wind["speed"];
      Serial.print("풍속 : ");
      Serial.print(speed);
      Serial.println("m/s");


      float temp = main["temp"];
      float feels_like = main["feels_like"];
      Serial.print("기온 : ");
      Serial.print(temp);
      Serial.println("도");
      Serial.print("체감 온도 : ");
      Serial.print(feels_like);
      Serial.println("도");

    }


    http.end(); //Free the resources
  } else {
    Serial.println("Error on HTTP request");
  }
  delay(500);
}