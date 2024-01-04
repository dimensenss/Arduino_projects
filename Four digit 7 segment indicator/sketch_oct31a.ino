// C++ code
//
const int DELAY_TIME = 1000;
const int SHORT_DELAY = 40;

int LEDs[] = {1, 2, 3, 4, 5, 6, 7};

// Массивы для каждой буквы
bool G[] = {1, 0, 0, 0, 1, 1, 0};
bool R[] = {1, 1, 0, 0, 1, 1, 1};
bool U[] = {0, 1, 1, 1, 0, 1, 1};
bool one[] = {0, 1, 1, 0, 0, 0, 0};
bool two[] = {1, 1, 0, 1, 1, 0, 1};
bool eight[] = {1, 1, 1, 1, 1, 1, 1};

void setup()
{
  for (int i = 0; i < 7; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
}

void writeLED(bool arr[]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(LEDs[i], arr[i]);
  }
  delay(DELAY_TIME);
  for (int i = 0; i < 7; i++) {
    digitalWrite(LEDs[i], LOW);
  }
  delay(SHORT_DELAY);
}

void loop()
{
  writeLED(G);
  writeLED(R);
  writeLED(U);
  writeLED(one);
  writeLED(two);
  writeLED(eight);
}