#include <CheapStepper.h>

int inPin = 7; 
int val = 0; 
int stanButton = 0;

CheapStepper stepper (2,3,4,5); 

void setup() 
{
pinMode(inPin, INPUT_PULLUP);
pinMode(buzzer, OUTPUT);
stepper.setRpm(12);
Serial.begin(9600);
startSound();
}

void loop() 
{
option();
if(stanButton == 0)
{
  Serial.println("1");
  stepper.moveDegreesCW(0);
  delay(100);
}
else if(stanButton == 1)
{
  Serial.println("2");
  stepper.moveDegreesCCW(10);
}
else if(stanButton == 2)
{
  Serial.println("3");
  stepper.moveDegreesCW(10);
}
}

//FUNCTIONS
void option()
{
  val = digitalRead(inPin);  
  if(val == LOW)
{
  selectSound();
  stanButton=(stanButton + 1); 
}
}
