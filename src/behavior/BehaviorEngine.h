#pragma once

class BehaviorEngine
{
public:
    void begin();
    void update();

private:
    enum class State
    {
        Idle,
        ReactStart,
        ReactHappy,
        ReturnNeutral
    };

    State state = State::Idle;

    unsigned long stateStart = 0;
};

extern BehaviorEngine behaviorEngine;