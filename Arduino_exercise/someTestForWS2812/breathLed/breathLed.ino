#include <Adafruit_NeoPixel.h>

#define LedNum 60
#define LedPin 9

Adafruit_NeoPixel theLedStrip = Adafruit_NeoPixel(LedNum, LedPin, NEO_GRB + NEO_KHZ800);

void setup()
{
    theLedStrip.begin();
    theLedStrip.show();
}

void loop()
{
    breathStrip(true, 255, 1, 2);
}

void breathStrip(boolean peaceIf, int strength, int timeGap, int t_)
{

    int r, g;
    if (peaceIf)
    {
        r = 0;
        g = 1;
    }
    else
    {
        r = 1;
        g = 0;
    }
    for (int i = 0; i <= strength; i += timeGap)
    {
        for (int j = 0; j < strip.numPixels(); j++)
        {
            strip.setPixelColor(j, strip.Color(r * i, g * i, 0)); // yellow with a little extra red to make it warmer
        }
        strip.show();
        delay(10);
    }
    delay(t_ * 1000);
    for (int i = strength; i >= 0; i -= timeGap)
    {
        for (int j = 0; j < strip.numPixels(); j++)
        {
            strip.setPixelColor(j, strip.Color(r * i, g * i, 0));
        }
        strip.show();
        delay(10);
    }
    delay(t_ * 1000);
    strip.clear();
}