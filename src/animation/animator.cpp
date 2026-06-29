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

            face.setEyeSize(18,2);
        }
    }
    else
    {
        if(now-lastBlink > 180)
        {
            blinking = false;

            face.setEyeSize(18,22);

            blinkTime = random(3000,6000);
        }
    }

    // ---------- Look Around ----------

    if(now-lastMove > moveTime)
    {
        lastMove = now;

        randomLook();

        moveTime = random(2000,4000);
    }
}

void Animator::randomLook()
{
    int dx=random(-8,9);

    int dy=random(-5,6);

    face.look(dx,dy);
}