const int SWITCH_PIN = 4;
const int LED1_PIN = 2;
const int LED2_PIN = 3;
const int MOTOR_PIN=9;
int val=0;

void setup() 
{ 
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(SWITCH_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}
void loop() 
{ 
  if (digitalRead(SWITCH_PIN)){
    
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED1_PIN, HIGH);
    
    val = analogRead(A0);
    val = map(val,1024,0,0,255);
    analogWrite(MOTOR_PIN, val);
    delay(5);
  }
  else{
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    analogWrite(MOTOR_PIN, LOW);
    delay(5);
  }
}
