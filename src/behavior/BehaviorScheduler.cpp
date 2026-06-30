#include "BehaviorScheduler.h"

#include "../mood/Mood.h"

#include <Arduino.h>

BehaviorScheduler scheduler;

void BehaviorScheduler::begin()
{
    nextMoodChange = millis() + random(5000, 12000);
}

void BehaviorScheduler::update()
{
    if (millis() < nextMoodChange)
        return;

    randomMood();

    nextMoodChange = millis() + random(5000, 12000);
}

void BehaviorScheduler::randomMood()
{
    switch (random(5))
    {
        case 0:
            mood.set(Mood::Neutral);
            break;

        case 1:
            mood.set(Mood::Happy);
            break;

        case 2:
            mood.set(Mood::Curious);
            break;

        case 3:
            mood.set(Mood::Sleepy);
            break;

        case 4:
            mood.set(Mood::Surprised);
            break;
    }
}