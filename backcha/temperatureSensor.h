#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class TemperatureSensor
{
private:
  enum
  {
    ConversionTime = 1000,
    StringLength = 20
  };
  
public:
  typedef void(*dataReadyHandler)(float);

public:
	TemperatureSensor();
	virtual ~TemperatureSensor(){}
	
public:
	void init();
  void run();

  float get() const { return lastValue_; }
  char* get_str() { return temperatureString_; }

private:
  unsigned long conversionTimeCounter_ = 0;
  float lastValue_ = 0.0f;
  char temperatureString_[StringLength];
  dataReadyHandler handler_ = 0;
};

#endif // !TEMPERATURE_SENSOR_HPP
