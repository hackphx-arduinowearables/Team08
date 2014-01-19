#include "FastLED.h"

#define NUM_LEDS 8
#define DATA_PIN1 2
#define DATA_PIN2 3

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

int dotLength = 250; 

void setup() {
    Serial.begin(9600);
    Serial1.begin(38400);
    
    FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS);
    FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds2, NUM_LEDS);
}

void morse(char c);

void ledOn(int length)
{//lights LEDs
  int startTime = millis();
  while (millis() - startTime < length)
    {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds1[i] = CRGB::Blue;
      leds2[i] = CRGB::Blue;
      FastLED.show();
      leds1[i] = CRGB::Black;
      leds2[i] = CRGB::Black;
    }
    FastLED.show();
  }
  delay(dotLength);
}

void dot()
{
  ledOn(dotLength);
}

void dash()
{//3 times as long 
  ledOn(dotLength * 3);
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
{//translate characters to morse
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
      delay(0);
  }
}

