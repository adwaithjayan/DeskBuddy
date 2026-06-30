#pragma once

#include <Arduino.h>

enum class IdlePattern
{
    Thinking,
    Curious,
    Relaxed,
    Distracted
};

class IdleBehavior
{
public:
    void begin();
    void update();

private:
    IdlePattern currentPattern = IdlePattern::Thinking;

    unsigned long nextAction = 0;
    unsigned long patternStart = 0;

    int step = 0;
};

extern IdleBehavior idleBehavior;