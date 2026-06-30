#include "BehaviorEngine.h"

#include "../behaviors/IdleBehavior.h"

#include <Arduino.h>

#include "../events/Event.h"
#include "../mood/Mood.h"
#include "../face/Face.h"

BehaviorEngine behaviorEngine;

void BehaviorEngine::begin()
{
    state = State::Idle;

    idleBehavior.begin();

    lastInteraction = millis();
}

void BehaviorEngine::update()
{
    switch (state)
    {
        //====================================================
        // IDLE
        //====================================================

        case State::Idle:

            idleBehavior.update();

            if (millis() - lastInteraction > SLEEP_TIMEOUT)
            {
                mood.set(Mood::Sleepy);

                state = State::Drowsy;

                stateStart = millis();

                break;
            }

            switch (events.poll())
            {
                case Event::Touch:

                    lastInteraction = millis();

                    face.look(0, -2);

                    state = State::ReactStart;

                    stateStart = millis();

                    break;

                case Event::DoubleTap:

                    lastInteraction = millis();

                    mood.set(Mood::Surprised);

                    state = State::DoubleTapReaction;

                    stateStart = millis();

                    break;

                case Event::LongTouch:

                    lastInteraction = millis();

                    mood.set(Mood::Sleepy);

                    state = State::ReturnNeutral;

                    stateStart = millis();

                    break;

                default:
                    break;
            }

            break;

        //====================================================
        // TOUCH REACTION
        //====================================================

        case State::ReactStart:

            if (millis() - stateStart > 250)
            {
                mood.set(Mood::Happy);

                state = State::ReactHappy;

                stateStart = millis();
            }

            break;

        case State::ReactHappy:

            if (millis() - stateStart > 2000)
            {
                mood.set(Mood::Neutral);

                state = State::Idle;
            }

            break;

        //====================================================
        // DOUBLE TAP
        //====================================================

        case State::DoubleTapReaction:

            if (millis() - stateStart > 1200)
            {
                mood.set(Mood::Happy);

                state = State::ReactHappy;

                stateStart = millis();
            }

            break;

        //====================================================
        // LONG PRESS
        //====================================================

        case State::ReturnNeutral:

            if (millis() - stateStart > 3000)
            {
                mood.set(Mood::Neutral);

                state = State::Idle;
            }

            break;

        //====================================================
        // DROWSY
        //====================================================

        case State::Drowsy:

            if (millis() - stateStart > 4000)
            {
                face.setUpperLid(11);
                face.setLowerLid(11);

                state = State::Sleeping;
            }

            break;

        //====================================================
        // SLEEPING
        //====================================================

        case State::Sleeping:

            switch (events.poll())
            {
                case Event::Touch:

                    lastInteraction = millis();

                    face.setUpperLid(0);
                    face.setLowerLid(0);

                    mood.set(Mood::Surprised);

                    state = State::Waking;

                    stateStart = millis();

                    break;

                default:
                    break;
            }

            break;

        //====================================================
        // WAKING
        //====================================================

        case State::Waking:

            if (millis() - stateStart > 1200)
            {
                mood.set(Mood::Happy);

                state = State::ReactHappy;

                stateStart = millis();
            }

            break;
    }
}