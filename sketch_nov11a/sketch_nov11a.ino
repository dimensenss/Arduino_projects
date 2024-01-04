#include <Servo.h>
Servo myServo;
int potPin=A0;
int result=0;
int rotate=0;
void setup()
{
  pinMode(potPin,INPUT);
  myServo.attach(5);
}

void loop()
{
  myServo.write(rotate);
  result=analogRead(potPin);
  result=map(result,0,1023,0,180);

  if (result!=rotate)
  {
  	myServo.write(result-rotate);
    rotate=result;
  }
}