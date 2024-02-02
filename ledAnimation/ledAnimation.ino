#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define NUM_LEDS 120
#define BLINK_INTERVAL 30 //in seconds

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  static unsigned long lastUpdate = 0;
  static int currentPixel = 0;

  if (millis() - lastUpdate >= (BLINK_INTERVAL*1000) / NUM_LEDS) {
    lastUpdate = millis();
    strip.setPixelColor(currentPixel, strip.Color(random(210, 256), random(210, 256), 0, 0));
    strip.show();
    currentPixel++;

    if (currentPixel > NUM_LEDS) {
      currentPixel = 0;
      strip.clear();
    }
  }
}
