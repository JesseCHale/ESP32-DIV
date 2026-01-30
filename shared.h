#ifndef SHARED_H
#define SHARED_H

// ========== HALEHOUND COLOR PALETTE ==========
// Primary colors
const uint16_t HALEHOUND_MAGENTA = 0xFB20;  // Orange-Red - Primary (selected items)
const uint16_t HALEHOUND_HOTPINK = 0xF8EA;  // #FF1C52 - Accents
const uint16_t HALEHOUND_BRIGHT = 0xFC9F;   // #FF90FF - Highlights
const uint16_t HALEHOUND_VIOLET = 0xF9FF;   // #FE3CFF - Purple tones
const uint16_t HALEHOUND_DARK = 0x2841;     // #2B080A - Dark backgrounds
const uint16_t HALEHOUND_CYAN = 0x067F;     // #00CFFF - Bright cyan for text
const uint16_t HALEHOUND_BLACK = 0x0000;    // #000000 - Pure black
const uint16_t HALEHOUND_GUNMETAL = 0x18E3; // #1C1C1C - Gunmetal gray
const uint16_t HALEHOUND_GREEN = 0x3FE2;    // #39FF14 - Neon green

// Legacy color mappings (mapped to HALEHOUND palette)
const uint16_t SHREDDY_TEAL = HALEHOUND_CYAN;       // Remap teal -> cyan
const uint16_t SHREDDY_PINK = HALEHOUND_MAGENTA;    // Remap pink -> magenta
const uint16_t SHREDDY_BLACK = HALEHOUND_BLACK;
const uint16_t SHREDDY_BLUE = HALEHOUND_CYAN;
const uint16_t SHREDDY_PURPLE = HALEHOUND_VIOLET;
const uint16_t SHREDDY_GREEN = HALEHOUND_GREEN;
const uint16_t SHREDDY_GUNMETAL = HALEHOUND_GUNMETAL;

const uint16_t ORANGE = HALEHOUND_MAGENTA;   // Use magenta instead of orange
const uint16_t GRAY = 0x8410;
const uint16_t BLUE = HALEHOUND_CYAN;
const uint16_t RED = 0xF800;
const uint16_t GREEN = HALEHOUND_GREEN;
const uint16_t BLACK = 0x0000;
const uint16_t WHITE = 0xFFFF;
const uint16_t LIGHT_GRAY = 0xC618;
const uint16_t DARK_GRAY = HALEHOUND_GUNMETAL;

#define TFT_DARKBLUE  0x3166
#define TFT_LIGHTBLUE HALEHOUND_CYAN
#define TFTWHITE     0xFFFF
#define TFT_GRAY      0x8410
#define SELECTED_ICON_COLOR HALEHOUND_MAGENTA

void displaySubmenu();

extern bool in_sub_menu;
extern bool feature_active;
extern bool submenu_initialized;
extern bool is_main_menu;
extern bool feature_exit_requested;


#endif // SHARED_H
