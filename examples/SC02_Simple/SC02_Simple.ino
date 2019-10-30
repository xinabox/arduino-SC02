#include <Wire.h>
#include <xSC02.h>

xSC02 SC02;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  SC02.begin();

  // Set sketch compiling time
  SC02.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  dt = SC02.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);
}
