
  int btnPin = 0;
  bool checkState = false;

  int potPin = A5;
  int potVal = 0;
  
  int redPin = 11;
  int grnPin = 10;
  int bluPin = 9;

  int redVal = 0;
  int grnVal = 0;
  int bluVal = 0;

  int mode = 0;
  
  void setup() {
    // put your setup code here, to run once:

    Serial.begin(9600);

    pinMode(btnPin, INPUT_PULLUP);
    
    pinMode(redPin, OUTPUT);
    pinMode(grnPin, OUTPUT);
    pinMode(bluPin, OUTPUT);

    mode = 1;
    
  }
  
  void loop() {
    
    if (digitalRead(btnPin) == LOW && checkState == false) {
      mode += 1;
    }

    if (digitalRead(btnPin) == LOW && checkState == false) {
      checkState = true;
    }

    if (digitalRead(btnPin) == HIGH && checkState == true) {
      checkState = false;
    }


    if (mode == 1) {

      Serial.println(mode);
      turnOffRGBLED(redPin, grnPin, bluPin);
  
    } else if (mode == 2) {

      
      Serial.println(mode);
      potControlledFade(redPin, grnPin, bluPin);

      } else if (mode == 3) {

        Serial.println(mode);
        
        } else if (mode == 4) {
          
          Serial.println(mode);
          
          } else if (mode > 4) {
  
            mode = 1;
            Serial.println(mode);
  
            }
    
  }

  void potControlledFade(int redPin, int grnPin, int bluPin) {
    
    // put your main code here, to run repeatedly:
    potVal = analogRead(potPin);
    
    if (potVal < 341) {                 // Den første tredjedel af potentiometerets værdier (0-341).
      potVal = (potVal * 3) / 4;
  
      redVal = 255 - potVal;
      grnVal = potVal;
      bluVal = 1;

    } else if (potVal < 682) {          // Den anden tredjedel af potentiometerets værdier (342-682).
      potVal = ( (potVal-341) * 3) / 4;
  
      redVal = 1;
      grnVal = 255 - potVal;
      bluVal = potVal;
    } else {                            // Den anden tredjedel af potentiometerets værdier (682-1023).
      potVal = ( (potVal-683) * 3) / 4;
      
      redVal = potVal;
      grnVal = 1;
      bluVal = 255 - potVal;
    }
    analogWrite(redPin, redVal);
    analogWrite(grnPin, grnVal);
    analogWrite(bluPin, bluVal);
  }

  void turnOffRGBLED(int redPin, int grnPin, int bluPin) {
      
    redVal = 0;
    grnVal = 0;
    bluVal = 0;

    analogWrite(redPin, redVal);
    analogWrite(grnPin, grnVal);
    analogWrite(bluPin, bluVal);  
      
  }  
