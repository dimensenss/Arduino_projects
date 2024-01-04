int LEDs[] = {1, 2, 3, 4, 5, 6, 7};
int INDs[] = {8, 9, 10, 11};

bool A[] = {1, 1, 1, 0, 1, 1, 1};
bool B[] = {1, 1, 1, 1, 1, 1, 1};
bool F[] = {1, 0, 0, 0, 1, 1, 1};
bool six[] = {1, 0, 1, 1, 1, 1, 1};

bool *arr[] = {A, B, F, six};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(INDs[i], OUTPUT);
  }
}

void writeLED(bool *arr[]) {
  for (int ind = 0; ind < 4; ind++) {
    digitalWrite(INDs[ind], LOW);

    for (int i = 0; i < 7; i++) {
      digitalWrite(LEDs[i], arr[ind][i]);
    }
    delay(100);
    for (int i = 0; i < 7; i++) {
      digitalWrite(LEDs[i], LOW);
    }
    
    digitalWrite(INDs[ind], HIGH);
    delay(15);
    
  }
}

void loop() {
  writeLED(arr);
}