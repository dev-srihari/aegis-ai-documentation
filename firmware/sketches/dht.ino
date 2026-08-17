#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "READ_DHT") {

      float t = dht.readTemperature();
      float h = dht.readHumidity();

      if (isnan(t) || isnan(h)) {

        Serial.println("ERROR");

      } else {

        Serial.print("{\"temperature\":");
        Serial.print(t);
        Serial.print(",\"humidity\":");
        Serial.print(h);
        Serial.println("}");

      }

    }

  }

}