#include "TouchManager.h"
#include "config.h"
#include <Arduino.h>

TouchManager touch;

void TouchManager::begin()
{
}

void TouchManager::update()
{
    tapEvent = false;
    longPressEvent = false;

    bool pressed = touchRead(TOUCH_PIN) < TOUCH_THRESHOLD;

    if (pressed && !touching)
    {
        touching = true;
        touchStart = millis();
    }

    if (!pressed && touching)
    {
        touching = false;

        if (millis() - touchStart < 700)
            tapEvent = true;
    }

    if (touching)
    {
        if (millis() - touchStart > 1000)
        {
            longPressEvent = true;
            touching = false;
        }
    }
}

bool TouchManager::tapped() const
{
    return tapEvent;
}

bool TouchManager::longPressed() const
{
    return longPressEvent;
}