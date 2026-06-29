#include "FaceRenderer.h"

#include "../display/display.h"

FaceRenderer renderer;

void FaceRenderer::draw(const Eye& left,
                        const Eye& right)
{
    OLED.clear();

    drawEye(left);
    drawEye(right);

    OLED.update();
}

void FaceRenderer::drawEye(const Eye& eye)
{
    if(!eye.visible)
        return;

    auto& d = OLED.getDisplay();

    int x = eye.position.x;
    int y = eye.position.y;

    int w = eye.size.x;
    int h = eye.size.y;

    // Eye body
    d.fillRoundRect(
        x,
        y,
        w,
        h,
        eye.radius,
        SSD1306_WHITE);

    // Pupil
    int px = x + w/2 + eye.pupilOffset.x;
    int py = y + h/2 + eye.pupilOffset.y;

    d.fillCircle(
        px,
        py,
        eye.pupilRadius,
        SSD1306_BLACK);

    // Upper eyelid
    if(eye.upperLid > 0)
    {
        d.fillRect(
            x,
            y,
            w,
            eye.upperLid,
            SSD1306_BLACK);
    }

    // Lower eyelid
    if(eye.lowerLid > 0)
    {
        d.fillRect(
            x,
            y+h-eye.lowerLid,
            w,
            eye.lowerLid,
            SSD1306_BLACK);
    }
}