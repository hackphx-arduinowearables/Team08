#include "FastLED.h"

#define NUM_LEDS 16
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

int dotLength = 500; 

void setup() {
    Serial.begin(9600);
    Serial1.begin(38400);
    
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void ledOn(int length)
{
  int startTime = millis();
  while (millis() - startTime < length)
    {
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB::Blue;
        FastLED.show();
        leds[i] = CRGB::Black;
        //delay (5);
    }//lights LEDs
  }
  delay(dotLength);
}
void dot()
{
  ledOn(dotLength);
}
void dash()
{
  ledOn(3*dotLength);
 //3 times as long 
}
void loop()
{
  dot();
  dash();
}
  /*String content = "";
  char character;
  while (Serial1.available())
  {
    character = Serial1.read();
    content.concat(character);
  }
  
  if (content != "")
  {
    Serial.print(content);
  
    int length = content.length();
    for (int i = 0; i < length; i++)
    {
      Serial.println(content[i]);
    }
  }
  
  // Morse shit goes here.
  
  
}*/
