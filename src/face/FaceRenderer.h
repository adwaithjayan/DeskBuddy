#pragma once

#include "Eye.h"

class FaceRenderer
{
public:
    void draw(const Eye& left, const Eye& right);

private:
    void drawEye(const Eye& eye);

    void drawEyeBody(const Eye& eye);

    void drawPupil(const Eye& eye);

    void drawUpperLid(const Eye& eye);

    void drawLowerLid(const Eye& eye);

    void drawEyebrow(const Eye& eye);
};

extern FaceRenderer renderer;