#include "kc_state.h"
#include "kb_utils.h"
#include "layout.h"

bool get_tap_code(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode)) keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    if (IS_QK_LAYER_TAP(keycode)) keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    return keycode;
}
bool is_src_layer_mask(keyrecord_t *record, layer_mask_t lm) {
    return lm & (0b0000000000000001 << read_source_layers_cache(record->event.key));
}
bool is_mod_t(mods_type_t mt) {
    return ((mt & MT_DEFAULT) && get_mods()               )
        || ((mt & MT_WEAK   ) && get_weak_mods()          )
#ifndef NO_ACTION_ONESHOT
        || ((mt & MT_ONESHOT) && get_oneshot_mods()       )
#endif  // NO_ACTION_ONESHOT
    ;
}
bool is_mod_kc(mods_type_t mt, mod_key_t mk) {
    return ((mt & MT_DEFAULT) && (mk & get_mods())        )
        || ((mt & MT_WEAK   ) && (mk & get_weak_mods())   )
#ifndef NO_ACTION_ONESHOT
        || ((mt & MT_ONESHOT) && (mk & get_oneshot_mods()))
#endif  // NO_ACTION_ONESHOT
    ;
}
bool is_mod_cnd(mods_type_t mt, mod_key_t mk, condition_type_t ct) {
    return  ((ct & CT_ONLY)
            && (((mt & MT_DEFAULT) && (mk == get_mods())         )
            ||  ((mt & MT_WEAK   ) && (mk == get_weak_mods())    )
#ifndef NO_ACTION_ONESHOT
            ||  ((mt & MT_ONESHOT) && (mk == get_oneshot_mods()) )
#endif  // NO_ACTION_ONESHOT
        ))||((ct & CT_ACTIVE)
            && (((mt & MT_DEFAULT) && (mk & get_mods())          )
            ||  ((mt & MT_WEAK   ) && (mk & get_weak_mods())     )
#ifndef NO_ACTION_ONESHOT
            ||  ((mt & MT_ONESHOT) && (mk & get_oneshot_mods())  )
#endif  // NO_ACTION_ONESHOT
        ))||((ct & CT_MASK)
            && (((mt & MT_DEFAULT) && !(~mk & get_mods())        )
            ||  ((mt & MT_WEAK   ) && !(~mk & get_weak_mods())   )
#ifndef NO_ACTION_ONESHOT
            ||  ((mt & MT_ONESHOT) && !(~mk & get_oneshot_mods()))
#endif  // NO_ACTION_ONESHOT
        ));
}

bool is_hrs(keyrecord_t *record, home_row_side_t hrs) {
    return ((record->event.key.row == LEFT_HOME_ROW)  && (hrs & HRS_LEFT) )
        || ((record->event.key.row == RIGHT_HOME_ROW) && (hrs & HRS_RIGHT));
}
bool is_hrf(keyrecord_t *record, home_row_finger_t hrf) {
    return ((record->event.key.col == PINKY_COL)  && (hrf & HRF_PINKY) )
        || ((record->event.key.col == RING_COL)   && (hrf & HRF_RING)  )
        || ((record->event.key.col == MIDDLE_COL) && (hrf & HRF_MIDDLE))
        || ((record->event.key.col == INDEX_COL)  && (hrf & HRF_INDEX) );
}
bool is_hr(keyrecord_t *record, home_row_side_t hrs, home_row_finger_t hrf) {
    return is_hrs(record, hrs) && is_hrf(record, hrf);
}

static uint8_t mods     = 0;
static uint8_t weak     = 0;
#ifndef NO_ACTION_ONESHOT
static uint8_t oneshot  = 0;
#endif  // NO_ACTION_ONESHOT
void        store_all_mods(void) {
    mods = get_mods();
    weak = get_weak_mods();
#ifndef NO_ACTION_ONESHOT
    oneshot = get_oneshot_mods();
#endif  // NO_ACTION_ONESHOT
}
void        clear_all_mods(void) {
    clear_mods();
    clear_weak_mods();
#ifndef NO_ACTION_ONESHOT
    clear_oneshot_mods();
#endif  // NO_ACTION_ONESHOT
}
void        restore_all_mods(void) {
    set_mods(mods);
    set_weak_mods(weak);
#ifndef NO_ACTION_ONESHOT
    set_oneshot_mods(oneshot);
#endif  // NO_ACTION_ONESHOT
}
