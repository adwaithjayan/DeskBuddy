#pragma once
#include "config.h"
class TouchManager
{
public:
    void begin();
    void update();

    bool tapped() const;
    bool longPressed() const;

private:
    bool tapEvent = false;
    bool longPressEvent = false;

    bool touching = false;

    unsigned long touchStart = 0;

    static constexpr int TOUCH_THRESHOLD = 25;
};

extern TouchManager touch;