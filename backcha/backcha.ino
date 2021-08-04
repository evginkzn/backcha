#include "temperatureSensor.h"
#include "brightnessSensor.h"
#include "soilMoistureSensor.h"
#include "mqttService.h"

TemperatureSensor t = TemperatureSensor();
BrightnessSensor b = BrightnessSensor();
SoilMoistureSensor s = SoilMoistureSensor();

MqttService mqttService;

static unsigned long temp_show_period_cnt = 0;
static unsigned long bright_show_period_cnt = 0;
static unsigned long soil_show_period_cnt = 0;

static void sensors_pseudo_thread(void);

void setup()
{
  Serial.begin(115200);
  t.init();
  b.init();
  s.init();
  mqttService.init();
}

void loop() 
{
  sensors_pseudo_thread();
  mqttService.run();
  if ((millis() - temp_show_period_cnt) >= 2000)
  {
    temp_show_period_cnt = millis();

    Serial.print("Temperature: ");
    Serial.print(t.get_str());
    mqttService.push(MqttService::TopicTemperature, t.get_str());
    Serial.print(" oC");
    Serial.println("");
  }

  if ((millis() - bright_show_period_cnt) >= 2000)
  {
    bright_show_period_cnt = millis();

    Serial.print("Brightness: ");
    Serial.print(b.get_str());
    mqttService.push(MqttService::TopicBrightness, b.get_str());
    Serial.print(" Lux");
    Serial.println("");
  }

  if ((millis() - soil_show_period_cnt) >= 2000)
  {
    soil_show_period_cnt = millis();

    Serial.print("Soil Moisture Level: ");
    Serial.print(s.get_str());
    mqttService.push(MqttService::TopicSoilMoisture, s.get_str());
    Serial.print(" \%");
    Serial.println("");
  }
}

void sensors_pseudo_thread(void)
{
  t.run();
  b.run();
  s.run();
}
