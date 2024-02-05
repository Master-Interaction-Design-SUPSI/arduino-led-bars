#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define NUM_LEDS 120
#define BLINK_INTERVAL 5 //in seconds

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  static unsigned long lastUpdate = 0;
  static int currentPixel = 0;
  static bool filling = true; // Flag to indicate if the LED bar is filling or emptying

  if (millis() - lastUpdate >= (BLINK_INTERVAL*1000) / NUM_LEDS) {
    lastUpdate = millis();

    if (filling) {
      strip.setPixelColor(currentPixel, strip.Color(255, 255, 0, 0));
      currentPixel++;

      if (currentPixel >= NUM_LEDS) {
        filling = false;
      }
    } else {
      strip.setPixelColor(currentPixel, strip.Color(0, 0, 0, 0));
      currentPixel--;

      if (currentPixel < 0) {
        filling = true;
        strip.clear();
      }
    }

    strip.show();
  }
}
