  
  // Arduino til Processing
  /*int intVal = 0;
  String stringVal;

  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    
    stringVal = (String) intVal;
    
    Serial.println(stringVal);
    
       if (intVal <= 4){
          intVal += 1;
       } else {
    
         intVal = 0;
    
         }
    delay(1000);
   }*/
   
  //___________________________________________________________\\

  // Processing til Arduino
  char val = 0;
  int ledPin = 13;

  void setup() {
    // put your setup code here, to run once:
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    
    if(Serial.available()){

      val = Serial.read();
      
      }
    if(val == '1'){
      
      digitalWrite(ledPin, HIGH);
      
    } else {
      
      digitalWrite(ledPin, LOW);
      
      }
    delay(10);
   }
