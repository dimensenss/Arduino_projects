#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

Servo myservo;

LiquidCrystal_I2C lcd(32, 16, 2);

const byte rows = 4;
const byte cols = 4;
char key[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[rows] = {1, 2, 3, 4};
byte colPins[cols] = {5, 6, 7, 8};
Keypad keypad = Keypad(makeKeymap(key), rowPins, colPins, rows, cols);

const char *password = "9999";
char enteredPassword[5]; 
int passwordIndex = 0;
int redled = 10;
int greenled = 12;
int buzz = 11; // Пин для пьезоэлемента

void setup() {
  lcd.init();
  lcd.backlight();
  displayScreen();
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(buzz, OUTPUT); // Установка пина пьезоэлемента как выхода
  myservo.attach(9);
  digitalWrite(redled, HIGH);
}

void loop() {
  
  char key = keypad.getKey();
  if (key != NO_KEY) {
    
    handleKeyPress(key);
    tone(buzz, 1000, 100); // Звук при нажатии на клавиши
    delay(100); // Задержка между звуками, чтобы избежать множественных звуков за короткое время
  }
}

void handleKeyPress(char key) {
  lcd.setCursor(7 + passwordIndex, 1);
  lcd.print("*");
  delay(100);
  enteredPassword[passwordIndex] = key;
  passwordIndex++;

  if (passwordIndex == 4) {
    passwordIndex = 0;
    if (strcmp(enteredPassword, password) == 0) {
      unlockDoor();
    } else {
      incorrect();
    }
  }
}

void unlockDoor() {
  lcd.clear();
  lcd.print("SUCCESS,");
  lcd.setCursor(0, 1);
  lcd.print("DOOR IS OPEN");
  digitalWrite(redled, LOW);
  digitalWrite(greenled, HIGH);
  unlockBuzz();
  
  myservo.write(0);
  
  delay(2000);
  counterBeep();
  digitalWrite(greenled, LOW);
  digitalWrite(redled, HIGH);
  myservo.write(90);
  
  displayScreen();
}

void incorrect() {
  lcd.clear();
  lcd.print("ACCESS DENIED!");
  lcd.setCursor(0, 1);
  lcd.print("CODE INCORRECT");

  
  buzzAlert();
  delay(3000);
  
  displayScreen();
}

void unlockBuzz() {
  
  for (int i =0; i<6; i++){
    tone(buzz, 200*i, 200);
    delay(200);
  }
  
  
}

void counterBeep() {
  lcd.clear();
  lcd.print("DOOR CLOSES IN..");
  for (int i = 5; i > 0; i--) {
    lcd.setCursor(4, 1);
    lcd.print(i);
    lcd.setCursor(6, 1);
    lcd.print("seconds");
    delay(1000);
  }
}

void buzzAlert() {
  tone(buzz, 100, 500); // Звуковой сигнал при ошибке ввода пароля
}

void displayScreen() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("ENTER CODE:");
  
}
