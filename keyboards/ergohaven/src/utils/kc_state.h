#pragma once
#include "quantum.h"

typedef enum home_row_side {
    HRS_NONE,
    /* LEFT HOME ROW */
    HRS_LEFT    = 0b00000001,
    /* RIGHT HOME ROW */
    HRS_RIGHT   = 0b00000010,
    HRS_ANY     = HRS_LEFT | HRS_RIGHT,
} home_row_side_t;

typedef enum home_row_finger {
    HRF_NONE,
    /* PINKY FINGER COLUMN */
    HRF_PINKY   = 0b00000001,
    /* RING FINGER COLUMN */
    HRF_RING    = 0b00000010,
    /* MIDDLE FINGER COLUMN */
    HRF_MIDDLE  = 0b00000100,
    /* INDEX FINGER COLUMN */
    HRF_INDEX   = 0b00001000,
    HRF_ANY     = HRF_PINKY | HRF_RING | HRF_MIDDLE | HRF_INDEX,
} home_row_finger_t;

typedef enum mods_type {
    MT_NONE,
    /* DEFAULT MODS */
    MT_DEFAULT  = 0b00000001,
    /* WEAK MODS */
    MT_WEAK     = 0b00000010,
#ifndef NO_ACTION_ONESHOT
    /* ONESHOT MODS */
    MT_ONESHOT  = 0b00000100,
#endif  // NO_ACTION_ONESHOT
    MT_ANY      = MT_DEFAULT | MT_WEAK
#ifndef NO_ACTION_ONESHOT
    | MT_ONESHOT
#endif  // NO_ACTION_ONESHOT
} mods_type_t;

typedef enum mod_key {
    MK_NONE,
    MK_LCTRL    = MOD_BIT_LCTRL,
    MK_LSHIFT   = MOD_BIT_LSHIFT,
    MK_LALT     = MOD_BIT_LALT,
    MK_LGUI     = MOD_BIT_LGUI,
    MK_RCTRL    = MOD_BIT_RCTRL,
    MK_RSHIFT   = MOD_BIT_RSHIFT,
    MK_RALT     = MOD_BIT_RALT,
    MK_RGUI     = MOD_BIT_RGUI,
    MK_CTRL     = MOD_MASK_CTRL,
    MK_SHIFT    = MOD_MASK_SHIFT,
    MK_CS       = MOD_MASK_CS,
    MK_ALT      = MOD_MASK_ALT,
    MK_CA       = MOD_MASK_CA,
    MK_SA       = MOD_MASK_SA,
    MK_CSA      = MOD_MASK_CSA,
    MK_GUI      = MOD_MASK_GUI,
    MK_CG       = MOD_MASK_CG,
    MK_SG       = MOD_MASK_SG,
    MK_AG       = MOD_MASK_AG,
    MK_CSG      = MOD_MASK_CSG,
    MK_CAG      = MOD_MASK_CAG,
    MK_SAG      = MOD_MASK_SAG,
    MK_CSAG     = MOD_MASK_CSAG,
} mod_key_t;

typedef enum condition_type {
    CT_NONE,
    CT_ONLY     = 0b00000001,
    CT_ACTIVE   = 0b00000010,
    CT_MASK     = 0b00000100,
    CT_ANY      = CT_MASK | CT_ACTIVE | CT_ONLY,
} condition_type_t;

#define LAYER_MASK(LAYER) 0b0000000000000001 << LAYER;
typedef enum layer_mask {
    LM_NONE,
    LM_BASE     = 0b0000000000000001,
    LM_LOWER    = 0b0000000000000010,
    LM_RAISE    = 0b0000000000000100,
    LM_ADJUST   = 0b0000000000001000,
    LM_FOUR     = 0b0000000000010000,
    LM_FIVE     = 0b0000000000100000,
    LM_SIX      = 0b0000000001000000,
    LM_SEVEN    = 0b0000000010000000,
    LM_EIGHT    = 0b0000000100000000,
    LM_NINE     = 0b0000001000000000,
    LM_TEN      = 0b0000010000000000,
    LM_ELEVEN   = 0b0000100000000000,
    LM_TWELVE   = 0b0001000000000000,
    LM_THIRTEEN = 0b0010000000000000,
    LM_FOURTEEN = 0b0100000000000000,
    LM_FIFTEEN  = 0b1000000000000000,
    LM_ALL      = 0b1111111111111111,
} layer_mask_t;

void                store_all_mods(void);
void                clear_all_mods(void);
void                restore_all_mods(void);

bool                get_tap_code(uint16_t keycode);

bool                is_src_layer_mask(keyrecord_t *record, layer_mask_t lm);
bool                is_mod_t(mods_type_t mt);
bool                is_mod_kc(mods_type_t mt, mod_key_t mk);
bool                is_mod_cnd(mods_type_t mt, mod_key_t mk, condition_type_t ct);
bool                is_hrs(keyrecord_t *record, home_row_side_t hrs);
bool                is_hrf(keyrecord_t *record, home_row_finger_t hrf);
bool                is_hr(keyrecord_t *record, home_row_side_t hrs, home_row_finger_t hrf);
