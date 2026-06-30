#pragma once

#include "Vec2.h"

namespace Math
{
    // Linear interpolation
    float lerp(float current,
               float target,
               float amount);

    Vec2 lerp(const Vec2& current,
              const Vec2& target,
              float amount);

    // Clamp
    float clamp(float value,
                float minimum,
                float maximum);

    // Move at constant speed (units/sec)
    float moveTowards(float current,
                      float target,
                      float speed,
                      float deltaTime);

    Vec2 moveTowards(const Vec2& current,
                     const Vec2& target,
                     float speed,
                     float deltaTime);
    

}