#include "Personality.h"

#include <Arduino.h>

PersonalityManager personality;

void PersonalityManager::begin()
{
    state = Personality::Calm;
    stateStart = millis();
}

void PersonalityManager::update()
{
    if (state != Personality::Calm &&
        millis() - stateStart > 30000)
    {
        state = Personality::Calm;
    }
}

void PersonalityManager::becomePlayful()
{
    state = Personality::Playful;
    stateStart = millis();
}

void PersonalityManager::becomeCurious()
{
    state = Personality::Curious;
    stateStart = millis();
}

void PersonalityManager::becomeSleepy()
{
    state = Personality::Sleepy;
    stateStart = millis();
}

Personality PersonalityManager::current() const
{
    return state;
}