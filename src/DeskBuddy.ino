#include "display/display.h"
#include "face/Face.h"
#include "face/FaceRenderer.h"
#include "animation/animator.h"
#include "core/Engine.h"

void setup()
{
    Serial.begin(115200);

    if(!OLED.begin())
    {
        while(true);
    }

    engine.begin();

    face.begin();

    animator.begin();
}

void loop()
{
    engine.update();

    animator.update();

    face.update();

    renderer.draw(
        face.leftEye(),
        face.rightEye()
    );

    // No delay()
}