
int potPin = 2;                       // Ints til at indholde værdierne til potentiometeret.
int potVal = 0;

int redPin = 3;                       // Ints til at indholde værdierne til RGB LED'en.
int grnPin = 5;   
int bluPin = 9;   

int redVal = 0;   
int grnVal = 0;   
int bluVal = 0;   

unsigned long previousMillis = 0;

int interval = 1000;

void setup()
{
  pinMode(redPin, OUTPUT);            // Pins bliver sat til output mode, så de kan få RGB LED'en til at lyse.
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT);

}

// Main program
void loop()
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    ++potVal;
    }
  
  potVal = millis();

  if (potVal < 341)
  {                  
    redVal = 255 - potVal;
    grnVal = potVal;
    bluVal = 1;
  }
  else if (potVal < 682)
  {
    redVal = 1;
    grnVal = 255 - potVal;
    bluVal = potVal;
  }
  else
  {
    redVal = potVal;
    grnVal = 1;
    bluVal = 255 - potVal;
  }
  analogWrite(redPin, redVal);
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);  
}
