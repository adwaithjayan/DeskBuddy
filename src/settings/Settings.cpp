#include "Settings.h"
#include <Preferences.h>


Preferences preferences;
SettingsManager settings;

void SettingsManager::begin()
{
    preferences.begin("deskbuddy", false);
}

void SettingsManager::load()
{
    displayBrightness =
        preferences.getUChar(
            "brightness",
            255);

    relationshipLevel =
        preferences.getInt(
            "relation",
            50);
}

void SettingsManager::save()
{
    preferences.putUChar(
        "brightness",
        displayBrightness);

    preferences.putInt(
        "relation",
        relationshipLevel);
}

void SettingsManager::setBrightness(uint8_t value)
{
    displayBrightness = value;
    save();
}

uint8_t SettingsManager::brightness() const
{
    return displayBrightness;
}

void SettingsManager::setRelationship(int value)
{
    relationshipLevel = value;

    save();
}

int SettingsManager::relationship() const
{
    return relationshipLevel;
}

void SettingsManager::end()
{
    preferences.end();
}