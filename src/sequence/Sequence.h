#pragma once

#include <Arduino.h>
#include "SequenceStep.h"

enum class Sequence
{
    None,

    Boot,

    Tap,
    DoubleTap,

    Sleep,
    Wake
};

class SequencePlayer
{
public:
    void begin();
    void update();

    void play(Sequence sequence);

    bool playing() const;
    void stop();

private:
    Sequence current = Sequence::None;

    unsigned long startTime = 0;

    bool running = false;

    // Timeline
    const SequenceStep* steps = nullptr;

    int stepCount = 0;

    int currentStep = 0;
};

extern SequencePlayer sequence;