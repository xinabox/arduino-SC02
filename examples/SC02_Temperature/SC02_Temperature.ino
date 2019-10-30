/*
  DS3231: Real-Time Clock. Temperature example
  Read more: www.jarzebski.pl/arduino/komponenty/zegar-czasu-rzeczywistego-rtc-ds3231.html
  GIT: https://github.com/jarzebski/Arduino-DS3231
  Web: http://www.jarzebski.pl
  (c) 2014 by Korneliusz Jarzebski
*/

#include <Wire.h>
#include <xSC02.h>

xSC02 SC02;
RTCDateTime dt;

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  SC02.begin();
}

void loop()
{
  // The temperature registers are updated after every 64-second conversion.
  // If you want force temperature conversion use forceConversion()
  SC02.forceConversion();

  Serial.print("Temperature: ");
  Serial.println(SC02.readTemperature());

  delay(1000);
}
