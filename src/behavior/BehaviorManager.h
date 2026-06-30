#pragma once

#include "Behavior.h"

class BehaviorManager
{
public:
    void begin();

    void update();

    BehaviorState state() const;

    void setState(BehaviorState newState);

private:
    BehaviorState currentState = BehaviorState::Idle;
};

extern BehaviorManager behavior;