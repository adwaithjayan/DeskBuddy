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

        DoubleTapReaction,

        Drowsy,
        Sleeping,
        Waking,

        ReturnNeutral
    };

    State state = State::Idle;

    unsigned long stateStart = 0;
    unsigned long lastInteraction = 0;

    static constexpr unsigned long SLEEP_TIMEOUT = 30000;   // 60 seconds
};

extern BehaviorEngine behaviorEngine;