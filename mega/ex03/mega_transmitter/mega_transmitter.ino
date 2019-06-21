#include <Wire.h>
#include <LiquidCrystal.h>

char str[5];
double val[2];
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(20, 4);
  // печатаем первую строку
  lcd.print("Voltage:");
  delay(1000);
 
  Serial.begin(9600);
  Serial3.begin(9600);

}



void atoi(char* chars, double* value, int count) {

  int i=0, l=0;
  float multiplier;
  float front =0.0, behind =0.0;
  
  //value = 0.0;
  
  // перед точкой
  
  while(chars[i]!='.' && i<count) {
  
  i++;
  
  if (chars[i]=='.') {
  
  int q=i;
  
  for(int j=i; j>0; j--) {
  
  multiplier=1;
  
  for(int k=q; k>1; k--) {
  
  multiplier *= 10;
  
  }
  
  front+=(chars[l]-'0')*multiplier;
  
  l++;
  
  q--;
  
  }
  
  l++;
  
  }

}

int n=i;

// после точки

  while(chars[n]!='\0' && i<count) {
  
  n++;
  
  if (chars[n]=='\0') {
  
  int q=n, l=n-1;
  
  for(int j=n-1; j>i; j--) {
  
  multiplier=1;
  
  for(int k=q-(i+2); k>=0; k--) {
  
  multiplier = 0.1*multiplier;
  
  }
  
  behind+=(chars[l]-'0')*multiplier;
  
  l--;
  
  q--;
  
  }
  
  }

}

value[0]=front;

value[1]=behind;

}


void loop() {

  int i=0;
  if (Serial3.available()) 
  {
      //delay(100);
      while(Serial3.available() && i<5) 
      {
        str[i++] = Serial3.read();
      }
      str[i++]='\0';

   }
  Serial.println(str);
  lcd.setCursor(0, 1);
  lcd.print("V1= "); // Устанавливаем курсор на вторую строку и нулевой символ.
  lcd.setCursor(3, 1);


  atoi(str,val,4);
  lcd.write(str);
  //lcd.print(Value_volt);
                  
  /*lcd.print('.');
  lcd.print(val[1]);*/
  
    delay(300);
    

}
