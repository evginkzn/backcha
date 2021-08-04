#ifndef BRIGHTNESS_SENSOR_HPP
#define BRIGHTNESS_SENSOR_HPP

#include <stdint.h>
#include <stdio.h>

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class BrightnessSensor
{
private:
  enum
  {
    ConversionTime = 1000,
    StringLength = 20
  };
  
public:
	BrightnessSensor(){}
	virtual ~BrightnessSensor(){}
	
public:
	void init();
	void run();
	
	uint16_t get() const { return last_val_; }
	char* get_str() { return val_string_; }
	
private:
	void display_details();
	void configure();
	
private:
	uint16_t last_val_ = 0;
	char val_string_[StringLength];
	unsigned long conversionTimeCounter_ = 0;
};

#endif // !BRIGHTNESS_SENSOR_HPP
