#pragma once

#include <Arduino.h>

class Engine
{
public:

    void begin();

    void update();

    float deltaTime() const;

    float fps() const;

    uint32_t frameCount() const;

    uint32_t uptime() const;

private:

    uint32_t previousTime = 0;

    uint32_t currentTime = 0;

    uint32_t frames = 0;

    float dt = 0.016f;

    float currentFPS = 60.0f;
};

extern Engine engine;