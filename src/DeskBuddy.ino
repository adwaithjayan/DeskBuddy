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
#include "sequence/Sequence.h"
#include "personality/Personality.h"


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
    sequence.begin();
    sequence.play(Sequence::Boot);

    personality.begin();
}

void loop()
{
    engine.update();

    touch.update();
    switch (touch.event())
    {
        case TouchEvent::Tap:
            events.push(Event::Touch);
            break;

        case TouchEvent::DoubleTap:
            events.push(Event::DoubleTap);
            break;

        case TouchEvent::LongPress:
            events.push(Event::LongTouch);
            break;

        case TouchEvent::None:
            break;
    }

    sequence.update();

    behaviorEngine.update();

    mood.update();

    animator.update();


    face.update();        // Smoothly animate eyes

    renderer.draw(
        face.leftEye(),
        face.rightEye()
    );
    personality.update();
}