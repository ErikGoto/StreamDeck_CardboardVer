
#include <avr/wdt.h>

void setup() {
  // close interrupts
  cli();

  // write magic key to ram
  *(uint16_t*)MAGIC_KEY_POS = 0x7777;

  // watchdog reset
  wdt_enable(WDTO_120MS);
}

void loop() {
  // wait for reset
}
