#include "Face.h"
#include <math.h>

#include "../core/Math.h"
#include "../core/Engine.h"

Face face;

namespace
{
    constexpr float LEFT_X = 28.0f;
    constexpr float RIGHT_X = 82.0f;
    constexpr float EYE_Y = 20.0f;

    constexpr float EYE_WIDTH = 20.0f;
    constexpr float EYE_HEIGHT = 20.0f;

    constexpr float POSITION_SPEED = 60.0f;
    constexpr float SIZE_SPEED = 180.0f;

    constexpr float LID_SPEED = 90.0f;
    constexpr float PUPIL_SPEED = 65.0f;

     
}

Face::Face()
{
}

void Face::initializeEyes()
{
    left.position.set(LEFT_X, EYE_Y);
    left.targetPosition = left.position;

    left.size.set(EYE_WIDTH, EYE_HEIGHT);
    left.targetSize = left.size;

    left.radius = 7.0f;
    left.targetRadius = left.radius;

    left.upperLid = 11.0f;
    left.lowerLid = 11.0f;

    left.targetUpperLid = 11.0f;
    left.targetLowerLid = 11.0f;

    left.pupilOffset.set(0.0f, 0.0f);
    left.targetPupilOffset = left.pupilOffset;

    left.pupilRadius = 2.5f;

    left.visible = true;

    //-------------------------------------

    right.position.set(RIGHT_X, EYE_Y);
    right.targetPosition = right.position;

    right.size.set(EYE_WIDTH, EYE_HEIGHT);
    right.targetSize = right.size;

    right.radius = 7.0f;
    right.targetRadius = right.radius;

    right.upperLid = 11.0f;
    right.lowerLid = 11.0f;

    right.targetUpperLid = 11.0f;
    right.targetLowerLid = 11.0f;

    right.pupilOffset.set(0.0f, 0.0f);
    right.targetPupilOffset = right.pupilOffset;

    right.pupilRadius = 2.5f;

    left.targetEyebrowAngle = 0.0f;
    right.targetEyebrowAngle = 0.0f;

    right.visible = true;
}

void Face::begin()
{
    initializeEyes();
}

void Face::update()
{
    float dt = engine.deltaTime();

    idleOffset = sinf(millis() * 0.0025f) * 0.2f;

    left.targetPosition.y += idleOffset;
    right.targetPosition.y += idleOffset;

    left.position =
        Math::smoothStep(
            left.position,
            left.targetPosition,
            0.18f
        );

    left.size =
        Math::moveTowards(
            left.size,
            left.targetSize,
            SIZE_SPEED,
            dt);

    left.radius =
        Math::moveTowards(
            left.radius,
            left.targetRadius,
            20.0f,
            dt);

    left.upperLid =
        Math::moveTowards(
            left.upperLid,
            left.targetUpperLid,
            LID_SPEED,
            dt);

    left.lowerLid =
        Math::moveTowards(
            left.lowerLid,
            left.targetLowerLid,
            LID_SPEED,
            dt);

    left.eyebrowAngle =
    Math::moveTowards(
        left.eyebrowAngle,
        left.targetEyebrowAngle,
        25.0f,
        dt);

    right.eyebrowAngle =
        Math::moveTowards(
            right.eyebrowAngle,
            right.targetEyebrowAngle,
            25.0f,
            dt);

    left.pupilOffset =
        Math::smoothStep(
            left.pupilOffset,
            left.targetPupilOffset,
            0.25f
        );

    //------------------------------------------------

    right.position =
        Math::smoothStep(
            right.position,
            right.targetPosition,
            0.18f
        );
    right.size =
        Math::moveTowards(
            right.size,
            right.targetSize,
            SIZE_SPEED,
            dt);

    right.radius =
        Math::moveTowards(
            right.radius,
            right.targetRadius,
            20.0f,
            dt);

    right.upperLid =
        Math::moveTowards(
            right.upperLid,
            right.targetUpperLid,
            LID_SPEED,
            dt);

    right.lowerLid =
        Math::moveTowards(
            right.lowerLid,
            right.targetLowerLid,
            LID_SPEED,
            dt);
            
    right.pupilOffset =
        Math::smoothStep(
            right.pupilOffset,
            right.targetPupilOffset,
            0.25f
        );
}

void Face::look(float dx, float dy)
{
    constexpr float MAX_EYE_X = 2.0f;
    constexpr float MAX_EYE_Y = 1.0f;

    constexpr float MAX_PUPIL_X = 4.0f;
    constexpr float MAX_PUPIL_Y = 4.0f;

    // Clamp input
    dx = Math::clamp(dx, -MAX_PUPIL_X, MAX_PUPIL_X);
    dy = Math::clamp(dy, -MAX_PUPIL_Y, MAX_PUPIL_Y);

    // Small movement of the eye body
    left.targetPosition.set(
        LEFT_X + dx * 0.4f,
        EYE_Y + dy * 0.4f
    );

    right.targetPosition.set(
        RIGHT_X + dx * 0.4f,
        EYE_Y + dy * 0.4f
    );

    // Larger movement of the pupil
    left.targetPupilOffset.set(dx, dy);
    right.targetPupilOffset.set(dx, dy);
}



void Face::setEyeSize(float width, float height)
{
    left.targetSize.set(width, height);
    right.targetSize.set(width, height);
}

void Face::setPupilOffset(float x, float y)
{
    left.targetPupilOffset.set(x, y);
    right.targetPupilOffset.set(x, y);
}

void Face::setUpperLid(float value)
{
    left.targetUpperLid = value;
    right.targetUpperLid = value;
}

void Face::setLowerLid(float value)
{
    left.targetLowerLid = value;
    right.targetLowerLid = value;
}

void Face::show()
{
    left.visible = true;
    right.visible = true;
}

void Face::hide()
{
    left.visible = false;
    right.visible = false;
}

const Eye& Face::leftEye() const
{
    return left;
}

const Eye& Face::rightEye() const
{
    return right;
}


void Face::setEyebrowAngle(float angle)
{
    left.targetEyebrowAngle = angle;
    right.targetEyebrowAngle = angle;
}



void Face::setEyebrow(float angle, float length)
{
    left.targetEyebrowAngle = angle;
    right.targetEyebrowAngle = angle;

    left.eyebrowLength = length;
    right.eyebrowLength = length;
}


void Face::setBreathing(float value)
{
    left.breathing = value;
    right.breathing = value;
}



void Face::setExpression(Expression expression)
{
    switch (expression)
    {
        case Expression::Neutral:
            setEyebrow(0.0f, 18.0f);
            setUpperLid(0.0f);
            setLowerLid(0.0f);
            setEyeSize(20.0f, 20.0f);
            left.targetRadius = 5.0f;
            right.targetRadius = 5.0f;
            break;

        case Expression::Happy:
            setEyebrow(2.0f, 18.0f);
            setUpperLid(2.0f);
            setLowerLid(1.0f);
            setEyeSize(20.0f, 18.0f);
            left.targetRadius = 8.0f;
            right.targetRadius = 8.0f;
            break;

        case Expression::Angry:
            setEyebrow(-4.0f, 18.0f);
            setUpperLid(5.0f);
            setLowerLid(0.0f);
            setEyeSize(19.0f, 18.0f);

            left.targetRadius = 3.0f;
            right.targetRadius = 3.0f;
            break;

        case Expression::Sleepy:
            setEyebrow(0.0f, 18.0f);
            setUpperLid(8.0f);
            setLowerLid(3.0f);
            setEyeSize(22.0f, 14.0f);

            left.targetRadius = 2.0f;
            right.targetRadius = 2.0f;
            break;

        case Expression::Surprised:
            setEyebrow(4.0f, 18.0f);
            setUpperLid(0.0f);
            setLowerLid(0.0f);
            setEyeSize(18.0f, 26.0f);

            left.targetRadius = 10.0f;
            right.targetRadius = 10.0f;
            break;
    }
}