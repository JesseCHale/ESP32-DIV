```
              _                                                   _
         .k$$$$$g,                                           ,g$$$$$k.
      .k$$$$$$$$$$$a.                                     .a$$$$$$$$$$$k.
    .J$$$$$?'   `?$?^?,                                 ,?^?$?`   `?$$$$$L.
   JS$$SI!a,  _.JS$   ?,                               ,?   $SL._  ,a$!IS$$SL
  k$$$SI!:?$$$$$$$$$xu$$j                              j$$ux$$$$$$$$$?:!IS$$$k
 :I$$SI:J$$?*"$$$$4^?*?:                               :?*?^4$$$$"*?$$L:iIS$$I:
 :IS$$SiJ?`  _.'$?`/'   ':                           :'    '/'?$'._  `?LiS$$SI:
  ?ISSik? _        ',    `                              .    ,'       _ ?kiSSI?
    ?i$?` _   k$        .                               :.        $k   _ `?$i?
      '?I:-?z$$I   _._.'                                  ._._   I$$z?-:I?'
     '*?- '?$$a louSxuS?                               ?xuSxuol a$$?' -?*'
           i$$$$$$$$$$$S                               S$$$$$$$$$$$i
              ?$$$?-                                       -?$$$?

     ██░ ██  ▄▄▄       ██▓    ▓█████  ██░ ██  ▒█████   █    ██  ███▄    █ ▓█████▄
    ▓██░ ██▒▒████▄    ▓██▒    ▓█   ▀ ▓██░ ██▒▒██▒  ██▒ ██  ▓██▒ ██ ▀█   █ ▒██▀ ██▌
    ▒██▀▀██░▒██  ▀█▄  ▒██░    ▒███   ▒██▀▀██░▒██░  ██▒▓██  ▒██░▓██  ▀█ ██▒░██   █▌
    ░▓█ ░██ ░██▄▄▄▄██ ▒██░    ▒▓█  ▄ ░▓█ ░██ ▒██   ██░▓▓█  ░██░▓██▒  ▐▌██▒░▓█▄   ▌
    ░▓█▒░██▓ ▓█   ▓██▒░██████▒░▒████▒░▓█▒░██▓░ ████▓▒░▒▒█████▓ ▒██░   ▓██░░▒████▓
     ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░▓  ░░░ ▒░ ░ ▒ ░░▒░▒░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒  ▒▒▓  ▒
     ▒ ░▒░ ░  ▒   ▒▒ ░░ ░ ▒  ░ ░ ░  ░ ▒ ░▒░ ░  ░ ▒ ▒░ ░░▒░ ░ ░ ░ ░░   ░ ▒░ ░ ▒  ▒
     ░  ░░ ░  ░   ▒     ░ ░      ░    ░  ░░ ░░ ░ ░ ▒   ░░░ ░ ░    ░   ░ ░  ░ ░  ░
     ░  ░  ░      ░  ░    ░  ░   ░  ░ ░  ░  ░    ░ ░     ░              ░    ░

              _                                                   _
         .k$$$$$g,                                           ,g$$$$$k.
      .k$$$$$$$$$$$a.                                     .a$$$$$$$$$$$k.
    .J$$$$$?'   `?$?^?,                                 ,?^?$?`   `?$$$$$L.
   JS$$SI!a,  _.JS$   ?,                               ,?   $SL._  ,a$!IS$$SL
  k$$$SI!:?$$$$$$$$$xu$$j                              j$$ux$$$$$$$$$?:!IS$$$k
 :I$$SI:J$$?*"$$$$4^?*?:                              :?*?^4$$$$"*?$$L:iIS$$I:
 :IS$$SiJ?`  _.'$?`/'  ':                            :'    '/'?$'._  `?LiS$$SI:
  ?ISSik? _        ',  .                                .    ,'       _ ?kiSSI?
    ?i$?` _  k$        .:                              :.        $k   _ `?$i?
      '?I:-?z$$I   _._.'                                  ._._   I$$z?-:I?'
     '*?- '?$$a louSxuS?                               ?xuSxuol a$$?' -?*'
           i$$$$$$$$$$$S                               S$$$$$$$$$$$i
              ?$$$?-                                       -?$$$?
```

# ESP32-DIV v2.4.5 — HaleHound Edition

![ESP32](https://img.shields.io/badge/ESP32--WROOM--32U-blue?logo=espressif)
![Version](https://img.shields.io/badge/Version-2.4.5-green)
![License](https://img.shields.io/badge/License-Educational-orange)
![Status](https://img.shields.io/badge/Status-Ready%20to%20Flash-brightgreen)
[![Discord](https://img.shields.io/badge/Discord-Join%20Server-5865F2?logo=discord&logoColor=white)](https://discord.gg/HPyVqAy7)

> Multi-radio offensive security platform with WiFi, BLE, SubGHz (CC1101), and 2.4GHz (NRF24L01+) capabilities.

---

## Colorblind Users: Duggie Edition Available

If you have color vision deficiency, download the **Duggie Edition** instead — same features, colorblind-accessible palette.

[Download Duggie Edition](https://github.com/JesseCHale/ESP32-DIV/releases/tag/v2.4)

---

## What's New in v2.4.5 (January 31, 2026)

### Touch Calibration Constants

Touch calibration now uses centralized constants instead of hardcoded values scattered throughout the codebase.

**The Change:**
All touch coordinate mapping now uses constants from `Touchscreen.h`:
```cpp
int x = ::map(p.x, TS_MINX, TS_MAXX, 0, SCREEN_WIDTH - 1);
int y = ::map(p.y, TS_MAXY, TS_MINY, 0, SCREEN_HEIGHT - 1);
```

**Why This Matters:**
- **DIY/Breadboard builds** — If your touch is off, just edit `Touchscreen.h`
- **One place to calibrate** — No more hunting through 4 different .cpp files
- **Community request** — Thanks @IgorMH for the suggestion

**Files Updated:**
- `bluetooth.cpp`
- `wifi.cpp`
- `subghz.cpp`
- `utils.cpp`

---

## What's New in v2.4 (January 28, 2026)

### Scanner Complete Redesign

The 2.4GHz Scanner has been completely redesigned with a clean, fast bar graph display.

**Scanner Improvements:**
- **Clean Bar Graph Display** — Replaced confusing waterfall with responsive vertical bars
- **WiFi-Only Range (2400-2484 MHz)** — No more ISM band noise, focused on WiFi channels
- **Channel Markers** — Channels 1, 6, 11 (magenta) and Channel 13 (yellow) for international
- **Teal-to-Pink Gradient** — Signal strength shown with color progression
- **Peak-Hold with Decay** — Smooth, stable bar animation

### Calibrate Background Noise — NOW FUNCTIONAL

The calibration button actually works now:
1. Go to Scanner screen
2. Make sure no active transmitters are nearby
3. Press the Calibrate button (first icon)
4. Wait for "Noise floor captured!" message
5. Start scanning — ambient noise is now filtered out

### Spectrum Analyzer Updates

- **WiFi-Only Range** — Now matches Scanner (2400-2484 MHz)
- **Channel 13 Marker** — Added in yellow for international channel detection
- **Updated Frequency Labels** — 2400 | 2442 | 2484
- **Taller Bars** — Improved scaling for better visibility

---

## What's New in v2.2 (January 25, 2026)

### Spectrum Analyzer Waterfall Display

The 2.4GHz Spectrum Analyzer now features a **scrolling waterfall display** with a stunning magenta-to-cyan gradient.

**New Features:**
- **100-row scrolling waterfall** — Real-time signal history below the spectrum bars
- **Magenta → Cyan gradient** — New signals appear magenta at top, fade to cyan as they scroll down
- **Brightness-based intensity** — Signal strength adjusts dot brightness (weak = dim, strong = full bright)
- **Dots-only rendering** — Only active signals draw, black background where no signal exists
- **Orange-Red accent color** — Updated primary color from magenta to orange-red (#FB20)

---

## What's New in v2.1 (January 22, 2026)

### SPI Bus Architecture Overhaul — Touch Finally Works Everywhere

The biggest fix in v2.1. Touch input now survives ALL features without dying.

**The Problem:**
Touch controller (XPT2046), NRF24 radios, CC1101 SubGHz, and SD Card were all fighting over the same SPI bus. When you used SubGHz or 2.4GHz features, touch would stop responding. You'd have to reboot to get it back.

**The Fix:**
Separated the SPI buses completely:

| Bus | Pins | Devices |
|-----|------|---------|
| **VSPI** | 18, 19, 23 | NRF24, CC1101, SD Card (shared) |
| **HSPI** | 25, 32, 33, 35 | Touch Controller (dedicated) |

**Result:** Use any feature, touch keeps working. No more reboots.

---

### WiFi Scanner Display Fix

**The Problem:**
WiFi scanner showed garbled, overlapping text. Network names were huge, rows overlapped, the whole screen was a mess.

**The Fix:**
Added `tft.setTextFont(1)` before `tft.setTextSize(1)` in both functions:
- `drawScanScreen()` at wifi.cpp:2649
- `drawNetworkList()` at wifi.cpp:4082

---

## V1 Board Owners

**This firmware is for original V1 ESP32-DIV boards** (ESP32-WROOM-32U).

CiferTech's official v1.5.0 firmware targets the newer V2 boards with ESP32-S3. If you have a V1 board, that firmware won't work for you.

**HaleHound Edition keeps V1 boards alive** with **8 new features**, 27+ bug fixes, and continued support.

| Your Board | Firmware |
|------------|----------|
| V1 (ESP32-WROOM-32U) | **HaleHound Edition** |
| V2 (ESP32-S3) | CiferTech v1.5.0 |

---

## New Features (HaleHound Exclusive)

Features added that **never existed** in original CiferTech firmware:

| Feature | Description |
|---------|-------------|
| **Spectrum Analyzer** | 2.4GHz visualization with scrolling magenta→cyan waterfall |
| **WLAN Jammer** | Targeted WiFi disruption via NRF24 |
| **Proto Kill** | Multi-protocol 2.4GHz disruption |
| **SubGHz Brute Force** | Automated code TX (Linear, CAME, Nice, Chamberlain, DoorHan, Gate TX) |
| **BLE Sniffer** | Passive Bluetooth packet capture |
| **Brightness Control** | Adjustable screen brightness |
| **Screen Timeout** | Configurable auto-sleep |
| **Full Touch Support** | Touch input on ALL menus and features |

---

## Hardware Requirements

| Component | Specification |
|-----------|---------------|
| **MCU** | ESP32-WROOM-32U |
| **Display** | 2.8" TFT LCD (240x320) ILI9341 |
| **Touch** | XPT2046 Touch Controller |
| **SubGHz** | CC1101 Transceiver (300-928 MHz) |
| **2.4GHz** | NRF24L01+ Transceiver |
| **Buttons** | PCF8574 I2C GPIO Expander |
| **Storage** | SD Card + EEPROM |

---

## Features

### 2.4GHz Radio (NRF24L01+)
- **Channel Scanner** — Scan WiFi channels (2400-2484 MHz) with noise calibration
- **Spectrum Analyzer** — Signal visualization with scrolling magenta→cyan waterfall
- **WLAN Jammer** — Targeted WiFi disruption
- **Proto Kill** — Multi-protocol 2.4GHz disruption

### SubGHz Radio (CC1101)
- **Replay Attack** — Capture and replay RF signals (garages, gates, car fobs)
- **Brute Force** — Automated code transmission (Linear, CAME, Nice, Chamberlain, DoorHan, Gate TX)
- **Jammer** — Broadband SubGHz jamming

### WiFi (ESP32)
- **Packet Monitor** — Real-time capture with channel hopping
- **Beacon Spammer** — Fake AP generation (Rickroll mode included)
- **Deauther** — Targeted deauthentication attacks
- **Deauth Detector** — Passive attack monitoring
- **WiFi Scanner** — Network enumeration
- **Captive Portal** — Evil twin credential harvesting

### Bluetooth (ESP32 BLE)
- **BLE Jammer** — Bluetooth Low Energy disruption
- **BLE Spoofer** — Device address cloning
- **Sour Apple** — iOS popup flooding
- **BLE Sniffer** — Passive packet capture
- **BLE Scanner** — Device discovery

### Tools & Utilities
- Serial Terminal
- OTA Firmware Update
- Brightness Control
- Screen Timeout
- Device Info

---

## HaleHound Visual Changes

This edition features a complete visual overhaul:

- **Custom Color Palette** — Magenta (#FF5EF2) and Cyan (#00CFFF) theme
- **Skull Menu Icons** — 8 custom 16x16 skull-themed navigation icons
- **Splash Screen** — Full-screen HaleHound branded startup
- **Transparent Buttons** — Clean button styling with cyan/magenta borders
- **Updated Branding** — "v2.4 - HaleHound Edition" displayed on device

---

## Quick Flash

### macOS
```bash
chmod +x flash_mac.sh
./flash_mac.sh
```

### Linux
```bash
chmod +x flash_linux.sh
./flash_linux.sh
```

### Windows
```batch
flash_windows.bat
```

> **Note:** Requires `esptool.py` — Install with `pip install esptool`

---

## Pin Configuration

### SPI Bus Architecture (v2.1)

| Bus | Function | MOSI | MISO | CLK | Devices |
|-----|----------|------|------|-----|---------|
| **VSPI** | Radios & Storage | 23 | 19 | 18 | NRF24, CC1101, SD Card |
| **HSPI** | Touch (Dedicated) | 32 | 35 | 25 | XPT2046 |

### Touch Controller (XPT2046) — HSPI
| Pin | GPIO |
|-----|------|
| IRQ | 34 |
| MOSI | 32 |
| MISO | 35 |
| CLK | 25 |
| CS | 33 |

### NRF24L01+
| Pin | GPIO |
|-----|------|
| CE | 4 |
| CSN | 5 |

### PCF8574 Buttons (I2C 0x20)
| Button | Pin |
|--------|-----|
| UP | 6 |
| DOWN | 3 |
| LEFT | 4 |
| RIGHT | 5 |
| SELECT | 7 |

---

## CRITICAL: TFT_eSPI Library Configuration

**If you get a WHITE SCREEN after flashing, this is the fix!**

The TFT_eSPI library requires a `User_Setup.h` file with the correct ESP32-DIV pin configuration. The default library config is for ESP8266 and WILL NOT WORK.

### Fix (Required Before Compiling)

1. Copy `User_Setup.h` from this repo to your TFT_eSPI library folder:

**macOS:**
```bash
cp User_Setup.h ~/Documents/Arduino/libraries/TFT_eSPI/User_Setup.h
```

**Linux:**
```bash
cp User_Setup.h ~/Arduino/libraries/TFT_eSPI/User_Setup.h
```

**Windows:**
```batch
copy User_Setup.h %USERPROFILE%\Documents\Arduino\libraries\TFT_eSPI\User_Setup.h
```

2. Recompile and flash the firmware.

### ESP32-DIV Pin Configuration (in User_Setup.h)
```cpp
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   15
#define TFT_DC    2
#define TFT_RST   0
#define TFT_BL    4
#define USE_HSPI_PORT
```

---

## Build From Source

```bash
# Board: ESP32 Dev Module
# Partition: Huge APP (3MB No OTA/1MB SPIFFS)
# Flash: 4MB @ 240MHz

arduino-cli compile --fqbn esp32:esp32:esp32:PartitionScheme=huge_app .
```

### Required Libraries
- TFT_eSPI (ILI9341) — **MUST configure User_Setup.h first!**
- XPT2046_Touchscreen
- PCF8574
- RF24
- ELECHOUSE_CC1101_SRC_DRV
- RCSwitch
- arduinoFFT
- ESP32 BLE Arduino

---

## Credits

| | |
|---|---|
| **Original Firmware** | [CiferTech](https://github.com/cifertech) |
| **HaleHound Edition** | JMFH |
| **GitHub** | [github.com/JesseCHale/ESP32-DIV](https://github.com/JesseCHale/ESP32-DIV) |
| **Release Date** | January 2026 |

---

<p align="center">
<b>For authorized security research only.</b>
</p>
