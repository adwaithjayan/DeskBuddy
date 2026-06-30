#include "BehaviorEngine.h"

#include <Arduino.h>

#include "../events/Event.h"
#include "../mood/Mood.h"
#include "../face/Face.h"

BehaviorEngine behaviorEngine;

void BehaviorEngine::begin()
{
    state = State::Idle;
}

void BehaviorEngine::update()
{
    switch(state)
    {
        case State::Idle:

            switch(events.poll())
            {
                case Event::Touch:

                    face.look(0, -2);

                    state = State::ReactStart;

                    stateStart = millis();

                    break;

                case Event::LongTouch:

                    mood.set(Mood::Sleepy);

                    state = State::ReturnNeutral;

                    stateStart = millis();

                    break;

                default:
                    break;
            }

            break;

        case State::ReactStart:

            if(millis()-stateStart>250)
            {
                mood.set(Mood::Happy);

                state = State::ReactHappy;

                stateStart = millis();
            }

            break;

        case State::ReactHappy:

            if(millis()-stateStart>2000)
            {
                mood.set(Mood::Neutral);

                state = State::Idle;
            }

            break;

        case State::ReturnNeutral:

            if(millis()-stateStart>3000)
            {
                mood.set(Mood::Neutral);

                state = State::Idle;
            }

            break;
    }
}