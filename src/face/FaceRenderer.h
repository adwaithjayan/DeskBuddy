#pragma once

#include "Eye.h"

class FaceRenderer
{
public:

    void draw(const Eye& left,
              const Eye& right);

private:

    void drawEye(const Eye& eye);

};

extern FaceRenderer renderer;