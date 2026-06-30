#include "Settings.h"

SettingsManager settings;

void SettingsManager::begin()
{
}

void SettingsManager::load()
{
}

void SettingsManager::save()
{
}

void SettingsManager::setBrightness(uint8_t value)
{
    displayBrightness = value;
}

uint8_t SettingsManager::brightness() const
{
    return displayBrightness;
}

void SettingsManager::setRelationship(int value)
{
    relationshipLevel = value;
}

int SettingsManager::relationship() const
{
    return relationshipLevel;
}