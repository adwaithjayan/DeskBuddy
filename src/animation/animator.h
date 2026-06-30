#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Arduino.h>

class Animator
{
public:

    void begin();

    void update();
    void microMove();

private:

    unsigned long lastBlink = 0;
    unsigned long blinkTime = 0;

    unsigned long lastMove = 0;
    unsigned long moveTime = 0;

    unsigned long nextSaccade = 0;

    float breathingPhase = 0.0f;



    enum class BlinkState
    {
        Idle,
        Closing,
        Hold,
        Opening
    };

    BlinkState blinkState = BlinkState::Idle;   
    unsigned long blinkStart = 0;

    unsigned long lastMicroMove = 0;
    unsigned long microMoveTime = 0;

    float gazeX = 0;
    float gazeY = 0;                              

    void randomLook();

};

extern Animator animator;

#endif