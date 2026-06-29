# DeskBuddy Firmware

> A modular firmware for an expressive ESP32-powered desktop companion.

DeskBuddy Firmware is an open-source firmware designed for ESP32-based desktop companions with OLED displays. The project focuses on smooth animations, modular architecture, and easy extensibility.

The goal is to build a reusable firmware platform that supports expressive facial animations, touch interaction, Wi-Fi connectivity, OTA updates, weather, notifications, and more.

---

## Current Status

**Version:** `v0.1.0`

Current development stage:

- ✅ Core Engine
- ✅ Display Driver
- ✅ Face Renderer
- ✅ Animation Engine
- 🚧 Eye Renderer V2
- ⏳ Touch Support
- ⏳ OTA Updates
- ⏳ Clock
- ⏳ Weather
- ⏳ Notifications

---

## Features

### Current

- Smooth eye movement
- Automatic blinking
- Time-based animation engine
- Modular rendering system
- Delta-time engine
- Object-oriented architecture

### Planned

- Touch interaction
- OTA firmware updates
- Wi-Fi configuration
- Clock
- Weather
- Notifications
- Home Assistant integration
- MQTT support
- Battery monitoring
- Multiple face themes

---

## Hardware

Current development hardware:

| Component | Description |
|-----------|-------------|
| MCU | ESP32-WROOM |
| Display | SSD1306 OLED 128×64 (I²C) |
| Input | ESP32 Capacitive Touch |
| Connectivity | Wi-Fi |
| Framework | Arduino Framework |
| IDE | PlatformIO |

---

## Project Structure

```text
DeskBuddy-Firmware/

├── include/
├── src/
│   ├── animation/
│   ├── core/
│   ├── display/
│   ├── face/
│   └── input/
│
├── assets/
├── docs/
└── screenshots/
```

---

## Building

Clone the repository:

```bash
git clone https://github.com/<YOUR_USERNAME>/DeskBuddy-Firmware.git

cd DeskBuddy-Firmware
```

Build:

```bash
pio run
```

Upload:

```bash
pio run -t upload
```

Monitor Serial:

```bash
pio device monitor
```

---

## Roadmap

### v0.1.0

- Core engine
- Face renderer
- Animation engine

### v0.2.0

- Eye renderer
- Pupils
- Eyelids
- Expressions

### v0.3.0

- Touch interaction
- Gesture support

### v0.4.0

- Wi-Fi
- OTA updates

### v0.5.0

- Clock
- Date
- Weather

### v1.0.0

- Stable release
- Complete API
- Documentation
- Multiple face themes

---

## Contributing

Contributions, feature requests, and bug reports are welcome.

Please open an Issue before making major architectural changes.

---

## License

This project is licensed under the MIT License.

See the LICENSE file for details.