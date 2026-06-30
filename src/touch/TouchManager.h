#pragma once

#include "config.h"

enum class TouchEvent
{
    None,
    Tap,
    DoubleTap,
    LongPress
};

class TouchManager
{
public:
    void begin();
    void update();

    TouchEvent event();

private:
    bool touching = false;

    unsigned long touchStart = 0;
    unsigned long lastTapTime = 0;

    TouchEvent currentEvent = TouchEvent::None;

    static constexpr int TOUCH_THRESHOLD = 25;
    static constexpr unsigned long DOUBLE_TAP_TIME = 350;
};

extern TouchManager touch;