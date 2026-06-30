#include "FaceRenderer.h"

#include "../core/Math.h"
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
    if (!eye.visible)
        return;

    drawEyeBody(eye);
    drawPupil(eye);
    drawUpperLid(eye);
    drawLowerLid(eye);
    drawEyebrow(eye);
}

void FaceRenderer::drawEyeBody(const Eye& eye)
{
    auto& d = OLED.getDisplay();

    d.fillRoundRect(
        (int)eye.position.x,
        (int)eye.position.y,
        (int)eye.size.x,
        (int)eye.size.y,
        (int)eye.radius,
        SSD1306_WHITE
    );
}

void FaceRenderer::drawPupil(const Eye& eye)
{
    auto& d = OLED.getDisplay();

    int cx = (int)(eye.position.x + eye.size.x / 2);
    int cy = (int)(eye.position.y + eye.size.y / 2);

    float maxX = (eye.size.x / 2.0f) - eye.pupilRadius - 2.0f;
    float maxY = (eye.size.y / 2.0f) - eye.pupilRadius - 3.0f;

    float px = Math::clamp(
        eye.pupilOffset.x,
        -maxX,
        maxX);

    float py = Math::clamp(
        eye.pupilOffset.y,
        -maxY,
        maxY);

    d.fillCircle(
        cx + (int)px,
        cy + (int)py,
        (int)eye.pupilRadius,
        SSD1306_BLACK
    );

    // Eye highlight
    d.drawPixel(
        cx + (int)px - 1,
        cy + (int)py - 1,
        SSD1306_WHITE
    );
}

void FaceRenderer::drawUpperLid(const Eye& eye)
{
    if (eye.upperLid <= 0)
        return;

    auto& d = OLED.getDisplay();

    int x = (int)eye.position.x;
    int y = (int)eye.position.y;
    int w = (int)eye.size.x;
    int h = (int)eye.upperLid;

    d.fillRoundRect(
        x,
        y,
        w,
        h + 2,
        eye.radius,
        SSD1306_BLACK
    );
}

void FaceRenderer::drawLowerLid(const Eye& eye)
{
    if (eye.lowerLid <= 0)
        return;

    auto& d = OLED.getDisplay();

    int x = (int)eye.position.x;
    int y = (int)(eye.position.y + eye.size.y - eye.lowerLid - 2);
    int w = (int)eye.size.x;
    int h = (int)eye.lowerLid + 2;

    d.fillRoundRect(
        x,
        y,
        w,
        h,
        eye.radius,
        SSD1306_BLACK
    );
}


void FaceRenderer::drawEyebrow(const Eye& eye)
{
    auto& d = OLED.getDisplay();

    int x = (int)eye.position.x;
    int y = (int)eye.position.y - eye.eyebrowOffset;

    int len = (int)eye.eyebrowLength;
    int slope = (int)eye.eyebrowAngle;

    bool isLeftEye = (eye.position.x < 64);

    if (isLeftEye)
    {
        d.drawLine(
            x,
            y,
            x + len,
            y - slope,
            SSD1306_WHITE
        );
    }
    else
    {
        d.drawLine(
            x,
            y - slope,
            x + len,
            y,
            SSD1306_WHITE
        );
    }
}