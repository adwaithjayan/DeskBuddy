#pragma once

struct Vec2
{
    float x;
    float y;

    constexpr Vec2()
        : x(0.0f), y(0.0f)
    {
    }

    constexpr Vec2(float xValue, float yValue)
        : x(xValue), y(yValue)
    {
    }

    Vec2 operator+(const Vec2& rhs) const
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator-(const Vec2& rhs) const
    {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    Vec2 operator*(float scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2& operator+=(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    void set(float newX, float newY)
    {
        x = newX;
        y = newY;
    }
};