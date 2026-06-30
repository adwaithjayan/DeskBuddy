#pragma once

#include <Arduino.h>

enum class MemoryEvent
{
    None,

    Touch,
    DoubleTap,
    LongTouch,

    Wake,
    Sleep,

    Happy,
    Curious,

    Boot
};

struct MemoryRecord
{
    MemoryEvent event;
    unsigned long time;
};

class MemoryManager
{
public:
    void begin();

    void record(MemoryEvent event);

    MemoryEvent lastEvent() const;

private:
    static constexpr int MAX_RECORDS = 10;

    MemoryRecord records[MAX_RECORDS];

    int index = 0;
};

extern MemoryManager memory;