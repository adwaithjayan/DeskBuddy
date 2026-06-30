#include "animation/animator.h"

#include "face/Face.h"
#include "../behavior/BehaviorManager.h"

Animator animator;

void Animator::begin()
{
    behavior.begin();

    randomSeed(micros());

    blinkTime = random(3000, 6000);
    moveTime = random(1500, 3500);
    microMoveTime = random(600, 1200);

    gazeX = 0;
    gazeY = 0;

    face.setExpression(Expression::Neutral);
}

void Animator::update()
{
    behavior.update();

    unsigned long now = millis();

    // ---------------- Blink ----------------

    if (behavior.state() != BehaviorState::Blinking)
    {
        if (now - lastBlink > blinkTime)
        {
            behavior.setState(BehaviorState::Blinking);

            lastBlink = now;

            face.setUpperLid(11);
            face.setLowerLid(11);
        }
    }
    else
    {
        if (now - lastBlink > 280)
        {
            behavior.setState(BehaviorState::Idle);

            face.setUpperLid(0);
            face.setLowerLid(0);

            blinkTime = random(3000, 7000);
        }
    }

    // ---------------- Main Look ----------------

    if (behavior.state() != BehaviorState::Blinking &&
        now - lastMove > moveTime)
    {
        lastMove = now;

        randomLook();

        moveTime = random(1800, 4000);
    }

    // ---------------- Micro Movement ----------------

    if (behavior.state() != BehaviorState::Blinking &&
        now - lastMicroMove > microMoveTime)
    {
        lastMicroMove = now;

        microMove();

        microMoveTime = random(700, 1300);
    }
}

void Animator::randomLook()
{
    int chance = random(0, 100);

    if (chance < 25)
    {
        gazeX = 0;
        gazeY = 0;
    }
    else
    {
        gazeX = random(-3, 4);
        gazeY = random(-2, 3);
    }

    face.look(gazeX, gazeY);
}

void Animator::microMove()
{
    float dx = random(-1, 2) * 0.5f;
    float dy = random(-1, 2) * 0.5f;

    face.look(
        gazeX + dx,
        gazeY + dy
    );
}