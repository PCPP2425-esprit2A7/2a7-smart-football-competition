#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String inputString = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(inputString);
      inputString = "";
    } else {
      inputString += c;
    }
  }
}
