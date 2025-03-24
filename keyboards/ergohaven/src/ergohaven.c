#include QMK_KEYBOARD_H
#include "version.h"

#include "keycodes.h"
#include "oled/oled.h"
#include "rgb/rgb.h"
#include "hid/hid.h"

// #include "print.h"

bool process_record_ergohaven_kb(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case EH_PRINFO:
                SEND_STRING("FW version: " QMK_VERSION "\n");
                SEND_STRING("Build date: " QMK_BUILDDATE "\n");
                SEND_STRING("Git hash: " QMK_GIT_HASH "\n");
#ifdef UNICODE_COMMON_ENABLE
                SEND_STRING("Unicode mode: ");
                switch (get_unicode_input_mode()) {
                    case UNICODE_MODE_MACOS:
                        SEND_STRING("Mac\n");
                        break;
                    case UNICODE_MODE_LINUX:
                        SEND_STRING("Linux\n");
                        break;
                    case UNICODE_MODE_WINDOWS:
                        SEND_STRING("Windows\n");
                        break;
                    case UNICODE_MODE_WINCOMPOSE:
                        SEND_STRING("WinCompose\n");
                        break;
                    default:
                        SEND_STRING("error\n");
                        break;
                }
#endif
            return false;
        default:
            break;
    }
    return true;
}

void keyboard_post_init_kb(void) {
    // uprint("[START]keyboard_post_init_kb\n");
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
#ifdef RGBLIGHT_ENABLE
    keyboard_post_init_rgb();
#endif  // RGBLIGHT_ENABLE
    keyboard_post_init_hid();
#ifdef OLED_ENABLE
    keyboard_post_init_oled_kb();
#endif  // OLED_ENABLE
    keyboard_post_init_user();
    // uprint("[END]keyboard_post_init_kb\n");
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    // uprint("[START]process_record_kb\n");
    switch (keycode) {
        case KC_CAPS:
#ifdef AUDIO_ENABLE
            if (record->event.pressed) {
                PLAY_SONG(caps_sound);
            }
#endif
            break;
        default:
            break;
    }
    return process_record_ergohaven_kb(keycode, record)
        && process_record_user(keycode, record);
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
    // uprint("[START]default_layer_state_set_kb\n");
    state = default_layer_state_set_user(state);
#ifdef RGBLIGHT_ENABLE
    layer_state_set_rgb(layer_state | state);
#endif
    // uprint("[END]default_layer_state_set_kb\n");
    return state;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    // uprint("[START]layer_state_set_kb\n");
    state = layer_state_set_user(state);
#ifdef RGBLIGHT_ENABLE
    layer_state_set_rgb(state | default_layer_state);
#endif
    // uprint("[END]layer_state_set_kb\n");
    return state;
}

void housekeeping_task_kb(void) {
#ifdef RGBLIGHT_ENABLE
    housekeeping_task_rgb();
#endif
#if defined(OLED_ENABLE) && defined(SPLIT_KEYBOARD)
    housekeeping_task_split_oled();
#endif
}

void suspend_wakeup_init_kb(void) {
    // uprint("[START]suspend_wakeup_init_kb\n");
#ifdef EH_HAS_DISPLAY
    display_turn_on();
#endif
#ifdef RGBLIGHT_ENABLE
    rgb_on();
#endif
#ifdef OLED_ENABLE
    oled_on();
#endif
    suspend_wakeup_init_user();
    // uprint("[END]suspend_wakeup_init_kb\n");
}

void suspend_power_down_kb(void) {
    // uprint("[START]suspend_power_down_kb\n");
#ifdef EH_HAS_DISPLAY
    display_turn_off();
#endif
#ifdef RGBLIGHT_ENABLE
    rgb_off();
#endif
#ifdef OLED_ENABLE
    oled_off();
#endif
    suspend_power_down_user();
    // uprint("[END]suspend_power_down_kb\n");
}

// bool pre_process_record_kb(uint16_t keycode, keyrecord_t *record) {
//     uprint("[START]pre_process_record_kb\n");
//     return pre_process_record_user(keycode, record);
// }
