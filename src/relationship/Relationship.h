#pragma once
#include "personality/Personality.h"


class RelationshipManager
{
public:
    void begin();
    void update();

    void onTouch();
    void onDoubleTap();
    void onLongTouch();

    void increase(int amount = 1);
    void decrease(int amount = 1);

    int value() const;

private:
    int level = 50;
    unsigned long lastDecay = 0;
    void updatePersonality();
};

extern RelationshipManager relationship;