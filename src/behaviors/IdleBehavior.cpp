#include "IdleBehavior.h"

#include <Arduino.h>

#include "../face/Face.h"
#include "../mood/Mood.h"
#include "../personality/Personality.h"

IdleBehavior idleBehavior;

//==================================================
// Choose pattern based on personality
//==================================================

static IdlePattern choosePattern()
{
    switch (personality.current())
    {
        case Personality::Calm:
            return static_cast<IdlePattern>(random(4));

        case Personality::Playful:
            return (random(100) < 70)
                ? IdlePattern::Distracted
                : IdlePattern::Curious;

        case Personality::Curious:
            return IdlePattern::Curious;

        case Personality::Sleepy:
            return IdlePattern::Relaxed;

        default:
            return IdlePattern::Thinking;
    }
}

//==================================================

void IdleBehavior::begin()
{
    currentPattern = choosePattern();
    nextAction = millis() + random(3000, 6000);
}

void IdleBehavior::update()
{
    if (step == 0 && millis() < nextAction)
        return;

    switch (currentPattern)
    {
        //==================================================
        // THINKING
        //==================================================

        case IdlePattern::Thinking:

            if (step == 0)
            {
                face.look(-2, 0);

                patternStart = millis();

                step = 1;
            }
            else if (step == 1 &&
                     millis() - patternStart > 900)
            {
                face.look(0, 0);

                currentPattern = choosePattern();

                step = 0;

                nextAction = millis() + random(3000, 7000);
            }

            break;

        //==================================================
        // CURIOUS
        //==================================================

        case IdlePattern::Curious:

            if (step == 0)
            {
                face.look(0, -2);

                patternStart = millis();

                step = 1;
            }
            else if (step == 1 &&
                     millis() - patternStart > 700)
            {
                face.look(2, 0);

                patternStart = millis();

                step = 2;
            }
            else if (step == 2 &&
                     millis() - patternStart > 700)
            {
                face.look(0, 0);

                currentPattern = choosePattern();

                step = 0;

                nextAction = millis() + random(3000, 7000);
            }

            break;

        //==================================================
        // RELAXED
        //==================================================

        case IdlePattern::Relaxed:

            if (step == 0)
            {
                mood.set(Mood::Happy);

                patternStart = millis();

                step = 1;
            }
            else if (step == 1 &&
                     millis() - patternStart > 1500)
            {
                mood.set(Mood::Neutral);

                currentPattern = choosePattern();

                step = 0;

                nextAction = millis() + random(4000, 8000);
            }

            break;

        //==================================================
        // DISTRACTED
        //==================================================

        case IdlePattern::Distracted:

            if (step == 0)
            {
                face.look(-2, 0);

                patternStart = millis();

                step = 1;
            }
            else if (step == 1 &&
                     millis() - patternStart > 400)
            {
                face.look(2, 0);

                patternStart = millis();

                step = 2;
            }
            else if (step == 2 &&
                     millis() - patternStart > 400)
            {
                face.look(0, 0);

                currentPattern = choosePattern();

                step = 0;

                nextAction = millis() + random(3000, 6000);
            }

            break;
    }
}