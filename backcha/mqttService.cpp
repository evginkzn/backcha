#include "mqttService.h"

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

static char ssid_[] = "Keenetic-0165";
static char pass_[] = "JwY5zX29";

static char server_[] = "hairdresser.cloudmqtt.com";
static int serverPort_ = 15466;
static const char login_[] = "nutliarr";
static char passKey_[] = "LQh0PcWu-9_Q";

static WiFiClient wifiClient;

static Adafruit_MQTT_Client mqtt(&wifiClient
	, server_, serverPort_
	, login_, passKey_);

static Adafruit_MQTT_Publish temprPub_ = Adafruit_MQTT_Publish(&mqtt
	, "sensors/temperature");
static Adafruit_MQTT_Publish soilPub_ = Adafruit_MQTT_Publish(&mqtt
	, "sensors/soil_moisture");
static Adafruit_MQTT_Publish brigthPub_ = Adafruit_MQTT_Publish(&mqtt
	, "sensors/brightness");

static Adafruit_MQTT_Publish* publishInstance[MqttService::TopicCount] =
{
	&temprPub_,
	&soilPub_,
	&brigthPub_
};

MqttService::MqttService()
{
}

void MqttService::init()
{
  Serial.print("Connecting to ");
  Serial.println(ssid_);

  WiFi.begin(ssid_, pass_);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
}

void MqttService::run()
{
	int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}

void MqttService::push(Topic topic, const char* value)
{
  if (! publishInstance[topic]->publish(value)) 
  {
    Serial.println(F("Failed"));
  } else 
  {
    Serial.println(F("OK!"));
  }
}
