 /*                                            ________________________________________
                                              |                                        |
                                              |  Thomas Therkelsen - 2.z               |
                                              |  Skumringsrelæ aflevering - 6/3-2018   |
                                              |  Programmering B                       |
                                              |________________________________________|                                                                                                                                                  */

  //  Lys sensorens variable
  int photoRes = A0;                              // Lys sensorens analog pin
  int lightLevel;                                 // Variablen som skal indeholde lysværdien
  //  Variable til potmeteret som skal sætte grænseværdien for LED'en
  int limitPot = A1;                              // Potmeterets analog pin
  int limit;                                      // Variablen skal indeholde grænseværdien
  //  Variable til potmeteret som skal bestemme tiden LED'en skal lyse
  int timerPot = A2;                              // Potmeterets analog pin
  int timer;                                      // Variablen som skal indeholde timeren
  //  Variable til LED'en
  int ledPin = 3;                                 // LED'ens digital pin med PWM
  int ledState;                                   // Variablen som skal indeholde LED'ens state
  float ledLightLevel;                            // Variablen som skal indeholde LED'ens lysniveau
  float fadeAmount = 0.01;                        // Variabel som indeholder mængden der skal fades med
  
  void setup() {

    Serial.begin(9600);
    pinMode(ledPin,OUTPUT);                       // LED'ens pin bliver sat til at kunne sende et signal
  
  }
  
  void loop() {

    lightLevel = analogRead(photoRes);            // Variablen bliver sat til at indeholde den værdi som lyssensoren giver
    limit = analogRead(limitPot);                 // Variablen bliver sat til at indeholde den værdi grænseværdi-potmeteret giver
    timer = analogRead(timerPot);                 // Variablen bliver sat til at indeholde den værdi som timer-potmeteret giver

    timer = map(timer, 0, 1023, 1000, 5000);      // Variablen bliver ændret fra at gå fra 0-1023 til at gå fra 1000 til 5000, for at kunne gøre timeren minimum 1000ms og max 5000ms. Her sættes en minimum værdi over 0 sekunder, 
                                                  // ellers kan koden potentielt gå i en loop og fortsætte med at tænde og slukke, hvis den er lige på grænsen hele tiden.
    Serial.println(ledLightLevel);


    if (lightLevel < limit){                      // Hvis lysværdien er lavere end grænseværdien
            
      fadeUp(ledPin);                             // Kør fadeUp funktionen på LED'en
      delay(timer);                               // Og vent i timerens værdi antal millisekunder. 
                                                  // (Her er brugt en delay funktion, da der ikke skal ske noget fra LED'en tænder til der tjekkes igen om LED'en skal forblive tændt)
      } else {                                    // Hvis ikke
        
        fadeDown(ledPin);                         // Kør fadeDown funktionen på LED'en
        
        }
  
  }

  void fadeUp(int ledPin) {                       // Laver en funktion til at fade op, som skal bruge ét parameter, nemlig hvilken pin den skal køre på
    
    while(ledLightLevel <= 255) {                 // Når LED'ens lysniveau er under eller lig med 255
      
      ledLightLevel = ledLightLevel + fadeAmount; // Så læg værdien af fadeAmount til LED'ens lysniveau
      analogWrite(ledPin, ledLightLevel);         // Og send niveauet til LED'en
      
      }
    }

  void fadeDown(int ledPin) {                     // Laver en funktion til at fade ned, som skal bruge ét parameter, nemlig hvilken pin den skal køre på
    
    while(ledLightLevel > 0) {                    // Når LED'en har en værdi på over 0
      
      ledLightLevel = ledLightLevel - fadeAmount; // Så træk værdien af fadeAmount fra LED'ens lysniveau
      analogWrite(ledPin, ledLightLevel);         // Og send niveauet til LED'en
      
      }
    
    }


