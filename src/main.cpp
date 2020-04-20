#include <M5StickC.h>
#include <Arduino.h>

int tsc = 200;
const int button = 37;
int last_value = 0;
int cur_value = 0;

void setup()
{

  pinMode(button, INPUT);

  M5.begin();
  // Lcd display
  M5.Lcd.fillScreen(WHITE);
  delay(500);

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(6);

  // put your setup code here, to run once:
}

void loop()
{
  cur_value = digitalRead(button);

  if (cur_value != last_value)
  {
    if (cur_value == 0)
    {
      tsc = 200;
    }
  }
  last_value = cur_value;
  // if (tsc % 10 == 0)
  // {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setRotation(1);

    M5.Lcd.setCursor(45, 22);
    M5.Lcd.printf("%02d", tsc / 10);
  // }
  tsc--;
  if (tsc == 0)
  {
    tsc = 200;
  }
  delay(100);
  // put your main code here, to run repeatedly:
}