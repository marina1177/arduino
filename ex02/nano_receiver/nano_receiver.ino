#include <Wire.h>
#include <LiquidCrystal.h>

int PhotoPin = A0;
int TPin = A1;
int photo = 0;
int therm = 0;
String outString = "";

char str[10];

void setup()
{
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  Serial.print("Start");
  outString.reserve(20);
}

void loop()
{
  photo = analogRead(PhotoPin);
  therm = analogRead(TPin);

  outString = String(itoa(photo, str, 10)) + '_' + String(itoa(therm, str, 10)) + '\n';
  const char* str = outString.c_str();
  int i = 0;
  /*while(*str != '\0')
    {
    // Serial.print(str[i]);
     str++;;
    }
    str = '\n';*/
  //Serial.print(str[i]);
  //Serial.print('\n');
  Serial.write(str);
  delay(200);
}

void serialEvent()
{
  int i = 0;
  while (Serial.available())
  {
    digitalWrite(12, HIGH);
  }
}
