#include "Mood.h"

#include <Arduino.h>

#include "../face/Face.h"

MoodManager mood;

void MoodManager::begin()
{
    currentMood = Mood::Neutral;
    moodStart = millis();

    face.look(0, 0);
    face.setExpression(Expression::Neutral);
}

void MoodManager::update()
{

    if (currentMood == Mood::Neutral)
        return;

    if (millis() - moodStart > 3000)
    {
        set(Mood::Neutral);
    }
    
}

void MoodManager::set(Mood m)
{
    if (currentMood == m)
        return;

    currentMood = m;
    moodStart = millis();

    switch (currentMood)
    {
        case Mood::Neutral:
            face.look(0, 0);
            face.setExpression(Expression::Neutral);
            break;

        case Mood::Happy:
            face.look(0, -1);
            face.setExpression(Expression::Happy);
            break;

        case Mood::Curious:
            face.look(random(-2, 3), random(-2, 1));
            face.setExpression(Expression::Surprised);
            break;

        case Mood::Sleepy:
            face.look(0, 2);
            face.setExpression(Expression::Sleepy);
            break;

        case Mood::Angry:
            face.look(0, -2);
            face.setExpression(Expression::Angry);
            break;

        case Mood::Surprised:
            face.look(0, 0);
            face.setExpression(Expression::Surprised);
            break;
    }
}

Mood MoodManager::current() const
{
    return currentMood;
}