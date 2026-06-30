#include "animation/animator.h"

#include "face/Face.h"
#include "../behavior/BehaviorManager.h"
#include "core/Engine.h"

Animator animator;

void Animator::begin()
{
    behavior.begin();

    randomSeed(micros());

    nextSaccade = millis() + random(1000, 3000);

    blinkTime = random(3000, 6000);
    moveTime = random(1500, 3500);
    microMoveTime = random(600, 1200);

    gazeX = 0;
    gazeY = 0;

    face.setExpression(Expression::Happy);
}

void Animator::update()
{
    behavior.update();

    unsigned long now = millis();

    // ---------------- Blink ----------------

    switch (blinkState)
    {
    case BlinkState::Idle:

        if (now - lastBlink > blinkTime)
        {
            blinkState = BlinkState::Closing;
            blinkStart = now;
        }

        break;

    case BlinkState::Closing:

        face.setUpperLid(11);
        face.setLowerLid(11);

        if (now - blinkStart > 80)
        {
            blinkState = BlinkState::Hold;
            blinkStart = now;
        }

        break;

    case BlinkState::Hold:

        if (now - blinkStart > 30)
        {
            blinkState = BlinkState::Opening;
            blinkStart = now;
        }

        break;

    case BlinkState::Opening:

        face.setUpperLid(0);
        face.setLowerLid(0);

        if (now - blinkStart > 180)
        {
            blinkState = BlinkState::Idle;

            lastBlink = now;
            blinkTime = random(2500, 7000);
        }

        break;
    }

    // ---------------- Main Look ----------------

    if (behavior.state() != BehaviorState::Blinking &&
        now - lastMove > moveTime)
    {
        lastMove = now;

        randomLook();

        moveTime = random(1200, 2800);
    }

    // ---------------- Micro Movement ----------------

    if (behavior.state() != BehaviorState::Blinking &&
        now - lastMicroMove > microMoveTime)
    {
        lastMicroMove = now;

        microMove();

        microMoveTime = random(250,700);
    }

    if (millis() > nextSaccade)
    {
        face.look(
            random(-1, 2),
            random(-1, 2));

        nextSaccade =
            millis() + random(1000, 4000);
    }

    breathingPhase += engine.deltaTime() * 1.2f;

    if (breathingPhase > TWO_PI)
        breathingPhase -= TWO_PI;

    float breath = sinf(breathingPhase);

    face.setBreathing(breath);
}

void Animator::randomLook()
{
    int chance = random(100);

    // 60% stay near center
    if (chance < 60)
    {
        gazeX = random(-1, 2);
        gazeY = random(-1, 2);
    }
    // 20% look left/right
    else if (chance < 80)
    {
        gazeX = random(-4, 5);
        gazeY = random(-1, 2);
    }
    // 15% look upward
    else if (chance < 95)
    {
        gazeX = random(-2, 3);
        gazeY = random(-3, 0);
    }
    // 5% look downward
    else
    {
        gazeX = random(-2, 3);
        gazeY = random(1, 3);
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