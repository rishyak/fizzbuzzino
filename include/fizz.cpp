#include "fizz.hpp"

namespace fzb {

/**
 * @brief Construct a new Fizz Buzz:: Fizz Buzz object
 *
 * @param limit     limit of fizzbuzz operation
 * @param current   current fizzbuzz count
 */
FizzBuzz::FizzBuzz(uint32_t limit, uint32_t current) :
    limit(limit), current(current), prev_limit(limit), prev_current(current) {}

/**
 * @brief Get limit
 *
 * @return uint32_t
 */
uint32_t FizzBuzz::get_limit() {
  return limit;
}

/**
 * @brief Get current
 *
 * @return uint32_t
 */
uint32_t FizzBuzz::get_current() {
  return current;
}

/**
 * @brief increment limit
 */
void FizzBuzz::inc_limit() {
  limit++;
}

/**
 * @brief decrement limit
 */
void FizzBuzz::dec_limit() {
  limit--;
  if (limit < current) {
    current = limit - 1;
  }
}

/**
 * @brief increment current
 */
void FizzBuzz::inc_current() {
  current = ++current % limit;
}

/**
 * @brief perform fizzbuzz
 *
 * @return String
 */
String FizzBuzz::do_fizzy() {
  if (!((current % 3) || (current % 5))) return "FizzBuzz\n";
  if (!(current % 3)) return "Fizz\n";
  if (!(current % 5))
    return "Buzz\n";
  else
    return String(current);
}

/**
 * @brief Check if the state has changed
 *
 * @return true
 * @return false
 */
bool FizzBuzz::state_changed() {
  if (limit != prev_limit) {
    prev_limit = limit;
    return true;
  }
  if (current != prev_current) {
    prev_current = current;
    return true;
  }

  return false;
}

} // namespace fzb
