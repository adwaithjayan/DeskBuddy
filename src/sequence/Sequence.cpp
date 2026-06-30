#include "Sequence.h"

#include "../face/Face.h"
#include "../mood/Mood.h"

//======================================================
// Sequence Actions
//======================================================

static void TapLook()
{
    face.look(0, -2);
}

static void TapHappy()
{
    mood.set(Mood::Happy);
}

static void TapNeutral()
{
    mood.set(Mood::Neutral);
}

static void DoubleTapSurprised()
{
    mood.set(Mood::Surprised);
}

static void DoubleTapHappy()
{
    mood.set(Mood::Happy);
}

static void DoubleTapNeutral()
{
    mood.set(Mood::Neutral);
}

static void BootClosed()
{
    face.setUpperLid(11);
    face.setLowerLid(11);
}

static void BootHalf()
{
    face.setUpperLid(5);
    face.setLowerLid(5);
}

static void BootOpen()
{
    face.setUpperLid(0);
    face.setLowerLid(0);
}

static void BootLookLeft()
{
    face.look(-3, 0);
}

static void BootLookRight()
{
    face.look(3, 0);
}

static void BootLookCenter()
{
    face.look(0, 0);
}

static void BootHappy()
{
    mood.set(Mood::Happy);
}

static void BootNeutral()
{
    mood.set(Mood::Neutral);
}

//======================================================
// Timelines
//======================================================

static const SequenceStep bootSequence[] =
{
    {0, BootClosed},
    {400, BootHalf},
    {800, BootOpen},
    {1200, BootLookLeft},
    {1700, BootLookRight},
    {2200, BootLookCenter},
    {2600, BootHappy},
    {3400, BootNeutral}
};

static const SequenceStep tapSequence[] =
{
    {0, TapLook},
    {150, TapHappy},
    {1200, TapNeutral}
};

static const SequenceStep doubleTapSequence[] =
{
    {0, DoubleTapSurprised},
    {250, DoubleTapHappy},
    {1200, DoubleTapNeutral}
};



SequencePlayer sequence;

//======================================================

void SequencePlayer::begin()
{
    running = false;
    current = Sequence::None;
    steps = nullptr;
    stepCount = 0;
    currentStep = 0;
}

void SequencePlayer::play(Sequence s)
{   
    stop();
    current = s;

    running = true;

    startTime = millis();

    currentStep = 0;

    switch (current)
    {
        case Sequence::Tap:

            steps = tapSequence;
            stepCount = sizeof(tapSequence) / sizeof(SequenceStep);

            break;

        case Sequence::DoubleTap:

            steps = doubleTapSequence;
            stepCount = sizeof(doubleTapSequence) / sizeof(SequenceStep);

            break;

        case Sequence::Boot:

            steps = bootSequence;
            stepCount = sizeof(bootSequence) / sizeof(SequenceStep);

            break;

        default:

            running = false;

            break;
    }
}

bool SequencePlayer::playing() const
{
    return running;
}

void SequencePlayer::update()
{
    if (!running)
        return;

    unsigned long elapsed = millis() - startTime;

    while (currentStep < stepCount &&
           elapsed >= steps[currentStep].time)
    {
        steps[currentStep].action();

        currentStep++;
    }

    if (currentStep >= stepCount)
    {
        running = false;
    }
}

void SequencePlayer::stop()
{
    running = false;
    current = Sequence::None;
}