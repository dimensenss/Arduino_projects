const int buttonPins[] = {9, 6};  
const int ledPins[] = {10, 5};    
boolean buttonWasPressed[] = {false, false};
unsigned long lastDebounceTime[] = {0, 0};
unsigned long debounceDelay = 5;
int lastButtonState[] = {LOW, LOW};

boolean ledActive[] = {false, false};

class Flasher {
  int ledPin; 
  long OnTime; 
  long OffTime; 
  int ledState;
  unsigned long previousMillis;
  
  public:
  Flasher(int pin, long on, long off) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    OnTime = on;
    OffTime = off;
    ledState = LOW;
    previousMillis = 0;
  }
  
  void Update() {
    unsigned long currentMillis = millis();
    
    if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
      ledState = LOW;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    } else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) {
      ledState = HIGH;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
  }
};

Flasher led[] = {Flasher(ledPins[0], 500, 1100), Flasher(ledPins[1], 1500, 2100)};

void checkButton(int buttonIndex) {
  int reading = digitalRead(buttonPins[buttonIndex]);

  if (reading != lastButtonState[buttonIndex]) {
    lastDebounceTime[buttonIndex] = millis();
  }

  if ((millis() - lastDebounceTime[buttonIndex]) > debounceDelay) {
    if (reading != buttonWasPressed[buttonIndex]) {
      buttonWasPressed[buttonIndex] = reading;

      if (buttonWasPressed[buttonIndex]) {
        if (!ledActive[buttonIndex]) {
          ledActive[buttonIndex] = true;
          led[buttonIndex].Update();
        } else {
          ledActive[buttonIndex] = false;
          digitalWrite(ledPins[buttonIndex], LOW);
        }
      }
    }
  }

  lastButtonState[buttonIndex] = reading;

  if (ledActive[buttonIndex]) {
    led[buttonIndex].Update();
  }
}

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(buttonPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  checkButton(0);
  checkButton(1);
}
