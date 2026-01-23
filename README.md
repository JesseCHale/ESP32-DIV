```
                            .......::.:....
                       ..::------------------::..
                     .:-=======================-::.
                   .:---====================-----::.
                 .:::::::-----=-----=--=---:::::::...
               ....:::::----====-=--====--------:::...
               ...::------::---=========--::::::--::.
               ....:::........:.:::::::..........:::.
                .....      ........::..      ...   ..
                . .            ..::....       ...
                             ...::.   ...
                  ..         .::.      ...          .
                 .:..     ......        .....      ....
              ... .:...........      .    .   .....::.
              ........  ..   ...       .....  ..........
                            .....      .....   ...
                             ...... .......
                          ...::.........:::.
                         ....... ....:......
                         ....     .  ....

  ██░ ██  ▄▄▄       ██▓    ▓█████     ██░ ██  ▒█████   █    ██  ███▄    █ ▓█████▄
 ▓██░ ██▒▒████▄    ▓██▒    ▓█   ▀    ▓██░ ██▒▒██▒  ██▒ ██  ▓██▒ ██ ▀█   █ ▒██▀ ██▌
 ▒██▀▀██░▒██  ▀█▄  ▒██░    ▒███      ▒██▀▀██░▒██░  ██▒▓██  ▒██░▓██  ▀█ ██▒░██   █▌
 ░▓█ ░██ ░██▄▄▄▄██ ▒██░    ▒▓█  ▄    ░▓█ ░██ ▒██   ██░▓▓█  ░██░▓██▒  ▐▌██▒░▓█▄   ▌
 ░▓█▒░██▓ ▓█   ▓██▒░██████▒░▒████▒   ░▓█▒░██▓░ ████▓▒░▒▒█████▓ ▒██░   ▓██░░▒████▓
  ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░▓  ░░░ ▒░ ░    ▒ ░░▒░▒░ ▒░▒░▒░ ░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒  ▒▒▓  ▒
  ▒ ░▒░ ░  ▒   ▒▒ ░░ ░ ▒  ░ ░ ░  ░    ▒ ░▒░ ░  ░ ▒ ▒░ ░░▒░ ░ ░ ░ ░░   ░ ▒░ ░ ▒  ▒
  ░  ░░ ░  ░   ▒     ░ ░      ░       ░  ░░ ░░ ░ ░ ▒   ░░░ ░ ░    ░   ░ ░  ░ ░  ░
  ░  ░  ░      ░  ░    ░  ░   ░  ░    ░  ░  ░    ░ ░     ░              ░    ░
```

# ESP32-DIV v2.1 — HaleHound Edition

![ESP32](https://img.shields.io/badge/ESP32--WROOM--32U-blue?logo=espressif)
![Version](https://img.shields.io/badge/Version-2.1-green)
![License](https://img.shields.io/badge/License-Educational-orange)
![Status](https://img.shields.io/badge/Status-Ready%20to%20Flash-brightgreen)

> Multi-radio offensive security platform with WiFi, BLE, SubGHz (CC1101), and 2.4GHz (NRF24L01+) capabilities.

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

**Code Changes:**
- `Touchscreen.cpp` — Moved touch from VSPI to dedicated HSPI bus
- `subghz.cpp` — CC1101 library corrected from HSPI to VSPI
- `bluetooth.cpp` — Added touch reinit after 2.4GHz operations
- `subghz.cpp` — Added touch reinit after SubGHz operations
- Added proper exit handlers that clean up SPI state and reinitialize touch

**Result:** Use any feature, touch keeps working. No more reboots.

---

### WiFi Scanner Display Fix

**The Problem:**
WiFi scanner showed garbled, overlapping text. Network names were huge, rows overlapped, the whole screen was a mess.

**Root Cause:**
`displayLogo()` sets Font 2 (16px) and Font 4 (26px) for the splash screen but never resets back to Font 1. When the WiFi scanner runs, it only called `tft.setTextSize(1)` which sets the SIZE MULTIPLIER, not the actual font. So it inherited Font 2 (16px height) but with row spacing of 15px — every line overlapped the previous by 1 pixel.

**The Fix:**
Added `tft.setTextFont(1)` before `tft.setTextSize(1)` in both functions:
- `drawScanScreen()` at wifi.cpp:2649
- `drawNetworkList()` at wifi.cpp:4082

```cpp
// BEFORE (BUG):
void drawScanScreen() {
    tft.setTextSize(1);  // Only sets multiplier, not font!

// AFTER (FIXED):
void drawScanScreen() {
    tft.setTextFont(1);  // Reset to correct font first
    tft.setTextSize(1);
```

---

### UI Updates

- **About Screen** — HaleHound branding
- **Device Info Screen** — HaleHound branding
- **About Page** — Red font styling
- **Version Display** — "v2.1 - HaleHound Edition"

---

## ⚠️ V1 Board Owners

**This firmware is for original V1 ESP32-DIV boards** (ESP32-WROOM-32U).

CiferTech's official v1.5.0 firmware targets the newer V2 boards with ESP32-S3. If you have a V1 board, that firmware won't work for you.

**HaleHound Edition keeps V1 boards alive** with **8 new features**, 27 bug fixes, and continued support.

| Your Board | Firmware |
|------------|----------|
| V1 (ESP32-WROOM-32U) | **HaleHound Edition** ← You're here |
| V2 (ESP32-S3) | CiferTech v1.5.0 |

---

## ✨ New Features (HaleHound Exclusive)

Features added that **never existed** in original CiferTech firmware:

| Feature | Description |
|---------|-------------|
| **Spectrum Analyzer** | FFT-based 2.4GHz visualization |
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
- **Channel Scanner** — Scan all 126 channels (2.400-2.525 GHz)
- **Spectrum Analyzer** — FFT-based signal visualization
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
- **Updated Branding** — "v2.1 - HaleHound Edition" displayed on device

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

## Bug Fixes (27 Total)

### v2.1 Fixes (3 new)

#### 1. SPI Bus Conflict — Touch Dies After Radio Use
**Severity:** CRITICAL

**Problem:** Touch controller shared VSPI bus with NRF24, CC1101, and SD Card. After using SubGHz or 2.4GHz features, touch stopped responding until reboot.

**Fix:**
- Moved touch to dedicated HSPI bus (pins 25, 32, 33, 35)
- Added exit handlers to reinitialize touch after radio operations
- CC1101 library corrected from HSPI to VSPI

**Files:** `Touchscreen.cpp`, `bluetooth.cpp`, `subghz.cpp`, `bleconfig.h`, `wificonfig.h`

---

#### 2. WiFi Scanner Font Inheritance
**Severity:** HIGH

**Problem:** `displayLogo()` set Font 2/4 but never reset to Font 1. WiFi scanner inherited wrong font, causing 16px text with 15px row spacing = overlapping garbled text.

**Fix:** Added `tft.setTextFont(1)` before `tft.setTextSize(1)` in `drawScanScreen()` and `drawNetworkList()`.

**Files:** `wifi.cpp:2649`, `wifi.cpp:4082`

---

#### 3. Touch Reinit After Feature Exit
**Severity:** MEDIUM

**Problem:** Even with separate SPI buses, touch needed reinitialization after radio features released SPI.

**Fix:** Added `ts.begin()` calls in SubGHz and 2.4GHz exit handlers.

**Files:** `subghz.cpp`, `bluetooth.cpp`

---

### v2.0 Fixes (24)

#### Original CiferTech Fixes (17)

| Priority | Fix |
|----------|-----|
| HIGH | Buffer overflow in deauth frame |
| HIGH | Wrong modulation for garage/Tesla replay |
| HIGH | Integer underflow on profile delete |
| MEDIUM | SCREEN_HEIGHT 64→320 (was OLED value) |
| MEDIUM | Double scanNetworks() call removed |
| LOW | Unused variables cleaned up |

#### HaleHound Edition Fixes (7)

**1. Assignment vs Comparison Bug (wifi.cpp:765)**
```cpp
// BEFORE: if (activeIcon = 3)   // Assignment - always true!
// AFTER:  if (activeIcon == 3)  // Proper comparison
```

**2. Null Task Handle Crash (wifi.cpp:1280-1292)**
```cpp
// BEFORE: vTaskDelete(wifiScanTaskHandle);  // Crash if NULL!
// AFTER:  if (wifiScanTaskHandle != NULL) { vTaskDelete(...); }
```

**3. CC1101 TX/RX Pin Swap (subghz.cpp)**
- GDO0 (GPIO 16) is TX data line
- GDO2 (GPIO 26) is RX data line
- Original code had them backwards

**4. RMT Pulse Truncation (subghz.cpp:2538-2560)**
- ESP32 RMT max duration is 32767μs
- Long pilot pulses now split across multiple symbols

**5. Beacon SSID Overflow (wifi.cpp:549-572)**
- Fixed packet offsets for variable SSID length
- Prevents malformed beacon frames

**6. GPIO 16/26 Conflict — SubGHz vs 2.4GHz**
- Added `cleanupSubGHz()` before NRF24 operations
- Added `cleanupNRF24()` before SubGHz operations
- Proper interrupt disable and SPI release

**7. GPIO 5 Conflict — SD Card vs NRF24 radio3**
- Added `cleanupSD()` before radio3 operations
- Added `cleanupNRF24()` before SD operations

---

## Stability Improvements

- **46 button debounce loops** — Added `delay(10); yield();` to prevent watchdog resets
- **16 recursive calls removed** — Eliminated stack overflow from recursive `handleButtons()` calls
- **RMT driver cleanup** — Proper `rmt_driver_uninstall()` on SubGHz exit
- **SPI bus isolation** — Touch on dedicated HSPI prevents conflicts

---

## Build From Source

```bash
# Board: ESP32 Dev Module
# Partition: Huge APP (3MB No OTA/1MB SPIFFS)
# Flash: 4MB @ 240MHz

arduino-cli compile --fqbn esp32:esp32:esp32:PartitionScheme=huge_app .
```

### Required Libraries
- TFT_eSPI (ILI9341)
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
