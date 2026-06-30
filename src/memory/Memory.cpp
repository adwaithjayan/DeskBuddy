#include "Memory.h"

MemoryManager memory;

void MemoryManager::begin()
{
    index = 0;

    for(int i=0;i<MAX_RECORDS;i++)
    {
        records[i].event = MemoryEvent::None;
        records[i].time = 0;
    }
}

void MemoryManager::record(MemoryEvent event)
{
    records[index].event = event;
    records[index].time = millis();

    index++;

    if(index >= MAX_RECORDS)
        index = 0;
}

MemoryEvent MemoryManager::lastEvent() const
{
    if(index == 0)
        return records[MAX_RECORDS-1].event;

    return records[index-1].event;
}