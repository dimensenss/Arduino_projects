const int LED_YELLOW = 9; // Порт для жовтого світлодіоду
const int LED_RED = 6; // Порт для червоного світлодіоду

void setup() {
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  // Жовтий світлодіод
  digitalWrite(LED_YELLOW, HIGH); // Увімкнути жовтий світлодіод
  delay(1500); // Затримка на 1.5 секунди
  digitalWrite(LED_YELLOW, LOW); // Вимкнути жовтий світлодіод
  delay(500); // Затримка на 0.5 секунди

  // Червоний світлодіод
  digitalWrite(LED_RED, HIGH); // Увімкнути червоний світлодіод
  delay(500); // Затримка на 0.5 секунди
  digitalWrite(LED_RED, LOW); // Вимкнути червоний світлодіод
  delay(800); // Затримка на 0.8 секунди
}