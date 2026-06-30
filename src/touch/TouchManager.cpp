#include "TouchManager.h"
#include "config.h"

#include <Arduino.h>

TouchManager touch;

void TouchManager::begin()
{
    touching = false;
    currentEvent = TouchEvent::None;
    lastTapTime = 0;
}

void TouchManager::update()
{
    currentEvent = TouchEvent::None;

    bool pressed = touchRead(TOUCH_PIN) < TOUCH_THRESHOLD;

    // Finger touched
    if (pressed && !touching)
    {
        touching = true;
        touchStart = millis();
    }

    // Finger released
    if (!pressed && touching)
    {
        touching = false;

        unsigned long duration = millis() - touchStart;

        if (duration > 30 && duration < 700)
        {
            unsigned long now = millis();

            if (lastTapTime != 0 &&
                (now - lastTapTime) < DOUBLE_TAP_TIME)
            {
                currentEvent = TouchEvent::DoubleTap;
                lastTapTime = 0;
            }
            else
            {
                currentEvent = TouchEvent::Tap;
                lastTapTime = now;
            }
        }
    }

    // Long press
    if (touching)
    {
        if (millis() - touchStart > 1000)
        {
            currentEvent = TouchEvent::LongPress;
            touching = false;
            lastTapTime = 0;
        }
    }
}

TouchEvent TouchManager::event()
{
    TouchEvent e = currentEvent;
    currentEvent = TouchEvent::None;
    return e;
}