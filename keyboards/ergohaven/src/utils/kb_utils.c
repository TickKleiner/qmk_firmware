#include "kb_utils.h"

uint8_t get_current_layer(void) {
    return get_highest_layer(layer_state | default_layer_state);
}
bool    get_mac(void) {
    return false;
}
bool    get_caps_word(void) {
    return is_caps_word_on();
}
