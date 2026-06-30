#pragma once

class BehaviorScheduler
{
public:
    void begin();
    void update();

private:
    unsigned long nextMoodChange = 0;

    void randomMood();
};

extern BehaviorScheduler scheduler;