#include "display/display.h"

Display OLED;

Display::Display()
    : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1)
{
}

bool Display::begin()
{
    Wire.begin(OLED_SDA, OLED_SCL);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS))
    {
        return false;
    }

    display.clearDisplay();
    display.display();

    return true;
}

void Display::clear()
{
    display.clearDisplay();
}

void Display::update()
{
    display.display();
}

void Display::pixel(int x, int y)
{
    display.drawPixel(x, y, SSD1306_WHITE);
}

void Display::line(int x1, int y1, int x2, int y2)
{
    display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
}

void Display::rect(int x, int y, int w, int h)
{
    display.drawRect(x, y, w, h, SSD1306_WHITE);
}

void Display::fillRect(int x, int y, int w, int h)
{
    display.fillRect(x, y, w, h, SSD1306_WHITE);
}

void Display::circle(int x, int y, int r)
{
    display.drawCircle(x, y, r, SSD1306_WHITE);
}

void Display::fillCircle(int x, int y, int r)
{
    display.fillCircle(x, y, r, SSD1306_WHITE);
}

void Display::text(int x, int y, const String &str, uint8_t size)
{
    display.setTextSize(size);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(x, y);
    display.print(str);
}

Adafruit_SSD1306 &Display::getDisplay()
{
    return display;
}