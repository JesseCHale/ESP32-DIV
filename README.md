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

# ESP32-DIV v2.0 — HaleHound Edition

![ESP32](https://img.shields.io/badge/ESP32--WROOM--32U-blue?logo=espressif)
![Version](https://img.shields.io/badge/Version-2.0-green)
![License](https://img.shields.io/badge/License-Educational-orange)
![Status](https://img.shields.io/badge/Status-Ready%20to%20Flash-brightgreen)

> Multi-radio offensive security platform with WiFi, BLE, SubGHz (CC1101), and 2.4GHz (NRF24L01+) capabilities.

---

## ⚠️ V1 Board Owners

**This firmware is for original V1 ESP32-DIV boards** (ESP32-WROOM-32U).

CiferTech's official v1.5.0 firmware targets the newer V2 boards with ESP32-S3. If you have a V1 board, that firmware won't work for you.

**HaleHound Edition keeps V1 boards alive** with **8 new features**, 22 bug fixes, and continued support.

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
- **Updated Branding** — "v2.0 - HaleHound Edition" displayed on device

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

### Touch Controller (XPT2046)
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

## Bug Fixes (22 Total)

### Original Fixes (17)

| Priority | Fix |
|----------|-----|
| HIGH | Buffer overflow in deauth frame |
| HIGH | Wrong modulation for garage/Tesla replay |
| HIGH | Integer underflow on profile delete |
| MEDIUM | SCREEN_HEIGHT 64→320 (was OLED value) |
| MEDIUM | Double scanNetworks() call removed |
| LOW | Unused variables cleaned up |

### HaleHound Edition Fixes (5)

#### 1. Assignment vs Comparison Bug (wifi.cpp:765)
**Problem:** Used `=` instead of `==`, causing condition to always be true.
```cpp
// BEFORE (BUG):
if (activeIcon = 3) {  // Assignment - always true!

// AFTER (FIXED):
if (activeIcon == 3) {  // Proper comparison
```

#### 2. Null Task Handle Crash (wifi.cpp:1280-1292)
**Problem:** Deleting task handles without null checks caused crashes on exit.
```cpp
// BEFORE (BUG):
vTaskDelete(wifiScanTaskHandle);    // Crash if NULL!

// AFTER (FIXED):
if (wifiScanTaskHandle != NULL) {
    vTaskDelete(wifiScanTaskHandle);
    wifiScanTaskHandle = NULL;
}
```

#### 3. CC1101 TX/RX Pin Swap (subghz.cpp:561,574,1368,1381)
**Problem:** TX and RX data lines were swapped. GDO0 is TX, GDO2 is RX.
```cpp
// BEFORE (BUG):
mySwitch.enableTransmit(TX_PIN);  // Wrong - TX_PIN is GDO2 (RX line)
mySwitch.enableReceive(RX_PIN);   // Wrong - RX_PIN is GDO0 (TX line)

// AFTER (FIXED):
mySwitch.enableTransmit(RX_PIN);  // RX_PIN=16=GDO0 is TX data line
mySwitch.enableReceive(TX_PIN);   // TX_PIN=26=GDO2 is RX data line
```

#### 4. RMT Pulse Truncation (subghz.cpp:2538-2560)
**Problem:** ESP32 RMT max duration is 32767μs. Long pilot pulses were truncated.
```cpp
// BEFORE (BUG):
rmtSymbols[0].duration1 = (proto.pilotLow > 32767) ? 32767 : proto.pilotLow;
// Truncates to 32767 - breaks protocols with longer pilots!

// AFTER (FIXED):
if (proto.pilotLow > 32767) {
    rmtSymbols[0].duration1 = 32767;
    rmtSymbols[1].level0 = 0;  // Continue LOW
    rmtSymbols[1].duration0 = proto.pilotLow - 32767;
    pilotSymbols = 2;  // Use 2 symbols for long pulse
}
```

#### 5. Beacon SSID Overflow (wifi.cpp:549-572)
**Problem:** Fixed packet offsets didn't account for variable SSID length.
```cpp
// BEFORE (BUG):
for (int i = 38 + ssidLength; i <= 43; i++) packet[i] = 0x00;
packet[56] = spamchannel;  // Fixed position - wrong for short SSIDs!
esp_wifi_80211_tx(..., 57, false);  // Fixed size - malformed packet!

// AFTER (FIXED):
if (ssidLength > 32) ssidLength = 32;  // Prevent overflow
int ratesOffset = 38 + ssidLength;     // Dynamic position
int dsOffset = ratesOffset + 10;
packet[dsOffset + 2] = spamchannel;    // Correct position
int packetSize = dsOffset + 3;
esp_wifi_80211_tx(..., packetSize, false);  // Correct size
```

---

## Stability Improvements

- **46 button debounce loops** — Added `delay(10); yield();` to prevent watchdog resets
- **16 recursive calls removed** — Eliminated stack overflow from recursive `handleButtons()` calls
- **RMT driver cleanup** — Proper `rmt_driver_uninstall()` on SubGHz exit

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
