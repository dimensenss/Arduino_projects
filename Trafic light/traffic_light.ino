const int carRedPin = 13;
const int carYellowPin = 12;
const int carGreenPin = 11;
const int pedestrianRedPin = 9;
const int pedestrianGreenPin = 10;

enum TrafficLightState {
  CAR_RED,
  CAR_YELLOW,
  CAR_GREEN,
};

TrafficLightState currentState = CAR_RED;

unsigned int previousMillis = 0;
const int carRedDuration = 3000;
const int carYellowDuration = 600;
const int carGreenDuration = 3000;

void setTrafficLights(bool carRed,
                      bool carYellow,
                      bool carGreen,
                      bool pedestrianRed,
                      bool pedestrianGreen) {
  digitalWrite(carRedPin, carRed);
  digitalWrite(carYellowPin, carYellow);
  digitalWrite(carGreenPin, carGreen);
  digitalWrite(pedestrianRedPin, pedestrianRed);
  digitalWrite(pedestrianGreenPin, pedestrianGreen);
}

void setup() {
  pinMode(carRedPin, OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carGreenPin, OUTPUT);
  pinMode(pedestrianRedPin, OUTPUT);
  pinMode(pedestrianGreenPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    case CAR_RED:
      setTrafficLights(true, false, false, false, true);

      if (currentMillis - previousMillis >= carRedDuration) {
        currentState = CAR_YELLOW;
        previousMillis = currentMillis;
      }

      if (currentMillis - previousMillis >= carRedDuration - 1500) {
        setTrafficLights(true, false, false, false, (currentMillis / 300) % 2);
      }
      break;

    case CAR_YELLOW:
      setTrafficLights(false, true, false, true, false);

      if (currentMillis - previousMillis >= carYellowDuration) {
        currentState = CAR_GREEN;
        previousMillis = currentMillis;
      }
      break;

    case CAR_GREEN:
      setTrafficLights(false, false, true, true, false);

      if (currentMillis - previousMillis >= carGreenDuration) {
        currentState = CAR_RED;
        previousMillis = currentMillis;
      }

      if (currentMillis - previousMillis >= carGreenDuration - 1500) {
        setTrafficLights(false, false, (currentMillis / 300) % 2, true, false);
      }
      break;
  }
}
