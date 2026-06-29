#pragma once

#include "Eye.h"

class Face
{
public:
    Face();

    void begin();
    void update();

    // Movement
    void look(float dx, float dy);

    // Eye size
    void setEyeSize(float width, float height);

    // Visibility
    void show();
    void hide();

    // Access for renderer
    const Eye& leftEye() const;
    const Eye& rightEye() const;

    void setPupilOffset(float x,float y);

    void setUpperLid(float value);

    void setLowerLid(float value);

private:

    Eye left;
    Eye right;

    void initializeEyes();
};

extern Face face;