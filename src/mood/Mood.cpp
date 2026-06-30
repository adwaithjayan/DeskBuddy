#include "Mood.h"

MoodManager mood;

void MoodManager::begin()
{
    currentMood = Mood::Neutral;
}

void MoodManager::update()
{
}

void MoodManager::set(Mood m)
{
    currentMood = m;
}

Mood MoodManager::current() const
{
    return currentMood;
}