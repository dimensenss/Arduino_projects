#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Підключення датчика температури DS18B20
const int oneWireBus = 9;  // Підключення до порту 9
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// Підключення LCD екрану через PCF8574
LiquidCrystal_I2C lcd(32, 16, 2);

void setup() {
  Serial.begin(9600);
  
  // Ініціалізація датчика температури
  sensors.begin();
  
  // Ініціалізація LCD екрану
 lcd.init();
 lcd.backlight();
}

void loop() {
  // Зчитування температури з датчика
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  // Переведення температури у фаренгейти
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  // Виведення температури на LCD екран
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureF);
  lcd.print(" F");

  delay(1000);  // Затримка 1 секунда між вимірюваннями
}
