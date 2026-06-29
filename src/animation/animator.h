#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Arduino.h>

class Animator
{
public:

    void begin();

    void update();

private:

    unsigned long lastBlink = 0;
    unsigned long blinkTime = 0;

    unsigned long lastMove = 0;
    unsigned long moveTime = 0;

    bool blinking = false;

    void randomLook();

};

extern Animator animator;

#endif