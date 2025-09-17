#[HARDWARE FEATURES]
NKRO_ENABLE					= yes
CONSOLE_ENABLE				= no	# (https://docs.qmk.fm/config_options)
VIA_ENABLE					= no 	# (https://docs.qmk.fm/config_options)
LTO_ENABLE 					= no 	# (https://docs.qmk.fm/config_options)

BOOTMAGIC_ENABLE			= yes	# (https://docs.qmk.fm/features/bootmagic)
RGBLIGHT_ENABLE				= yes	# (http://docs.qmk.fm/features/rgblight)
DIP_SWITCH_ENABLE			= no 	# (https://docs.qmk.fm/features/dip_switch)
ENCODER_ENABLE				= no	# (https://docs.qmk.fm/features/encoders)
ENCODER_MAP_ENABLE			= no	# (https://docs.qmk.fm/features/encoders)
STENO_ENABLE				= no 	# (https://docs.qmk.fm/features/stenography)

#[SOFTWARE FEATURES]
ENABLE_CHORDAL_HOLD			= yes
COMBO_ENABLE				= yes 	# (https://docs.qmk.fm/features/combo)
SEND_STRING_ENABLE			= yes 	# (https://docs.qmk.fm/features/send_string)
CAPS_WORD_ENABLE			= yes 	# (https://docs.qmk.fm/features/caps_word)
MOUSE_ENABLE				= yes
KEYCODE_STRING_ENABLE		= yes
DYNAMIC_TAPPING_TERM_ENABLE	= no	# (https://docs.qmk.fm/tap_hold)
DYNAMIC_KEYMAP_ENABLE		= no
KEY_OVERRIDE_ENABLE			= no 	# https://docs.qmk.fm/features/key_overrides
AUTOCORRECT_ENABLE			= no 	# (https://docs.qmk.fm/features/autocorrect)
AUTO_SHIFT_ENABLE			= no 	# (https://docs.qmk.fm/features/auto_shift)
TAP_DANCE_ENABLE			= no 	# (https://docs.qmk.fm/features/tap_dance)
TRI_LAYER_ENABLE			= no 	# (https://docs.qmk.fm/features/tri_layer)
KEY_LOCK_ENABLE				= no 	# (https://docs.qmk.fm/features/key_lock)

RAW_ENABLE					= yes 	# (https://docs.qmk.fm/features/rawhid)
SWAP_HANDS_ENABLE			= no 	# (https://docs.qmk.fm/features/swap_hands)
SECURE_ENABLE				= no 	# (https://docs.qmk.fm/features/secure)
OS_DETECTION_ENABLE			= no 	# (https://docs.qmk.fm/features/os_detection)

UNICODE_COMMON				= yes 	# (https://docs.qmk.fm/features/unicode)
UNICODE_ENABLE				= yes 	# (https://docs.qmk.fm/features/unicode)
UNICODEMAP_ENABLE			= no 	# (https://docs.qmk.fm/features/unicode)
UCIS_ENABLE					= no 	# (https://docs.qmk.fm/features/unicode)

DIGITIZER_ENABLE			= no 	# (https://docs.qmk.fm/features/digitizer)
SEQUENCER_ENABLE			= no 	# (https://docs.qmk.fm/features/sequencer)

#[ADVANCED KEYCODES]
LAYER_LOCK_ENABLE			= yes 	# (https://docs.qmk.fm/features/layer_lock)
REPEAT_KEY_ENABLE			= yes 	# (https://docs.qmk.fm/features/repeat_key)
EXTRAKEY_ENABLE				= yes 	# (https://docs.qmk.fm/config_options)
COMMAND_ENABLE				= no 	# (https://docs.qmk.fm/features/command)
MOUSEKEY_ENABLE				= no 	# (https://docs.qmk.fm/features/mouse_keys)
MAGIC_ENABLE				= no 	# (https://docs.qmk.fm/keycodes_magic)
GRAVE_ESC_ENABLE			= no 	# (https://docs.qmk.fm/features/grave_esc)
SPACE_CADET_ENABLE			= no 	# (https://docs.qmk.fm/features/space_cadet)
DYNAMIC_MACRO_ENABLE		= no 	# (https://docs.qmk.fm/features/dynamic_macros)
PROGRAMMABLE_BUTTON_ENABLE	= no 	# (https://docs.qmk.fm/features/programmable_button)
LEADER_ENABLE				= no 	# (https://docs.qmk.fm/features/leader_key)
MACROS_ENABLED				= no 	# (https://docs.qmk.fm/feature_macros)

SRC += ./src/tick_kleiner.c
SRC += ./src/features/caps_word.c
SRC += ./src/features/keycode_string.c
SRC += ./src/features/chordal_hold.c
SRC += ./src/features/repeat_key.c
SRC += ./src/features/tap_hold.c
SRC += ./src/utils/global_state.c

#[EXTRA FEATURES]
#[GETREUER]
CUSTOM_SHIFT_KEYS_ENABLE	= yes
SELECT_WORD_ENABLE			= yes
ORBITAL_MOUSE_ENABLE		= yes
SENTENCE_CASE_ENABLE		= no

ifeq ($(strip $(CUSTOM_SHIFT_KEYS_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_SHIFT_KEYS_ENABLE
endif

ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE
endif

ifeq ($(strip $(ORBITAL_MOUSE_ENABLE)), yes)
	OPT_DEFS += -DORBITAL_MOUSE_ENABLE
endif

ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
endif
