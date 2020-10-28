  
  int ledPin1 = 2;
  int ledPin2 = 3;
  int ledPin3 = 4;
  int ledPin4 = 5;
  int ledPin5 = 6;
  int ledPin6 = 7;
  int ledState1 = LOW;
  int ledState2 = LOW;
  int ledState3 = LOW;
  int ledState4 = LOW;
  int ledState5 = LOW;
  int ledState6 = LOW;
  
  int btnPin = 9;
  int btnState = HIGH;
  int btnStatePrev = HIGH;
  
  int buzzPin = 11;

  int state = 0;

  int del = 0;
  
  void setup() {
    // put your setup code here, to run once:
    
    Serial.begin(9600);
    
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    pinMode(ledPin5, OUTPUT);
    pinMode(ledPin6, OUTPUT);

    pinMode(btnPin, INPUT_PULLUP);

    pinMode(buzzPin, OUTPUT);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:

    btnState = digitalRead(btnPin);

    randomSeed(analogRead(0));
    del = random(190, 210);
    
    Serial.println(btnState);
    Serial.println(btnStatePrev);
    Serial.println(" ");
    Serial.println(" ");
    
    if(state == 0){
        
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);

        if(btnState != btnStatePrev){
          if(btnState == LOW){
            state += 1;
            }
          btnStatePrev = btnState;
        }
      
    }  
    else if(state == 1 && btnStatePrev != LOW){
        
        digitalWrite(ledPin1,LOW);
        delay(50);
        digitalWrite(ledPin2,LOW);
        delay(50);
        digitalWrite(ledPin3,LOW);
        delay(50);
        digitalWrite(ledPin4,LOW);
        delay(50);
        digitalWrite(ledPin5,LOW);
        delay(50);
        digitalWrite(ledPin6,LOW);
        delay(1000);
        
        digitalWrite(ledPin1,HIGH);
        tone(buzzPin,500);
        delay(250);
        noTone(buzzPin);
        digitalWrite(ledPin1,LOW);
        delay(250);
        digitalWrite(ledPin2,HIGH);
        tone(buzzPin,500);
        delay(250);
        noTone(buzzPin);
        digitalWrite(ledPin2,LOW);
        delay(250);
        digitalWrite(ledPin3,HIGH);
        tone(buzzPin,500);
        delay(250);
        noTone(buzzPin);
        digitalWrite(ledPin3,LOW);
        delay(250);
        digitalWrite(ledPin4,HIGH);
        tone(buzzPin,500);
        delay(250);
        noTone(buzzPin);
        digitalWrite(ledPin4,LOW);
        delay(250);
        digitalWrite(ledPin5,HIGH);
        tone(buzzPin,500);
        delay(250);
        noTone(buzzPin);
        digitalWrite(ledPin5,LOW);
        delay(250);
        digitalWrite(ledPin6,HIGH);
        tone(buzzPin,500);
        delay(250);
        noTone(buzzPin);
        digitalWrite(ledPin6,LOW);

        if(btnState != btnStatePrev){
          if(btnState == LOW){
            state += 1;
            }
          btnStatePrev = btnState;
        }
    }
     
    else if(state >= 2){
        
        state = 0;
        
    }
    btnStatePrev = btnState;
  }
