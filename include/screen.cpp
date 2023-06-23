#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

namespace screen {

void init_screen();

void clear_screen();

Adafruit_ST7789 screen = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

/**
 * @brief initialise screen
 */
void init_screen() {
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);

  screen.init(135, 240);
  screen.setRotation(3);
  screen::clear_screen();
  screen.setTextSize(3);
}

/**
 * @brief clear screen
 */
void clear_screen() {
  screen.fillScreen(ST77XX_BLACK);
  screen.setCursor(0, 10);
}

} // namespace screen
