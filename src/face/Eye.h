#pragma once

#include "../core/Vec2.h"

struct Eye
{
    // Current position
    Vec2 position;

    // Target position
    Vec2 targetPosition;

    // Current size
    Vec2 size;

    // Target size
    Vec2 targetSize;

    // Corner radius
    float radius = 5.0f;
    float targetRadius = 5.0f;
    // Current eyelids
    float upperLid = 0.0f;
    float lowerLid = 0.0f;

    // Target eyelids
    float targetUpperLid = 0.0f;
    float targetLowerLid = 0.0f;

    // Current pupil position
    Vec2 pupilOffset;

    // Target pupil position
    Vec2 targetPupilOffset;

    // Pupil radius
    float pupilRadius = 2.5f;

    // Current eyebrow angle

    // Target eyebrow angle
    float targetEyebrowAngle = 0.0f;

    float eyebrowAngle = 0.0f;
    float eyebrowLength = 18.0f;
    int eyebrowOffset = 5;

    // Visible
    bool visible = true;

    float breathing = 0.0f;
};