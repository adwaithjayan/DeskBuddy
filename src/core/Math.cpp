#include "Math.h"

namespace Math
{

float lerp(float current,
           float target,
           float amount)
{
    return current + (target - current) * amount;
}

Vec2 lerp(const Vec2& current,
          const Vec2& target,
          float amount)
{
    return Vec2(
        lerp(current.x, target.x, amount),
        lerp(current.y, target.y, amount)
    );
}

float clamp(float value,
            float minimum,
            float maximum)
{
    if(value < minimum)
        return minimum;

    if(value > maximum)
        return maximum;

    return value;
}

float moveTowards(float current,
                  float target,
                  float speed,
                  float dt)
{
    float maxDelta = speed * dt;

    if(current < target)
    {
        current += maxDelta;

        if(current > target)
            current = target;
    }
    else if(current > target)
    {
        current -= maxDelta;

        if(current < target)
            current = target;
    }

    return current;
}

Vec2 moveTowards(const Vec2& current,
                 const Vec2& target,
                 float speed,
                 float dt)
{
    return Vec2(
        moveTowards(current.x,
                    target.x,
                    speed,
                    dt),

        moveTowards(current.y,
                    target.y,
                    speed,
                    dt)
    );
}



}