#include <Wire.h>
#include <LiquidCrystal.h>
//   #include <SoftwareSerial.h>

int val1;
int val2;
char str1[5];
char str2[5];
float Value_volt = 0;
float Therm_volt = 0;
String inputString = "";
boolean stringComplete = false;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(20, 4);
  // печатаем первую строку
  lcd.print("Voltage:");
  delay(1000);

  Serial.begin(9600);
  Serial3.begin(9600);
//  outSerial3.begin(9600);
 
  inputString.reserve(20);
}


void loop() {

  if (stringComplete)
  {
    lcd.setCursor(0, 1);
    lcd.print("V1= ");
    lcd.setCursor(7, 1);
    lcd.print("v");
    lcd.setCursor(3, 1);
    const char* str = inputString.c_str();
    int i = 0;
    while (str[i] != '_')
    {
      str1[i] = str[i];
      i++;
    }
    str1[i] = '\0';
    val1 = atoi(str1);

    Value_volt = (float)5 / 1025 * val1;
    lcd.print(Value_volt);
    lcd.setCursor(10, 1);
    lcd.print("V2= ");
    lcd.setCursor(17, 1);
    lcd.print("v");
    lcd.setCursor(13, 1);
    
    int j = i+1;
    i++;
    while (str[i] != '\n')
    {
      str2[i - j] = str[i];
      i++;
    }
    str2[i-j] = '\0';
    val2 = atoi(str2);

    Therm_volt = (float)5 / 1025 * val2;
    lcd.print(Therm_volt);

    /* if(val1 > 0.50)
    {
        Serial3.write(1);
    }*/
    delay(300);
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent3()
{
  int i = 0;
  while (Serial3.available())
  {
    Serial.println("event");
    char inChar = (char)Serial3.read();
    inputString += inChar;
    if (inChar == '\n')
    {
      Serial.println("end");
      inChar = (char)Serial3.read();
      stringComplete = true;
    }
  }
}

/*while(str)
  {
  Serial.print(*str);
  str++;
  }*/
