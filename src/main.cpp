#include <fizz.cpp>
#include <screen.hpp>

#define LIMIT 10
fzb::FizzBuzz fizzbuzz = fzb::FizzBuzz(LIMIT, 0);

void setup() {
  pinMode(BUTTON_CURRENT, INPUT);
  pinMode(BUTTON_INC_LIMIT, INPUT);
  pinMode(BUTTON_DEC_LIMIT, INPUT);

  screen::initialise();
  // First display
  screen::display(fizzbuzz.get_limit(), fizzbuzz.get_current(),
                  fizzbuzz.do_fizzy());
}

void loop() {
  // Check button input
  if (!digitalRead(BUTTON_INC_LIMIT)) fizzbuzz.inc_limit();
  if (!digitalRead(BUTTON_CURRENT)) fizzbuzz.inc_current();
  if (!digitalRead(BUTTON_DEC_LIMIT)) fizzbuzz.dec_limit();

  // Wait
  delay(300);

  // Only reset screen if state changed
  if (fizzbuzz.state_changed()) {
    screen::clear();
    screen::display(fizzbuzz.get_limit(), fizzbuzz.get_current(),
                    fizzbuzz.do_fizzy());
  }
}
