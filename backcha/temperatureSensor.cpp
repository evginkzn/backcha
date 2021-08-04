#include "temperatureSensor.h"

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_PIN D5

static OneWire oneWireBus_(ONE_WIRE_BUS_PIN);
static DallasTemperature ds18b20_(&oneWireBus_);

TemperatureSensor::TemperatureSensor()
{
}

void TemperatureSensor::init()
{
	ds18b20_.begin();

  //TODO: add checking sensor on the bus!
  //..
  //

  //Serial.println("Temperature sensor initialization done");
}

void TemperatureSensor::run()
{
  if ((millis() - conversionTimeCounter_) >= ConversionTime)
  {
    conversionTimeCounter_ = millis();
    
    ds18b20_.requestTemperatures();
    lastValue_ = ds18b20_.getTempCByIndex(0);
    dtostrf(lastValue_, 2, 1, temperatureString_);
  }
}
