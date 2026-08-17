#include <DHT.h>

#define GAS_PIN 2
#define PIR_PIN 3
#define DHT_PIN 4

#define HALL_LIGHT 5
#define KITCHEN_LIGHT 6
#define BEDROOM_LIGHT 7

#define BUZZER 8

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  pinMode(GAS_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  pinMode(HALL_LIGHT, OUTPUT);
  pinMode(KITCHEN_LIGHT, OUTPUT);
  pinMode(BEDROOM_LIGHT, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  dht.begin();

  Serial.println("AEGIS AI STARTED");
}

void loop()
{

  bool gas = digitalRead(GAS_PIN);
  bool motion = digitalRead(PIR_PIN);

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Turn everything OFF first

  digitalWrite(HALL_LIGHT, LOW);
  digitalWrite(KITCHEN_LIGHT, LOW);
  digitalWrite(BEDROOM_LIGHT, LOW);

  digitalWrite(BUZZER, LOW);

  // SAFE

  if(!gas && !motion)
  {
      Serial.println("SAFE");
  }

  // PERSON INSIDE

  else if(motion && !gas)
  {
      Serial.println("HOUSE OCCUPIED");

      digitalWrite(HALL_LIGHT, HIGH);
      digitalWrite(BEDROOM_LIGHT, HIGH);
  }

  // GAS LEAK

  else if(gas && !motion)
  {
      Serial.println("WARNING : GAS DETECTED");

      digitalWrite(KITCHEN_LIGHT, HIGH);
      digitalWrite(BUZZER, HIGH);
  }

  // EMERGENCY

  else
  {
      Serial.println("EMERGENCY");

      digitalWrite(HALL_LIGHT, HIGH);
      digitalWrite(KITCHEN_LIGHT, HIGH);
      digitalWrite(BEDROOM_LIGHT, HIGH);

      digitalWrite(BUZZER, HIGH);
  }

  Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Humidity : ");
  Serial.print(hum);
  Serial.println(" %");

  delay(1000);
}