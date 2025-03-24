#pragma once
#include "quantum.h"

typedef enum {
    OLED_STATUS_CLASSIC = 0,
    OLED_SPLASH,
    OLED_STATUS_MODERN,
    OLED_STATUS_MINIMALISTIC,
    OLED_BONGOCAT,
    OLED_MEDIA_VER,
    OLED_MEDIA_HOR,
    OLED_DISABLED,
} oled_mode_t;

typedef union {
    uint32_t raw;
    struct {
        uint8_t slave : 3;
        uint8_t master : 3;
        bool    right_encoder : 1;
        bool    left_encoder : 1;
        uint8_t lang : 1;
        bool    mac : 1;
        bool    caps_word : 1;
    };
} oled_config_t;

void housekeeping_task_split_oled(void);
void keyboard_post_init_oled_kb(void);
