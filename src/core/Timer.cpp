#include "Timer.h"

Timer::Timer()
{
    startTime = millis();
}

void Timer::reset()
{
    startTime = millis();
}

bool Timer::elapsed(uint32_t interval)
{
    if(millis() - startTime >= interval)
    {
        startTime = millis();
        return true;
    }

    return false;
}

uint32_t Timer::milliseconds() const
{
    return millis() - startTime;
}