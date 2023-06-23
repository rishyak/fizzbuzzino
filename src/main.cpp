#include "fizz.cpp"
#include "screen.cpp"

#define LIMIT 31
fzb::FizzBuzz fizzbuzz = fzb::FizzBuzz(LIMIT, 0);

void display();

void setup() {
  pinMode(BUTTON_CURRENT, INPUT);
  pinMode(BUTTON_DEC_LIMIT, INPUT);

  screen::init_screen();
}

void loop() {
  // Check button input
  if (!digitalRead(BUTTON_INC_LIMIT)) fizzbuzz.inc_limit();
  if (digitalRead(BUTTON_CURRENT)) fizzbuzz.inc_current();
  if (digitalRead(BUTTON_DEC_LIMIT)) fizzbuzz.dec_limit();

  // Display fizzbuzz
  display();
  delay(300);

  // Only reset screen if state changed
  if (fizzbuzz.state_changed()) screen::clear_screen();
}

/**
 * @brief pretty-print fizzbuzz on screen
 */
void display() {
  screen::screen.setTextColor(ST77XX_WHITE);
  screen::screen.printf("Limit    %d\n", fizzbuzz.get_limit());
  screen::screen.printf("Current  %d\n", fizzbuzz.get_current());

  screen::screen.setTextColor(ST77XX_CYAN);
  screen::screen.printf("-------------");

  screen::screen.setTextColor(ST77XX_ORANGE);
  screen::screen.print(fizzbuzz.do_fizzy());
}
