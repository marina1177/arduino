#include <Wire.h>
#include <LiquidCrystal.h>


// инициализируем объект-экран, передаём использованные
// для подключения контакты на Arduino в порядке:
// RS, E, DB4, DB5, DB6, DB7
int PhotoPin = A0; // select the input pin for the potentiometer
int TPin = A1;
int Value = 0;
float Value_volt = 0;
int Therm = 0;
float Therm_volt = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(20, 4);
  // печатаем первую строку
  lcd.print("Voltage:");
  delay(1000);
  Serial.begin(9600);
  Serial.print("Start");

}

void loop()
{
  Value = analogRead(PhotoPin);
  Therm = analogRead(TPin);
  
  Value_volt = (float)5 / 1025 * Value;
  Therm_volt = (float)5 / 1025 * Therm;

  lcd.setCursor(0, 1);
  lcd.print("V1= "); // Устанавливаем курсор на вторую строку и нулевой символ.
  lcd.setCursor(3, 1);
  lcd.print(Value_volt);// Выводим на экран значение с аналогового входа (от 0 до 1024 пропорционально от 0 В. до 5 В.)

  lcd.setCursor(11, 1);
  lcd.print("V2= ");
  lcd.setCursor(14, 1);
  lcd.print(Therm_volt);
 
  
  //Serial.println(Therm_volt);
  //   lcd.print(Value);
  delay(300);

}
