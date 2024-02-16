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
  for(int i=0; i< NUM_LEDS; i++){
    strip.setPixelColor(i, strip.Color(0, 0, 0, 100));
  }
  strip.show();
}
