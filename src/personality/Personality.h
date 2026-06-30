#pragma once

enum class Personality
{
    Calm,
    Playful,
    Curious,
    Sleepy
};

class PersonalityManager
{
public:
    void begin();
    void update();

    void becomePlayful();
    void becomeCurious();
    void becomeSleepy();

    Personality current() const;

private:
    Personality state = Personality::Calm;

    unsigned long stateStart = 0;
};

extern PersonalityManager personality;