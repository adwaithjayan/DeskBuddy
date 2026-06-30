#pragma once

enum class Mood
{
    Neutral,
    Happy,
    Curious,
    Sleepy,
    Angry,
    Surprised
};

class MoodManager
{
public:
    void begin();

    void update();

    void set(Mood mood);

    Mood current() const;

private:
    Mood currentMood = Mood::Neutral;
};

extern MoodManager mood;