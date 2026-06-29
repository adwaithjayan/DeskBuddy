#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"

class Display
{
public:
    Display();

    bool begin();

    void clear();
    void update();

    void pixel(int x, int y);

    void line(int x1, int y1, int x2, int y2);

    void rect(int x, int y, int w, int h);

    void fillRect(int x, int y, int w, int h);

    void circle(int x, int y, int r);

    void fillCircle(int x, int y, int r);

    void text(int x, int y, const String &str, uint8_t size = 1);

    Adafruit_SSD1306 &getDisplay();

private:
    Adafruit_SSD1306 display;
};

extern Display OLED;

#endif