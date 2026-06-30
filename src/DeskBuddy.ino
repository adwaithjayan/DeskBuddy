#include "display/display.h"
#include "face/Face.h"
#include "face/FaceRenderer.h"
#include "animation/animator.h"
#include "core/Engine.h"
#include "mood/Mood.h"
#include "behavior/BehaviorScheduler.h"
#include "touch/TouchManager.h"
#include "events/Event.h"
#include "behavior/BehaviorEngine.h"

void setup()
{
    Serial.begin(115200);

    if (!OLED.begin())
    {
        while (true);
    }

    touch.begin();

    engine.begin();

    face.begin();

    mood.begin();

    animator.begin();

    scheduler.begin();

    events.begin();
}

void loop()
{
    engine.update();

    touch.update();
    if (touch.tapped())
    {
        events.push(Event::Touch);
    }

    if (touch.longPressed())
    {
        events.push(Event::LongTouch);
    }

behaviorEngine.update();

mood.update();

animator.update();


    face.update();        // Smoothly animate eyes

    renderer.draw(
        face.leftEye(),
        face.rightEye()
    );
}