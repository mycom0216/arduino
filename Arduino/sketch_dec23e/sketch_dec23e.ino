#include <WiFi.h>
#include <HTTPClient.h>

#include <ArduinoJson.h>

const char* ssid = "Galaxy A13 8675"; // WIFI ID
const char* password = "09301031"; // WIFI PW

// Server 요청 주소
String address = "https://kobis.or.kr/kobisopenapi/webservice/rest/boxoffice/searchDailyBoxOfficeList.json?key=f5eef3421c602c6cb7ea224104795888&targetDt=20221222";

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
      JsonObject& boxOfficeResult = root["boxOfficeResult"];
      JsonArray& movies = boxOfficeResult["dailyBoxOfficeList"];

      for(int i = 0; i < 10; i++){
        JsonObject& movie = movies[i];
        String movieNm = movie["movieNm"];
        Serial.print(i + 1);
        Serial.print("위 : ");
        Serial.println(movieNm);
      }








    }


    http.end(); //Free the resources
  } else {
    Serial.println("Error on HTTP request");
  }
  delay(500);
}
