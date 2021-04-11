#include "Keyboard.h"
#include "HID.h"

void setup() {
  Serial1.begin(115200);
  Keyboard.begin();
}

int muteState = true;

void loop() {
  char c = Serial1.read();
  
  //Acelerador
  if (c == 'x') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
  }
  if (c == 'z') {
    Keyboard.releaseAll();
  }
  //Microfone mute/unmute pelo pedal
  if (c == 'M') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('m');
    delay(100);
    Keyboard.releaseAll();
  }
  if (c == 'N') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('m');
    delay(100);
    Keyboard.releaseAll();
  }
  
  //Linux----------------------------------------------------------------------------------------------------
  //Screenshot to clipboard
  if (c == 'A') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('p');
  }
  if (c == 'B') {
    Keyboard.releaseAll();
  }

  //Save Screenshot
  if (c == 'C') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('p');
  }
  if (c == 'D') {
    Keyboard.releaseAll();
  }
  
  //Spotfy next track
  if (c == 'E') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('n');
  }
  if (c == 'F') {
    Keyboard.releaseAll();
  }
  //Play/Pause spotify
  if (c == 'G') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('b');
    delay(100);
    Keyboard.releaseAll();
    delay(500);
  }
  
  //Microfone mute/unmute
  if (c == 'I') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('m');
  }
  if (c == 'J') {
    Keyboard.releaseAll();
  }

  //Launch Calc
  if (c == 'K') {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('t');
  }
  if (c == 'L') {
    Keyboard.releaseAll();
  }

//Volume Controler
  if (c == 'O') {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(50);
    Keyboard.releaseAll();   
  }
  if (c == 'P') {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('a');
    delay(50);
    Keyboard.releaseAll();
  }
  if (c == 'Q') {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('d');
    delay(50);
    Keyboard.releaseAll();
  }

}
