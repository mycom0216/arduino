#include <ArduinoJson.h>
String result = "{\"contry\":[{\"weather\":\"snow\", \"temp\":-5}, {\"weather\":\"cloud\", \"temp\":10}]}";  // key : weather, value : snow

void setup() {
  Serial.begin(115200);
}

void loop() {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(result);
  JsonArray& contry = root["contry"];

  JsonObject& gwangju = contry[0];
  JsonObject& london = contry[1];

  String weather = gwangju["weather"];
  int temp = gwangju["temp"];
  Serial.print("날씨 : ");
  Serial.print(weather);
  Serial.print("  기온 : ");
  Serial.print(temp);
  Serial.println("도");

  String weather2 = london["weather"];
  int temp2 = london["temp"];
  Serial.print("날씨 : ");
  Serial.print(weather2);
  Serial.print("  기온 : ");
  Serial.print(temp2);
  Serial.println("도");
  delay(1000);
}