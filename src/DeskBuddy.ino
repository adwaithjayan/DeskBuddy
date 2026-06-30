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
#include "memory/Memory.h"
#include "settings/Settings.h"
#include "relationship/Relationship.h"




void setup()
{
    Serial.begin(115200);

    // Persistent settings
    settings.begin();
    settings.load();

    // Display
    if (!OLED.begin())
    {
        while (true);
    }

    // Core
    engine.begin();

    // Systems
    relationship.begin();
    personality.begin();
    memory.begin();

    // Input
    touch.begin();
    events.begin();

    // Face
    face.begin();
    mood.begin();
    animator.begin();

    // Behaviors
    scheduler.begin();
    behaviorEngine.begin();

    // Sequences
    sequence.begin();
    sequence.play(Sequence::Boot);
    memory.record(MemoryEvent::Boot);
}



void loop()
{
    // Core timing
    engine.update();

    // Input
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

    // Persistent systems
    relationship.update();
    personality.update();

    // Behaviour
    behaviorEngine.update();

    // Animation
    sequence.update();
    mood.update();
    animator.update();
    face.update();

    // Render
    renderer.draw(
        face.leftEye(),
        face.rightEye()
    );
}