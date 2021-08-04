#ifndef SOIL_MOISTURE_SENSOR_HPP
#define SOIL_MOISTURE_SENSOR_HPP

#include <stdint.h>

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class SoilMoistureSensor
{
private:
  enum
  {
    ConversionTime = 1000,
    StringLength = 20
  };
  
public:
	SoilMoistureSensor(){}
	virtual ~SoilMoistureSensor(){}
	
public:
	void init();
	void run();

  float get() const { return lastValue_; }
  char* get_str() { return val_string_; }

private:
  unsigned long conversionTimeCounter_ = 0;
  uint16_t lastValue_ = 0.0f;
  uint16_t max_val_ = 0;
  uint16_t min_val_ = 1023;
  float perc = 0.0f;
  char val_string_[StringLength];
};

#endif // !SOIL_MOISTURE_SENSOR_HPP
