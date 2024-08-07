#include <fizz.hpp>

namespace fzb {

/**
 * @brief Construct a new Fizz Buzz object
 *
 * @param limit     limit of fizzbuzz operation
 * @param current   current fizzbuzz count
 */
FizzBuzz::FizzBuzz(std::uint16_t limit, std::uint16_t current)
    : limit(limit),
      current(current),
      prev_limit(limit),
      prev_current(current) {}

/**
 * @brief Get limit
 *
 * @return limit
 */
std::uint16_t FizzBuzz::get_limit() { return limit; }

/**
 * @brief Get current
 *
 * @return current
 */
std::uint16_t FizzBuzz::get_current() { return current; }

/**
 * @brief increment limit
 */
void FizzBuzz::inc_limit() { limit++; }

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
void FizzBuzz::inc_current() { current = ++current % (limit + 1); }

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
 * @return  true of state has changed
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

}  // namespace fzb
