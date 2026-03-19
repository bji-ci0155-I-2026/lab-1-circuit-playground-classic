///////////////////////////////////////////////////////////////////////////////
// Circuit playground classic semaphore
// Authors:
// Isabella Rodríguez Sánchez
// Esteban Isaac Baires Cerdas
// Jorge Ricardo Díaz Sagot
///////////////////////////////////////////////////////////////////////////////

#include <Adafruit_CircuitPlayground.h>

#define RED           0xFF0000   // change this to your favorite color
#define YELLOW        0xFFFF00
#define GREEN         0x008000
#define FLASH_RATE    250        // lower is faster
#define BRIGHTNESS    32
#define FLASHES       10
#define STOP_TIME     5000
#define GO_TIME       5000

///////////////////////////////////////////////////////////////////////////////
void setup() {
  CircuitPlayground.begin();
  
  // Make it bright!
  CircuitPlayground.setBrightness(BRIGHTNESS);
}


///////////////////////////////////////////////////////////////////////////////
void loop() {
  // Turn on all the pixels to COLOR
  for (int pixel=0; pixel<10; pixel++) {
    CircuitPlayground.setPixelColor(pixel, RED);    
  }
  
  delay(STOP_TIME);

  for (int pixel=0; pixel<10; pixel++) {
    CircuitPlayground.setPixelColor(pixel, GREEN);    
  }

  delay(GO_TIME);

  flash(GREEN);

  for (int pixel=0; pixel<10; pixel++) {
    CircuitPlayground.setPixelColor(pixel, YELLOW);    
  }

  delay(GO_TIME);
}

void flash(unsigned int color) {
  for (int i = 0; i < FLASHES; ++i) {
    for (int pixel=0; pixel<10; pixel++) {
      CircuitPlayground.setPixelColor(pixel, color);    
    }
    // Leave them on for a little bit  
    delay(FLASH_RATE);
    CircuitPlayground.playTone(500,200);    // output a 440 Hz sound for a tenth of a second
    // Turn off all the NeoPixels
    CircuitPlayground.clearPixels();

    // Leave them off for a little bit
    delay(FLASH_RATE);
  }
}

// References:
// Circuit Playground Bike Light - Flasher
// Author: Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)
