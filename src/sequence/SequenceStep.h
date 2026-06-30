#pragma once

typedef void (*SequenceAction)();

struct SequenceStep
{
    unsigned long time;
    SequenceAction action;
};