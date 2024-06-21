#ifndef FIZZ_H
#define FIZZ_H

#include <Arduino.h>

#include <cstdint>

#define BUTTON_INC_LIMIT 10
#define BUTTON_CURRENT 11
#define BUTTON_DEC_LIMIT 12

namespace fzb {
class FizzBuzz {
 public:
  FizzBuzz(std::uint32_t, std::uint32_t);

  std::uint32_t get_limit();

  std::uint32_t get_current();

  void inc_limit();

  void dec_limit();

  void inc_current();

  String do_fizzy();

  bool state_changed();

 private:
  std::uint32_t limit;
  std::uint32_t current;

  std::uint32_t prev_limit;
  std::uint32_t prev_current;
};

}  // namespace fzb

#endif  // FIZZ_H
