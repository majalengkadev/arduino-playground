/*
 * By Billal Fauzan
 */

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

String teks1 = "    Billal Fauzan";
String teks2 = "Arduino running text";

void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{
  int i;  
  lcd.setCursor(0, 0);
  lcd.print(teks1);
  for (i = 0 ; i < 16; i++)
  {
    lcd.scrollDisplayLeft(); 
    delay(600);
  }
  
  int a;  
  lcd.setCursor(0, 1);
  lcd.print(teks2);
  for (a = 0 ; a < 16; a++)
  {
    lcd.scrollDisplayRight(); 
    delay(600);
  } 
}
