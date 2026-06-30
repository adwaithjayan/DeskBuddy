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

    int x = (int)eye.position.x;
    int y = (int)eye.position.y;
    int w = (int)eye.size.x;
    int h = (int)(eye.size.y + eye.breathing);
    int r = (int)eye.radius;

    // Main eyeball
    d.fillRoundRect(
        x,
        y,
        w,
        h,
        r,
        SSD1306_WHITE
    );

    // Thin black outline
    d.drawRoundRect(
        x,
        y,
        w,
        h,
        r,
        SSD1306_BLACK
    );

    // Restore the inside so the outline is only 1 pixel
    d.fillRoundRect(
        x + 1,
        y + 1,
        w - 2,
        h - 2,
        r - 1,
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

    int x = cx + (int)px;
    int y = cy + (int)py;

    // Outer iris
    d.fillCircle(
        x,
        y,
        eye.pupilRadius + 1,
        SSD1306_BLACK
    );

    // Inner pupil
    d.fillCircle(
        x,
        y,
        eye.pupilRadius - 1,
        SSD1306_BLACK
    );

    // Main highlight
    d.drawPixel(
        x - 1,
        y - 1,
        SSD1306_WHITE
    );

    // Secondary highlight
    d.drawPixel(
        x + 1,
        y - 1,
        SSD1306_WHITE
    );
}

void FaceRenderer::drawUpperLid(const Eye& eye)
{
    if (eye.upperLid <= 0)
        return;

    auto& d = OLED.getDisplay();

    int cx = eye.position.x + eye.size.x / 2;
    int y = eye.position.y - 24 + eye.upperLid;

    d.fillCircle(
        cx,
        y,
        26,
        SSD1306_BLACK
    );
}

void FaceRenderer::drawLowerLid(const Eye& eye)
{
    if (eye.lowerLid <= 0)
        return;

    auto& d = OLED.getDisplay();

    int cx = eye.position.x + eye.size.x / 2;
    int y = eye.position.y + eye.size.y + 24 - eye.lowerLid;

    d.fillCircle(
        cx,
        y,
        26,
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

    bool leftEye = eye.position.x < 64;

    int x1, y1, x2, y2;

    if (leftEye)
    {
        x1 = x;
        y1 = y;

        x2 = x + len;
        y2 = y - slope;
    }
    else
    {
        x1 = x;
        y1 = y - slope;

        x2 = x + len;
        y2 = y;
    }

    // Main eyebrow
    d.drawLine(x1, y1, x2, y2, SSD1306_WHITE);

    // Thickness
    d.drawLine(x1, y1 + 1, x2, y2 + 1, SSD1306_WHITE);
}