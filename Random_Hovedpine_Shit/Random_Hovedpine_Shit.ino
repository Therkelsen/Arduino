
int buzzerPin = 3;

int redPin = 5;
int grnPin = 6;
int bluPin = 9;

int redVal = 0;
int grnVal = 0;
int bluVal = 0;

int buttonPin = 13;

int buttonState = 0;

int buzzerVal = 0;

unsigned long previousMillis = 0;

void setup(){

  Serial.begin(9600);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){

  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW){
    
    tone(buzzerPin, buzzerVal);
    analogWrite(redPin, redVal);
    analogWrite(grnPin, grnVal);
    analogWrite(bluPin, bluVal);
    Serial.println(buzzerVal);
        
    } else {
      
      noTone(buzzerPin);
      digitalWrite(redPin, LOW);
      digitalWrite(grnPin, LOW);
      digitalWrite(bluPin, LOW);
      buzzerVal = random(1,10000);
      redVal = random(255);
      grnVal = random(255);
      bluVal = random(255);
      
      }
  
}
