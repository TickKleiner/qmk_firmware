
// Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
// Specify a optional status led which blinks when entering the bootloader
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

#define DEBOUNCE 5
// wait for USB hub to start
#define USB_SUSPEND_WAKEUP_DELAY 2000

#define OLED_FONT_H "src/oled/font.c"
#define OLED_TIMEOUT 0
#define EH_TIMEOUT (10 * 60 * 1000) // 10 minutes
