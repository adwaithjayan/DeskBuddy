#ifndef CONFIG_H
#define CONFIG_H

// OLED Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_ADDRESS 0x3C

// ESP32 I2C Pins
#define OLED_SDA 21
#define OLED_SCL 22


enum class TouchInputType
{
    Capacitive,
    Digital
};

constexpr TouchInputType TOUCH_INPUT_TYPE =
    TouchInputType::Capacitive;

// Capacitive touch pin
constexpr int TOUCH_PIN = 4;

// Digital touch module pin
constexpr int TOUCH_DIGITAL_PIN = 4;

// Threshold for capacitive touch
constexpr int TOUCH_THRESHOLD = 25;


#endif