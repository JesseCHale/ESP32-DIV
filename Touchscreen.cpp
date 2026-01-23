#include "Touchscreen.h"

// Use HSPI to avoid conflict with NRF24/CC1101 which use VSPI
SPIClass touchscreenSPI = SPIClass(HSPI); 
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ); 
bool feature_active = false; 

void setupTouchscreen() {
    // End first to force GPIO matrix reconfiguration (releases any existing HSPI mapping)
    touchscreenSPI.end();
    delay(5);
    // Reinitialize HSPI with touch pins
    touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
    ts.begin(touchscreenSPI);
    ts.setRotation(0);
}
