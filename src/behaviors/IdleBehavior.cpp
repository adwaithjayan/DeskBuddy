#include "IdleBehavior.h"

#include <Arduino.h>

#include "../face/Face.h"
#include "../mood/Mood.h"

IdleBehavior idleBehavior;

static unsigned long nextAction = 0;

void IdleBehavior::begin()
{
    nextAction = millis() + random(5000, 12000);
}

void IdleBehavior::update()
{
    if (millis() < nextAction)
        return;

    switch (random(100))
    {
        case 0 ... 49:
            face.look(random(-4, 5), random(-2, 3));
            break;

        case 50 ... 69:
            mood.set(Mood::Happy);
            break;

        case 70 ... 84:
            mood.set(Mood::Curious);
            break;

        case 85 ... 94:
            face.look(0, -3);
            break;

        default:
            mood.set(Mood::Sleepy);
            break;
    }

    nextAction = millis() + random(5000, 12000);
}