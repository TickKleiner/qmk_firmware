MCU						= RP2040
BOARD					= GENERIC_RP_RP2040
BOOTLOADER				= rp2040
OLED_ENABLE				= yes
OLED_DRIVER				= ssd1306
SERIAL_DRIVER			= vendor

SPLIT_KEYBOARD			= yes

# Build options
BOOTMAGIC_ENABLE		= yes
RGBLIGHT_ENABLE			= yes
RAW_ENABLE				= yes
NKRO_ENABLE				?= yes
WPM_ENABLE				?= yes
NO_USB_STARTUP_CHECK	?= no
CONSOLE_ENABLE			?= no
LTO_ENABLE 				?= no

SRC += keyboards/ergohaven/src/ergohaven.c
SRC += keyboards/ergohaven/src/oled/oled.c
SRC += keyboards/ergohaven/src/hid/hid.c
SRC += keyboards/ergohaven/src/rgb/rgb.c
SRC += oled/dark.c
