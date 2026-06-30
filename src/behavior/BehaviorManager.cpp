#include "BehaviorManager.h"

BehaviorManager behavior;

void BehaviorManager::begin()
{
    currentState = BehaviorState::Idle;
}

void BehaviorManager::update()
{
    // Empty for now
}

BehaviorState BehaviorManager::state() const
{
    return currentState;
}

void BehaviorManager::setState(BehaviorState newState)
{
    currentState = newState;
}