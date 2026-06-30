#include "Sequence.h"

SequencePlayer sequence;

void SequencePlayer::begin()
{
    current = Sequence::None;
}

void SequencePlayer::play(Sequence s)
{
    current = s;
    startTime = millis();
}

bool SequencePlayer::playing() const
{
    return current != Sequence::None;
}

void SequencePlayer::update()
{
}