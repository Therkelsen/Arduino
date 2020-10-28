
int potPin = A0;                       // Ints til at indholde værdierne til potentiometeret.
int potVal = 0;

int redPin = 11;                       // Ints til at indholde værdierne til RGB LED'en.
int grnPin = 10;   
int bluPin = 9;   

int redVal = 0;   
int grnVal = 0;   
int bluVal = 0;   

int mode = 0;
  
void setup()
{
  pinMode(redPin, OUTPUT);            // Pins bliver sat til output mode, så de kan få RGB LED'en til at lyse.
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT); 
}

void loop()
{
  potVal = analogRead(potPin);        // Læser værdien på potentiometeret og sætter det ind i en variabel.

  if (potVal < 341)                   // Den første tredjedel af potentiometerets værdier (0-341).
  {                  
    potVal = (potVal * 3) / 4;

    redVal = 255 - potVal;
    grnVal = potVal;
    bluVal = 1;
  }
  else if (potVal < 682)              // Den anden tredjedel af potentiometerets værdier (342-682).
  {
    potVal = ( (potVal-341) * 3) / 4;

    redVal = 1;
    grnVal = 255 - potVal;
    bluVal = potVal;
  }
  else                                // Den anden tredjedel af potentiometerets værdier (682-1023).
  {
    potVal = ( (potVal-683) * 3) / 4;
    
    redVal = potVal;
    grnVal = 1;
    bluVal = 255 - potVal;
  }
  analogWrite(redPin, redVal);
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);  
}
