#include <ArduinoJson.h>
String result = "{\"weather\":\"snow\"}"; // key : weather, value : snow

void setup() {
  Serial.begin(115200);
}

void loop() {
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(result);
  String weather = root["weather"];
  Serial.println(weather);
  delay(1000);
}
