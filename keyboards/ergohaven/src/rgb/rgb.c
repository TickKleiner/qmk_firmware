#include "rgb.h"

#define INDICATOR_BRIGHTNESS 30

#define HSV_HELPER(h, s, v) h, s, INDICATOR_BRIGHTNESS
#define SEG_COLOR(COLOR) RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_HELPER(COLOR)})
#define RGB_SEG static const rgblight_segment_t
#define RGB_LIST static const rgblight_segment_t *const
#define LAYER_NAME(LAYER) l_ ## LAYER ## _rgb

// clang-format off
RGB_SEG  PROGMEM LAYER_NAME(0)  [] = SEG_COLOR(HSV_WHITE);
RGB_SEG  PROGMEM LAYER_NAME(1)  [] = SEG_COLOR(HSV_WHITE);
RGB_SEG  PROGMEM LAYER_NAME(2)  [] = SEG_COLOR(HSV_CYAN);
RGB_SEG  PROGMEM LAYER_NAME(3)  [] = SEG_COLOR(HSV_GOLDENROD);
RGB_SEG  PROGMEM LAYER_NAME(4)  [] = SEG_COLOR(HSV_GREEN);
RGB_SEG  PROGMEM LAYER_NAME(5)  [] = SEG_COLOR(HSV_PURPLE);
RGB_SEG  PROGMEM LAYER_NAME(6)  [] = SEG_COLOR(HSV_BLUE);
RGB_SEG  PROGMEM LAYER_NAME(7)  [] = SEG_COLOR(HSV_PINK);
RGB_SEG  PROGMEM LAYER_NAME(8)  [] = SEG_COLOR(HSV_SPRINGGREEN);
RGB_SEG  PROGMEM LAYER_NAME(9)  [] = SEG_COLOR(HSV_YELLOW);
RGB_SEG  PROGMEM LAYER_NAME(10) [] = SEG_COLOR(HSV_TEAL);
RGB_SEG  PROGMEM LAYER_NAME(11) [] = SEG_COLOR(HSV_ORANGE);
RGB_SEG  PROGMEM LAYER_NAME(12) [] = SEG_COLOR(HSV_AZURE);
RGB_SEG  PROGMEM LAYER_NAME(13) [] = SEG_COLOR(HSV_CHARTREUSE);
RGB_SEG  PROGMEM LAYER_NAME(14) [] = SEG_COLOR(HSV_CORAL);
RGB_SEG  PROGMEM LAYER_NAME(15) [] = SEG_COLOR(HSV_GOLD);
RGB_LIST PROGMEM USER_RGB_LAYERS[] = RGBLIGHT_LAYERS_LIST(
    LAYER_NAME(0),
    LAYER_NAME(1),
    LAYER_NAME(2),
    LAYER_NAME(3),
    LAYER_NAME(4),
    LAYER_NAME(5),
    LAYER_NAME(6),
    LAYER_NAME(7),
    LAYER_NAME(8),
    LAYER_NAME(9),
    LAYER_NAME(10),
    LAYER_NAME(11),
    LAYER_NAME(12),
    LAYER_NAME(13),
    LAYER_NAME(14),
    LAYER_NAME(15)
);
// clang-format on
static const uint8_t LAYERS_COUNT = sizeof(USER_RGB_LAYERS) / sizeof(USER_RGB_LAYERS[0]);

static bool is_rgb_on = false;

void rgb_on(void) {
    if (!is_rgb_on) rgblight_wakeup();
    is_rgb_on = true;
}
void rgb_off(void) {
    if (is_rgb_on) rgblight_suspend();
    is_rgb_on = false;
}
void layer_state_set_rgb(layer_state_t state) {
    for (int layer = 0; layer < LAYERS_COUNT; ++layer)
        rgblight_set_layer_state(layer, layer_state_cmp(state, layer));
}
void keyboard_post_init_rgb(void) {
    rgblight_layers = USER_RGB_LAYERS;
}
void housekeeping_task_rgb(void) {
    if (last_input_activity_elapsed() > EH_TIMEOUT) {
        rgb_off();
    } else {
        rgb_on();
    }
}
