#pragma once

enum class Event
{
    None,

    Touch,
    DoubleTap,
    LongTouch,

    Blink,

    Sleep,
    Wake
};
class EventManager
{
public:
    void begin();

    void push(Event event);

    Event poll();

private:
    Event current = Event::None;
};

extern EventManager events;