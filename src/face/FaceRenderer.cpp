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

    int px =
        eye.position.x +
        eye.size.x / 2 +
        eye.pupilOffset.x;

    int py =
        eye.position.y +
        eye.size.y / 2 +
        eye.pupilOffset.y;

    d.fillCircle(
        px,
        py,
        (int)eye.pupilRadius,
        SSD1306_BLACK
    );
}

void FaceRenderer::drawUpperLid(const Eye& eye)
{
    if (eye.upperLid <= 0)
        return;

    auto& d = OLED.getDisplay();

    d.fillRect(
        (int)eye.position.x,
        (int)eye.position.y,
        (int)eye.size.x,
        (int)eye.upperLid,
        SSD1306_BLACK
    );
}

void FaceRenderer::drawLowerLid(const Eye& eye)
{
    if (eye.lowerLid <= 0)
        return;

    auto& d = OLED.getDisplay();

    d.fillRect(
        (int)eye.position.x,
        (int)(eye.position.y + eye.size.y - eye.lowerLid),
        (int)eye.size.x,
        (int)eye.lowerLid,
        SSD1306_BLACK
    );
}

void FaceRenderer::drawEyebrow(const Eye&)
{
    // v0.2.1
    // Stub
    // Will be implemented later.
}