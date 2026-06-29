#include "animation/animator.h"
#include "face/Face.h"

Animator animator;

void Animator::begin()
{
    randomSeed(micros());

    blinkTime = random(3000,6000);

    moveTime = random(1500,3500);
}

void Animator::update()
{
    unsigned long now = millis();

    // ---------- Blink ----------

    if(!blinking)
    {
        if(now-lastBlink > blinkTime)
        {
            blinking = true;

            lastBlink = now;

            // Close eyelids
            face.setUpperLid(11);
            face.setLowerLid(11);
        }
    }
    else
    {
        if(now-lastBlink > 180)
        {
            blinking = false;

            // Open eyelids
            face.setUpperLid(0);
            face.setLowerLid(0);

            blinkTime = random(2500,7000);
        }
    }

    // ---------- Look Around ----------

   if(!blinking && now - lastMove > moveTime)
    {
        lastMove = now;

        randomLook();

        moveTime = random(1500,3500);
    }
}

void Animator::randomLook()
{
    int chance = random(0, 100);

    if (chance < 25)
    {
        // Look straight
        face.look(0, 0);
    }
    else
    {
        int dx = random(-3, 4);
        int dy = random(-2, 3);

        face.look(dx, dy);
    }
}