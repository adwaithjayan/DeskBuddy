#pragma once

enum class Sequence
{
    None,

    Boot,

    Tap,

    DoubleTap,

    Sleep,

    Wake,

    Happy,

    Curious
};

class SequencePlayer
{
public:
    void begin();
    void update();

    void play(Sequence sequence);

    bool playing() const;

private:
    Sequence current = Sequence::None;

    unsigned long startTime = 0;
};

extern SequencePlayer sequence;