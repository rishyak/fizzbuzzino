#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

namespace screen {

Adafruit_ST7789 screen = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void initialise();

void clear();

/**
 * @brief initialise screen
 */
void initialise() {
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);

  screen.init(135, 240);
  screen.setRotation(3);
  screen::clear();
  screen.setTextSize(3);
}

/**
 * @brief clear screen
 */
void clear() {
  screen.fillScreen(ST77XX_BLACK);
  screen.setCursor(0, 10);
}

/**
 * @brief pretty-print fizzbuzz on screen
 *
 * @param limit     the limit
 * @param current   the current number
 * @param fizzy     fizzbuzz string
 */
void display(uint32_t limit, uint32_t current, String fizzy) {
  screen::screen.setTextColor(ST77XX_WHITE);
  screen::screen.printf("Limit    %d\n", limit);
  screen::screen.printf("Current  %d\n", current);

  screen::screen.setTextColor(ST77XX_CYAN);
  screen::screen.printf("-------------");

  screen::screen.setTextColor(ST77XX_ORANGE);
  screen::screen.print(fizzy);
}

} // namespace screen
