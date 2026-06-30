#pragma once

class SettingsManager
{
public:
    void begin();

    void load();
    void save();

    // Display
    void setBrightness(uint8_t value);
    uint8_t brightness() const;

    // Relationship
    void setRelationship(int value);
    int relationship() const;

private:
    uint8_t displayBrightness = 255;
    int relationshipLevel = 50;
};

extern SettingsManager settings;