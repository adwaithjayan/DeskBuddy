#include "Engine.h"

Engine engine;

void Engine::begin()
{
    previousTime = micros();
}

void Engine::update()
{
    currentTime = micros();

    uint32_t delta = currentTime - previousTime;

    previousTime = currentTime;

    dt = delta / 1000000.0f;

    if(dt <= 0.0f)
        dt = 0.000001f;

    currentFPS = 1.0f / dt;

    frames++;
}

float Engine::deltaTime() const
{
    return dt;
}

float Engine::fps() const
{
    return currentFPS;
}

uint32_t Engine::frameCount() const
{
    return frames;
}

uint32_t Engine::uptime() const
{
    return millis();
}