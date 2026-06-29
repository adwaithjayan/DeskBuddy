#pragma once

#include <Arduino.h>

class Timer
{
public:

    Timer();

    void reset();

    bool elapsed(uint32_t interval);

    uint32_t milliseconds() const;

private:

    uint32_t startTime;
};