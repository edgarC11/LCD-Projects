#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define sensor A0

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int Vin;
float temp;
float tempF;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
}

void loop()
{
  Vin = analogRead(sensor);
  temp = (500 * Vin) / 1023;
  tempF = (1.8 * temp) + 32;
  if(tempF >= 50)
  {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
    delay(200);
    digitalWrite(10,LOW);
    delay(200);
  }
  else
  {
    digitalWrite(11, HIGH);
  }
  lcd.setCursor(0,1);
  lcd.print(tempF);
  lcd.print(" F");
  delay(1000);
}