#include <Morse.h>

Morse morse(13);

void setup() {
}

void loop() {
  
  morse.dot(); morse.dot(); morse.dash(); morse.dot();
  
  morse.dot(); morse.dash(); morse.dot(); morse.dot();

  morse.dot();
  
  morse.dash(); morse.dot(); morse.dot();
  
  morse.dash(); morse.dot(); morse.dash(); morse.dash();
  morse.dot(); morse.dash(); morse.dot();
  
  delay(3000);

}
