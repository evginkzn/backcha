#include "soilMoistureSensor.h"

void SoilMoistureSensor::init()
{
  
}

void SoilMoistureSensor::run()
{
  if ((millis() - conversionTimeCounter_) >= ConversionTime)
  {
    conversionTimeCounter_ = millis();
    
    lastValue_ = analogRead(A0);

    if (lastValue_ < min_val_)
    {
      min_val_ = lastValue_;
    }

    if (lastValue_ > max_val_)
    {
      max_val_ = lastValue_;
    }

    Serial.print(min_val_);
    Serial.println("");
    Serial.print(max_val_);
    Serial.println("");
    Serial.print(lastValue_);
    Serial.println("");

    float level = ((float)lastValue_ - (float)min_val_)/((float)max_val_ - (float)min_val_);
    perc = 100 - (level*100);
    dtostrf(perc, 2, 1, val_string_);
    //sprintf(val_string_, "%.1f", level);
  }
}
