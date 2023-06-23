#ifndef FIZZ_H
#define FIZZ_H

#include <Arduino.h>
#include <cstdint>

#define BUTTON_INC_LIMIT 0
#define BUTTON_CURRENT   1
#define BUTTON_DEC_LIMIT 2

namespace fzb {
class FizzBuzz {
public:
  FizzBuzz(uint32_t, uint32_t);

  uint32_t get_limit();

  uint32_t get_current();

  void inc_limit();

  void dec_limit();

  void inc_current();

  String do_fizzy();

  bool state_changed();

private:
  uint32_t limit;
  uint32_t current;

  uint32_t prev_limit;
  uint32_t prev_current;
};

} // namespace fzb

#endif // FIZZ_H
