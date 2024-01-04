#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.display();

}

void task_1(){
  lcd.print("KN-321B");
  lcd.setCursor(0,1);
  lcd.print("Khoma D. M.");
}

void task_2(){
  char arr[] = {'2','.','7','1','8',
                '2','8','1','8','2',
                '8','4','5','9','0',
                '4','5','2','3','5'};
  
  lcd.print("e:");
  for(int i = 0; i<14;i++){
    lcd.print(arr[i]);
  }
  lcd.setCursor(0,1);
  for(int i = 14; i<20;i++){
    lcd.print(arr[i]);
  }
}

void task_3(){
  int num = 18;
  lcd.print("10:");
  lcd.print(num);
  
  lcd.setCursor(6,0);
  lcd.print("2:");
  lcd.print(num, BIN);
  
  lcd.setCursor(0,1);
  lcd.print("16:");
  lcd.print(num, HEX);

}

void task_4(){
  byte customChars[8][8] = 
  {
  {B00100,B01010,B01010,B01010,B01010,B11111,B10001,B10001}, // Д
  {B10001,B11011,B10101,B10001,B10001,B10001,B10001,B10001}, // м
  {B10001,B10011,B10011,B10101,B10101,B11001,B11001,B10001}, // и
  {B11111,B00100,B00100,B00100,B00100,B00100,B00100,B00100}, // т
  {B11110,B10001,B10001,B10001,B11110,B10000,B10000,B10000}, // р
  {B01110,B10001,B10001,B10001,B10001,B10001,B10001,B01110}, // о
};
  for (int i = 0; i < 6; i++) {
    lcd.createChar(i, customChars[i]);
  }

  lcd.setCursor(0, 0);
  for(int i =0; i<6; i++){
    lcd.write(byte(i));
  }
}

void (*tasks[])() = {task_1, task_2, task_3, task_4};

void loop(){
  for (int i =0; i<4; i++){
  	tasks[i]();
    delay(2000);
  	lcd.clear();
  }
}