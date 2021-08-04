#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_PIN D1

static OneWire oneWire(ONE_WIRE_BUS_PIN);
static DallasTemperature DS18B20(&oneWire);

static char temperatureString[7];

static void getTemperature();

void setup() {
  DS18B20.begin();
  Serial.begin(115200);

  Serial.println("Initialization done");
}

void loop() {
  Serial.print("Temperature: ");
  getTemperature();
  Serial.print(temperatureString);
  Serial.print(" oC");
  Serial.println("");
}

void getTemperature() 
{
  float tempC;
  do {
    DS18B20.requestTemperatures();
    tempC = DS18B20.getTempCByIndex(0);
    dtostrf(tempC, 2, 1, temperatureString);
    delay(100);
  } while (tempC == 85.0 || tempC == (-127.0));
}
