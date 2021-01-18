/*
* This is a simplest sketch that demonstrate use of Keyboard library for Arduino. 
* It intended to be used with Arduino based on ATmega32u4 microcontroller, like Arduino Micro or Leonardo.
* More details on the use of the library can be found here:
* https://www.arduino.cc/reference/en/language/functions/usb/keyboard/

* Non-printable keys can be pressed by specifying the key code.
* For instance, to press Left Shift, you can type:
Keyboard.press(0x81);

* Full list of key modifiers you can find here:
* https://www.arduino.cc/en/Reference/KeyboardModifiers
*/
#include "Keyboard.h"

bool button_state = false;    //Store state of the input number 2

void setup(){
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
  delay(1000);
  
  Keyboard.press(0x81);       //Press left shift
  Keyboard.print("H");
  Keyboard.release(0x81);     //Release left shift
  Keyboard.print("ello ");
  delay(1000);
  Keyboard.println("WORLD!");
}

void loop() {
    if (digitalRead(2) != button_state) {   //If input 2 changed value
      button_state = digitalRead(2);        //Record value from input 2
      if (!button_state)                    //If input 2 just connected to the ground
        Keyboard.write(0xB0);               //Press enter
    }   
}
