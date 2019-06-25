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
  str[4] = '\0';
  Serial.begin(9600);
  Serial.print("Start");
}

void loop()
{
  Value = analogRead(PhotoPin);
  Therm = analogRead(TPin);
  
  itoa(Value, str,10);
 // Serial.println(Value);
 // Serial.println(str);
 //Serial.print(*(str+1));
/*int i;
 while(str[i] != '\0')
 {
  Serial.print(str);
  str++;
 }*/
 //Serial.print('\n');
 Serial.write(str);

 
  
  //Serial.println(Therm_volt);
  //   lcd.print(Value);
 // delay(300);

}
