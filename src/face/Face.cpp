#include "Face.h"

#include "../core/Math.h"
#include "../core/Engine.h"

Face face;

namespace
{
    constexpr float LEFT_X = 28.0f;
    constexpr float RIGHT_X = 82.0f;
    constexpr float EYE_Y = 20.0f;

    constexpr float EYE_WIDTH = 18.0f;
    constexpr float EYE_HEIGHT = 22.0f;

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

    left.radius = 5.0f;

    left.upperLid = 0.0f;
    left.lowerLid = 0.0f;

    left.targetUpperLid = 0.0f;
    left.targetLowerLid = 0.0f;

    left.pupilOffset.set(0.0f, 0.0f);
    left.targetPupilOffset = left.pupilOffset;

    left.pupilRadius = 2.5f;

    left.visible = true;

    //-------------------------------------

    right.position.set(RIGHT_X, EYE_Y);
    right.targetPosition = right.position;

    right.size.set(EYE_WIDTH, EYE_HEIGHT);
    right.targetSize = right.size;

    right.radius = 5.0f;

    right.upperLid = 0.0f;
    right.lowerLid = 0.0f;

    right.targetUpperLid = 0.0f;
    right.targetLowerLid = 0.0f;

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

    left.position =
        Math::moveTowards(
            left.position,
            left.targetPosition,
            POSITION_SPEED,
            dt);

    left.size =
        Math::moveTowards(
            left.size,
            left.targetSize,
            SIZE_SPEED,
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
        Math::moveTowards(
            left.pupilOffset,
            left.targetPupilOffset,
            PUPIL_SPEED,
            dt);

    //------------------------------------------------

    right.position =
        Math::moveTowards(
            right.position,
            right.targetPosition,
            POSITION_SPEED,
            dt);

    right.size =
        Math::moveTowards(
            right.size,
            right.targetSize,
            SIZE_SPEED,
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
        Math::moveTowards(
            right.pupilOffset,
            right.targetPupilOffset,
            PUPIL_SPEED,
            dt);
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

void Face::setExpression(Expression expression)
{
    switch (expression)
    {
        case Expression::Neutral:
            setEyebrow(0, 18);
            setUpperLid(0);
            setLowerLid(0);
            setEyeSize(18, 22);
            setPupilOffset(0, 0);
            break;

        case Expression::Happy:
            setEyebrow(2, 18);
            setUpperLid(2);
            setLowerLid(0);
            setEyeSize(18, 21);
            setPupilOffset(0, -1);
            break;

        case Expression::Angry:
            setEyebrow(-3, 18);
            setUpperLid(5);
            setLowerLid(0);
            setEyeSize(18, 18);
            setPupilOffset(0, -1);
            break;

        case Expression::Sleepy:
            setEyebrow(0, 18);
            setUpperLid(8);
            setLowerLid(3);
            setEyeSize(18, 18);
            setPupilOffset(0, 1);
            break;

        case Expression::Surprised:
            setEyebrow(4, 18);
            setUpperLid(0);
            setLowerLid(0);
            setEyeSize(16, 28);
            setPupilOffset(0, 0);
            break;
    }
}