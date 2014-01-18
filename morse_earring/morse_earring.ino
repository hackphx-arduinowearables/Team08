#include "FastLED.h"

#define NUM_LEDS 10
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
    Serial.begin(9600);
    Serial1.begin(38400);
    
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  String content = "";
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
  
  /*for (int i = 0; i < NUM_LEDS; i++)
  {
    if (content == "blue")
    {
      Serial.println("B");
      leds[i] = CRGB::Blue;
    }
    else if (content == "red")
    {
      Serial.println("R");
      leds[i] = CRGB::Red;
    }
    else
    {
      leds[i] = CRGB::Black;
    }
  }*/
}
