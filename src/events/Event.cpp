#include "Event.h"

EventManager events;

void EventManager::begin()
{
    current = Event::None;
}

void EventManager::push(Event event)
{
    current = event;
}

Event EventManager::poll()
{
    Event e = current;
    current = Event::None;
    return e;
}