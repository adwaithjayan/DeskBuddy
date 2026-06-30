# DeskBuddy Firmware

> A modular, expressive firmware framework for ESP32-powered desktop companions.

DeskBuddy Firmware is an open-source firmware framework for building expressive desktop companions using ESP32-based hardware and OLED displays.

Rather than being a single application, DeskBuddy is designed as a reusable firmware platform with a clean, modular architecture. It provides procedural facial animation, behavior systems, personality, interaction, and a foundation for future features such as Wi-Fi connectivity, OTA updates, weather, notifications, and Home Assistant integration.

---

# Current Status

**Version:** `v0.3.0`

**Branch Status**

* `master` → Stable releases
* `develop` → Active development

Current implementation:

* ✅ Core Engine
* ✅ Display Driver
* ✅ Procedural Face Renderer
* ✅ Animation Engine
* ✅ Expression System
* ✅ Sequence Player
* ✅ Behavior Engine
* ✅ Touch Interaction
* ✅ Boot Animation
* ✅ Personality System
* ✅ Relationship System
* ✅ Memory System
* ✅ Idle Behavior Engine
* ✅ Hardware-Abstraction for Touch Input
* 🚧 Persistent Storage (NVS)
* ⏳ Wi-Fi
* ⏳ OTA Updates
* ⏳ Web Dashboard
* ⏳ Weather
* ⏳ Notifications

---

# Features

## Implemented

### Face Engine

* Procedural eye rendering
* Smooth eye movement
* Dynamic pupils
* Curved eyelids
* Animated eyebrows
* Expression transitions
* Eye breathing animation
* Micro eye movements (saccades)

### Animation

* Delta-time animation engine
* Sequence-based animation system
* Boot animation
* Touch reactions
* Double-tap reactions
* Sleep/Wake sequences

### Interaction

* Capacitive touch support
* Digital touch module support
* Double tap detection
* Long press detection
* Hardware-independent touch interface

### AI & Behavior

* Behavior Engine
* Mood System
* Personality System
* Relationship Engine
* Recent Memory Log
* Intelligent idle behavior

### Architecture

* Modular component design
* Object-oriented architecture
* Hardware abstraction
* Easily extensible framework

---

# Planned Features

## v0.4.x

* Preferences (NVS)
* Wi-Fi Manager
* OTA Firmware Updates
* Web Dashboard
* NTP Time Synchronization

## v0.5.x

* Clock
* Date
* Weather
* Notifications
* Battery Monitoring
* Home Assistant Integration
* MQTT Support

## v1.0.0

* Stable API
* Complete Documentation
* Multiple Face Themes
* Plugin-style Module System

---

# Hardware

Current development hardware

| Component    | Description                                   |
| ------------ | --------------------------------------------- |
| MCU          | ESP32-WROOM                                   |
| Display      | SSD1306 OLED 128×64 (I²C)                     |
| Input        | ESP32 Capacitive Touch / Digital Touch Module |
| Connectivity | Wi-Fi                                         |
| Framework    | Arduino Framework                             |
| IDE          | PlatformIO                                    |

---

# Firmware Architecture

```text
Application
│
├── Engine
├── Display
├── Face
├── Renderer
├── Animator
├── Touch
├── Events
├── Sequence
├── Behavior
├── Mood
├── Personality
├── Relationship
├── Memory
└── Idle Behavior
```

Each subsystem has a single responsibility, making the firmware easy to maintain and extend.

---

# Project Structure

```text
DeskBuddy-Firmware/

include/
│
├── config.h
└── hardware_config.h

src/
│
├── animation/
├── behavior/
├── core/
├── display/
├── events/
├── face/
├── memory/
├── mood/
├── personality/
├── relationship/
├── sequence/
├── touch/

assets/
docs/
screenshots/
```

---

# Building

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

Open the serial monitor:

```bash
pio device monitor
```

---

# Roadmap

## v0.1.0

* Core firmware architecture
* Display driver
* Initial animation engine

## v0.2.0

* Procedural eye renderer
* Expressions
* Eyelids
* Eyebrows
* Improved animations

## v0.3.0

* Sequence Player
* Touch interaction
* Behavior Engine
* Personality System
* Relationship Engine
* Memory System
* Idle behavior
* Boot animation
* Hardware abstraction

## v0.4.0

* Preferences (NVS)
* Wi-Fi
* OTA Updates
* Web Dashboard
* Time synchronization

## v0.5.0

* Clock
* Weather
* Notifications
* Home Assistant
* MQTT
* Battery monitoring

## v1.0.0

* Stable release
* Complete documentation
* Public API
* Multiple face themes
* Production-ready firmware

---

# Contributing

Contributions, feature requests, and bug reports are welcome.

Please open an Issue before making significant architectural changes.

---

# License

This project is licensed under the MIT License.

See the LICENSE file for more information.
