#include <Wire.h>
#include <LiquidCrystal.h>


int PhotoPin = A0; // select the input pin for the potentiometer
int TPin = A1;
int Value = 0;
float Value_volt = 0;
int Therm = 0;
float Therm_volt = 0;

char str[5];
void setup()
{
 // lcd.begin(20, 4);
  // печатаем первую строку
  //lcd.print("Voltage:");
//  delay(1000);
  Serial.begin(9600);
  Serial.print("Start");

}

void loop()
{
  Value = analogRead(PhotoPin);
  Therm = analogRead(TPin);
  
  Value_volt = (float)5 / 1025 * Value;
  Therm_volt = (float)5 / 1025 * Therm;
  // Serial.println(Value_volt);
  itoa(Value_volt, str,10);
 //  Serial.print(Value_volt);
  Serial.write("123");
// Serial.write(Value_volt);
/*
  lcd.setCursor(11, 1);
  lcd.print("V2= ");
  lcd.setCursor(14, 1);
  lcd.print(Therm_volt);*/
 
  
  //Serial.println(Therm_volt);
  //   lcd.print(Value);
 // delay(300);

}
