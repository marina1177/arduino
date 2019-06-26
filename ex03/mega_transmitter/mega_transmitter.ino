#include <Wire.h>
#include <LiquidCrystal.h>

int val1;
int val2;
char str1[5];
char str2[5];
float Value_volt = 0;
String inputString = "";         // строка, в которую будут записываться входящие данные
boolean stringComplete = false;  // заполнилась ли строка или нет
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(20, 4);
  // печатаем первую строку
  lcd.print("Voltage:");
  delay(1000);

  Serial.begin(9600);
  Serial3.begin(9600);

  inputString.reserve(20);
}


void loop() {

  if (stringComplete)
  {
    lcd.setCursor(0, 1);
    lcd.print("V1= ");
    /* lcd.setCursor(7, 1);
      lcd.print("v");*/
    lcd.setCursor(3, 1);
    const char* str = inputString.c_str();

    while (*str != '_')
    {
      Serial.print("str1");
      *str1 = *str;;
    }
    *str1 = '\0';

    val1 = atoi(str1);

    Value_volt = (float)5 / 1025 * val1;
    lcd.print(Value_volt);
    delay(300);



    /*  Serial.print("str_");
      Serial.println(str);
      //
      //char k = inBuff[0];
      byte n1 = str[0]-48;
      byte n2 = str[1]-48;
      byte n3 = str[2]-48;


      int NumComm = (n1*100) + (n2*10) + n3;
      // Serial.println(k);
      Serial.println(NumComm);*/

    inputString = "";
    stringComplete = false;
    /* lcd.setCursor(0, 1);
      lcd.print("V1= "); // Устанавливаем курсор на вторую строку и нулевой символ.
      lcd.setCursor(3, 1);
      const char* str = inputString.c_str();
      val = atoi(str);
      Serial.println(val);
      lcd.print(val);
      delay(300);

      inputString = "";
      stringComplete = false;*/
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

/*
  int i = 0;
  while(Serial3.available() && i<5)
  {
   str[i++] = Serial3.read();
  }
  str[i++]='\0';*/


/*Value_volt = (float)5 / 1025 * Value;
  Therm_volt = (float)5 / 1025 * Therm;
  // Serial.println(Value_volt);
  //Serial.println(Therm_volt);*/

/*while(str)
  {
  Serial.print(*str);
  str++;
  }*/



/* while (Serial3.available()) {
  // получаем новый байт:
  char inChar = (char)Serial3.read();

  //  Serial.print("inChar_");
  Serial.println(inChar);
  // добавляем его к inputString:
  inputString += inChar;
  // если получили символ новой строки, оповещаем программу об этом,
  // чтобы она могла принять дальнейшие действия.
  if (inChar == '\0')
  {
   stringComplete = true;
  }*/


/*Serial.println("event");
  char inChar = (char)Serial3.read();
  inputString += inChar;
  Serial.print("i_");
  Serial.println(i);
  Serial.print("write_");
  Serial.write(inChar);
  Serial.println();
  Serial.print("inChar_");
  Serial.println(inChar);
  i++;

  if (i == 5)
  {
    Serial.print("end");
    while(1);
     stringComplete = true;
  }*/
