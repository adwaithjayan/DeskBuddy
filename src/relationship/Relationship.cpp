#include "Relationship.h"
#include <Arduino.h>
#include "../settings/Settings.h"


RelationshipManager relationship;

void RelationshipManager::begin()
{
    level = settings.relationship();
    lastDecay = millis();
}

void RelationshipManager::update()
{
    // Every hour reduce relationship slightly
    if (millis() - lastDecay > 3600000UL)
    {
        decrease();
        lastDecay = millis();
    }
}

void RelationshipManager::increase(int amount)
{
    level = min(100, level + amount);
    settings.setRelationship(level);
}

void RelationshipManager::decrease(int amount)
{
    level = max(0, level - amount);
    settings.setRelationship(level);
}

int RelationshipManager::value() const
{
    return level;
}

void RelationshipManager::onTouch()
{
    increase(1);
    updatePersonality();
}

void RelationshipManager::onDoubleTap()
{
    increase(2);
    updatePersonality();
}

void RelationshipManager::onLongTouch()
{
    increase(3);
    updatePersonality();
}

void RelationshipManager::updatePersonality()
{
    if (level < 30)
    {
        personality.becomeSleepy();
    }
    else if (level < 60)
    {
        // Calm - do nothing
    }
    else if (level < 85)
    {
        personality.becomePlayful();
    }
    else
    {
        personality.becomeCurious();
    }
}