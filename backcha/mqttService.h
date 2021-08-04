#ifndef MQTT_SERVICE_HPP
#define MQTT_SERVICE_HPP

class MqttService
{
public:
	enum Topic
	{
		TopicTemperature = 0,
		TopicSoilMoisture,
		TopicBrightness,
		
		TopicCount
	};

public:
	MqttService();
	virtual ~MqttService(){}
	
public:
	void init();
	void run();
	void push(Topic topic, const char* value);
};

#endif //! MQTT_SERVICE_HPP