// *****************
// Thomas Therkelsen
// 06/12-2017
// *****************

// *****************************************************************************
// Aflevering:

// Krav: Knapper skal være på pin 8 og 9     LED'er skal være på pins 3 og 4.

// Knap 8 skal skifte mellem forskellige modes på LED'en på pin 3:
// 1. blink 500 ms 
// 2. blink 250 ms
// 3. blink random (100-500 ms)
// 4. fade op & ned

// Knap 9 skal toggle mellem tænd og sluk på LED'en på pin 4.
// *****************************************************************************


//  Her sætter jeg knap pins samt LED pins med ints, så jeg bare kan ændre på navnet i koden, i stedet for, at skulle skrive tallet.
int buttpin1 = 8;
int buttpin2 = 9;

int ledpin1 = 3;
int ledpin2 = 4;

// Her laver jeg int's som fortæller om LED'erne er tændt eller slukket.
int ledState1 = LOW;
int ledState2 = LOW;

// Her laver jeg bools som fortæller om knapper er trykket ned eller ikke er.
bool pressed = true;
bool checkState = false;

bool checkState2 = false;

// Her laver jeg ints som den fjerde mode skal bruge til at fade op og ned med. Én som bestæmmer hvor meget LED'en skal lyse og en anden der bestemmer hvor hurtigt den skal fade med.
int brightness = 0;
int fadeAmount = 5;

int mode = 0;

// Her laver jeg en unsigned long som indeholder mængden af millisekunder LED'en skal have som delay.
unsigned long timer = 500; 
// Her laver jeg en unsigned long som tæller hvor længe det er siden, at LED'en blinkede sidst.
unsigned long ledTidSiden = 0; 
// De to ovenstående unsigned long's skal bruges til at lave timer.

void setup() {
// Her sætter jeg LED pins til at kunne sende et output.
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  
// Her sætter jeg knap pins til at kunne sende et input, med pullup mode for at undgå støj på læsningen af knappen.
  pinMode(buttpin2, INPUT_PULLUP);
  pinMode(buttpin1, INPUT_PULLUP);
}

void loop() {
// Toggle mellem forskelluge modes----------------------------------------------------------------------------------

// Koden herunder gør, at hvis der trykkes på knap nummer 1, så lægges der 1 til int'en kaldet mode.
  if (digitalRead(buttpin1) == LOW && checkState2 == false)
  {
    mode += 1;
  }

  if (digitalRead(buttpin1) == LOW && checkState2 == false)
  {
    checkState2 = true;
  }

  if (digitalRead(buttpin1) == HIGH && checkState2 == true)
  {
    checkState2 = false;
  }

// Koden herunder starter med at definere timeren på 500ms.
  if (mode == 1) {
    unsigned long tidSidenStart = millis();

    timer = 500;

// Her tjekker den om der er gået 500ms siden sidst hvor LED'en blinkede, hvis der er det, så sætter den ledTidSiden lig med tidSidenStart så den også er læsbar næste gang loop'et køres igennem.
  if (tidSidenStart - ledTidSiden >= timer) {

      ledTidSiden = tidSidenStart;

// Her sætter den ledState til at være HIGH hvis den er LOW og LOW hvis den er HIGH. Altså tænder eller slukker LED'en, afhængig af hvad den gjorde sidst den kørte loopet igennem.
  if (ledState1 == LOW) {

      ledState1 = HIGH;

  } else {

      ledState1 = LOW;

  }
// Til sidst outputter ledpin1 værdien for ledState1.
      digitalWrite(ledpin1, ledState1);

  }
 }
// Koden herunder starter med at definere timeren på 250ms.
   if (mode == 2) {
    unsigned long tidSidenStart = millis();

    timer = 250;
// Her tjekker den om der er gået 250ms siden sidst hvor LED'en blinkede, hvis der er det, så sætter den ledTidSiden lig med tidSidenStart så den også er læsbar næste gang loop'et køres igennem.
  if (tidSidenStart - ledTidSiden >= timer) {

      ledTidSiden = tidSidenStart;

  if (ledState1 == LOW) {

      ledState1 = HIGH;

  } else {

      ledState1 = LOW;

  }
// Her sætter den ledState til at være HIGH hvis den er LOW og LOW hvis den er HIGH. Altså tænder eller slukker LED'en, afhængig af hvad den gjorde sidst den kørte loopet igennem.
      digitalWrite(ledpin1, ledState1);

  }
 }
// Koden herunder starter med at definere timeren på et tilfældigt tal mellem 100ms og 500ms, den bliver sat for hver gang arduinoen har kørt loop igennem, så LED'en blinker med et tilfældigt delay hver gang.
   if (mode == 3) {
    unsigned long tidSidenStart = millis();

    timer = random(100,500);
// Her tjekker den om der er gået timerens værdi siden sidst hvor LED'en blinkede, hvis der er det, så sætter den ledTidSiden lig med tidSidenStart så den også er læsbar næste gang loop'et køres igennem.
  if (tidSidenStart - ledTidSiden >= timer) {

      ledTidSiden = tidSidenStart;

  if (ledState1 == LOW) {

      ledState1 = HIGH;

  } else {

      ledState1 = LOW;

  }
// Her sætter den ledState til at være HIGH hvis den er LOW og LOW hvis den er HIGH. Altså tænder eller slukker LED'en, afhængig af hvad den gjorde sidst den kørte loopet igennem.
      digitalWrite(ledpin1, ledState1);

  }
 }
// Koden herunder starter med at definere timeren på 30ms.
   if (mode == 4) {

     unsigned long tidSidenStart = millis();

    timer = 30;
// Her tjekker den om der er gået 30ms værdi siden sidst hvor LED'en blinkede, hvis der er det, så sætter den ledTidSiden lig med tidSidenStart så den også er læsbar næste gang loop'et køres igennem.
// Derudover sætter den også den nye lysstyrke for LED'en der skal fade.
  if (tidSidenStart - ledTidSiden >= timer) {
  ledTidSiden = tidSidenStart;
  brightness = brightness + fadeAmount;

// Her tjekker den om brightness er over under eller lig med 0, eller over eller lig med 255, og i så fald sætter den fadeAmount lig med minus sig selv, så den 'vender faden om'.
  }
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
// Her skriver den den satte brightness til LED'en.
  analogWrite(ledpin1, brightness);
 }
// Her sætter den mode int'en tilbage til 1, hvis den kommer over 4, så den fortsætter med at loop igennem modes.
 if (mode > 4) {
  
  mode = 1;
  
  }

// Toggle mellem tænd og sluk --------------------------------------------------------------------------------------

// Dette stykke kode tjekker om knappen bliver trykket på, og hvis den gør det, så skifter den mellem tænd og sluk på LED nummer 2.
  if (digitalRead(buttpin2) == LOW && checkState == false)
  {
    pressed = !pressed;
  }

  if (digitalRead(buttpin2) == LOW && checkState == false)
  {
    checkState = true;
  }


  if (digitalRead(buttpin2) == HIGH && checkState == true)
  {
    checkState = false;
  }

  if (pressed == true)
  {
    digitalWrite(ledpin2, HIGH);
  } else {
    digitalWrite(ledpin2, LOW);
  }


}
