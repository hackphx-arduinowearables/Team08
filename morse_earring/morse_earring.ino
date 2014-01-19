#include "FastLED.h"

#define NUM_LEDS 16
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

int dotLength = 250; 

void setup() {
    Serial.begin(9600);
    Serial1.begin(38400);
    
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void morse(char c);

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
      morse(content[i]);
    }
  }
}

void morse(char c)
{
  switch (c)
  {
    case 'a':
      dot();
      dash();
      break;
    case 'b':
      dash();
      dot();
      dot();
      dot();
      break;
    case 'c':
      dash();
      dot();
      dash();
      dot();
      break;
    case 'd':
      dash();
      dot();
      dot();
      break;
    case 'e':
      dot();
      break;
    case 'f':
      dot();
      dot();
      dash();
      dot();
      break;
    case 'g':
      dash();
      dash();
      dot();
      break;
    case 'h':
      dot();
      dot();
      dot();
      dot();
      break;
    case 'i':
      dot();
      dot();
      break;
    case 'j':
      dot();
      dash();
      dash();
      dash();
      break;
    case 'k':
      dash();
      dot();
      dash();
      break;
    case 'l':
      dot();
      dash();
      dot();
      dot();
      break;
    case 'm':
      dash();
      dash();
      break;
    case 'n':
      dash();
      dot();
      break;
    case 'o':
      dash();
      dash();
      dash();
      break;
    case 'p':
      dot();
      dash();
      dash();
      dot();
      break;
    case 'q':
      dash();
      dash();
      dot();
      dash();
      break;
    case 'r':
      dot();
      dash();
      dot();
      break;
    case 's':
      dot();
      dot();
      dot();
      break;
    case 't':
      dash();
      break;
    case 'u':
      dot();
      dot();
      dash();
      break;
    case 'v':
      dot();
      dot();
      dot();
      dash();
      break;
    case 'w':
      dot();
      dash();
      dash();
      break;
    case 'x':
      dash();
      dot();
      dot();
      dash();
      break;
    case 'y':
      dash();
      dot();
      dash();
      dash();
      break;
    case 'z':
      dash();
      dash();
      dot();
      dot();
      break;
    case ' ':
      delay(dotLength * 3);
      break;
    default:
      break;
  }
}

