#include QMK_KEYBOARD_H

#include "quantum.h"
#include "custom_shift_keys.h"

#include "layout.h"
#include "src/keycodes.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[EN] = LAYOUT_LR(
    SAVE      , CUT     , SEL_ALL , COPY    , PASTE   , UNDO    ,
    KC_TAB    , KC_V    , KC_M    , KC_L    , KC_C    , KC_P    ,
    KC_UNDS   , ALT_S   , SYM_T   , SFT_R   , NAV_D   , KC_Y    ,
    EXT_COL   , GUI_X   , MUS_K   , KC_J    , CTL_G   , KC_W    , KC_LPRN   ,
                          DF_EN   , CW_TOGG , KC_BSPC , KC_SPC  , KC_DEL    ,

                KC_HOME , KC_LEFT , KC_RGHT , KC_END  , EXP_TAB , KC_MPLY   ,
                KC_B    , MAGIC   , KC_U    , KC_O    , KC_Q    , KC_SLSH   ,
                KC_F    , NUM_N   , SFT_E   , SYM_A   , ALT_I   , KC_MINS   ,
    KC_RPRN   , KC_Z    , CTL_H   , KC_COMM , WIN_DOT , GUI_QUO , KC_EQL    ,
    KC_ENT    , QK_REP  , KC_ESC  , LT_WORD , DF_RU
),
[RU] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    _______   , RU_SHTI , RU_TSE  , RU_U    , RU_KA   , RU_IE   ,
    _______   , ALT_EF  , SYM_YRU , SFT_VE  , NAV_A   , RU_PE   ,
    _______   , GUI_YA  , MUS_CH  , RU_ES   , CTL_EM  , RU_I    , RU_HA     ,
                          _______ , _______ , _______ , _______ , _______   ,

                _______ , _______ , _______ , _______ , _______ , _______   ,
                RU_EN   , RU_GHE  , RU_SHA  , RU_SHCH , RU_ZE   , _______   ,
                RU_ER   , NUM_O   , SFT_EL  , SYM_DE  , ALT_ZHE , _______   ,
    RU_HARD   , RU_TE   , CTL_SFT , RU_BE   , WIN_YU  , GUI_E   , _______   ,
    _______   , _______ , _______ , _______ , _______
),
[SYM] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX   , KC_GRV  , KC_LABK , KC_RABK , KC_MINS , KC_PIPE ,
    XXXXXXX   , KC_EXLM , KC_ASTR , NAV_SLS , NAV_EQL , KC_AMPR ,
    XXXXXXX   , KC_TILD , KC_PLUS , KC_LBRC , KC_RBRC , KC_PERC , XXXXXXX ,
                          _______ , XXXXXXX , _______ , _______ , _______ ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                KC_QUES , KC_LCBR , KC_RCBR , KC_DLR  , KC_CIRC , XXXXXXX ,
                KC_HASH , KC_LPRN , KC_RPRN , KC_SCLN , KC_DQUO , XXXXXXX ,
    XXXXXXX   , KC_AT   , KC_COLN , KC_COMM , KC_DOT  , KC_QUOT , XXXXXXX ,
    _______   , _______ , _______ , XXXXXXX , _______
),
[NAV] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX   , G(KC_B) , G(KC_A) , G(KC_X) , XXXXXXX , XXXXXXX ,
    KC_WREF   , KC_LALT , KC_LCTL , KC_LSFT , _______ , XXXXXXX ,
    XXXXXXX   , KC_LGUI , PRV_TAB , NXT_TAB , XXXXXXX , XXXXXXX , XXXXXXX ,
                          _______ , XXXXXXX , KC_WBAK , _______ , _______ ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                KC_PGUP , KC_HOME , KC_UP   , KC_END  , SRCHSEL , XXXXXXX ,
                KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , REP_SEL , XXXXXXX ,
    XXXXXXX   , KC_APP  , SELWBAK , SELLINE , SELWORD , G(KC_T) , XXXXXXX ,
    _______   , C(KC_T) , _______ , QK_LLCK , _______
),
[NUM] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX   , KC_SLSH , KC_9    , KC_8    , KC_7    , KC_ASTR ,
    XXXXXXX   , KC_MINS , KC_3    , KC_2    , KC_1    , KC_PLUS ,
    XXXXXXX   , KC_X    , KC_6    , KC_5    , KC_4    , KC_PERC , XXXXXXX ,
                          _______ , XXXXXXX , _______ , _______ , _______ ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                XXXXXXX , XXXXXXX , KC_CALC , XXXXXXX , XXXXXXX , XXXXXXX ,
                XXXXXXX , _______ , KC_E    , KC_RCTL , KC_LALT , XXXXXXX ,
    XXXXXXX   , XXXXXXX , XXXXXXX , KC_COMM , KC_DOT  , KC_LGUI , XXXXXXX ,
    _______   , KC_0    , _______ , QK_LLCK , _______
),
[WIN] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX   , XXXXXXX , MUTEMIC , KC_VOLD , KC_VOLU , KC_MUTE ,
    XXXXXXX   , XXXXXXX , G(KC_3) , G(KC_2) , G(KC_1) , NEW_DKP ,
    XXXXXXX   , XXXXXXX , G(KC_6) , G(KC_5) , G(KC_4) , CLS_DKP , XXXXXXX ,
                          _______ , XXXXXXX , G(KC_S) , _______ , _______ ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                XXXXXXX , PRV_DKP , NXT_DKP , XXXXXXX , XXXXXXX , XXXXXXX ,
                XXXXXXX , WIN_LFT , KC_LSFT , XXXXXXX , KC_LALT , XXXXXXX ,
    XXXXXXX   , XXXXXXX , BWD_TAB , FWD_TAB , _______ , XXXXXXX , XXXXXXX ,
    _______   , G(KC_D) , _______ , QK_LLCK , _______
),
[MUS] = LAYOUT_LR(
    XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX   , XXXXXXX , XXXXXXX , MS_BTN4 , MS_BTN5 , XXXXXXX ,
    XXXXXXX   , L_ACTL  , XXXXXXX , MS_BTN1 , MS_BTN2 , MS_BTN3 ,
    XXXXXXX   , L_SCTL  , _______ , NLK_HLD , SLK_HLD  , XXXXXXX , XXXXXXX ,
                          _______ , XXXXXXX , KC_LALT , KC_LCTL , KC_LSFT ,

                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  ,
    XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX   , XXXXXXX , XXXXXXX , QK_LLCK , _______
),
[EXT] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX   , SAVE    , CUT     , SEL_ALL , XXXXXXX , XXXXXXX ,
    KC_WBAK   , KC_LALT , KC_LCTL , KC_LSFT , SELLINE , XXXXXXX ,
    _______   , KC_LGUI , COPY    , PASTE   , UNDO    , XXXXXXX , XXXXXXX ,
                          _______ , XXXXXXX , MS_ACL0 , _______ , _______ ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                MS_WHLU , MS_WHLL , MS_UP   , MS_WHLR , SRCHSEL , KC_PSCR ,
                MS_WHLD , MS_LEFT , MS_DOWN , MS_RGHT , MS_ACL0 , FST_MS  ,
    XXXXXXX   , MS_BTN4 , MS_BTN1 , MS_BTN3 , MS_BTN2 , MS_BTN5 , XXXXXXX ,
    _______   , MS_BTN1 , _______ , QK_LLCK , _______
),
[FUN] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX   , KC_F12  , KC_F9   , KC_F8   , KC_F7   , OPTS    ,
    XXXXXXX   , KC_F10  , KC_F3   , KC_F2   , KC_F1   , EXPLR   ,
    XXXXXXX   , KC_F11  , KC_F6   , KC_F5   , KC_F4   , KC_MYCM , XXXXXXX ,
                          XXXXXXX , XXXXXXX , XXXXXXX , TKMGR   , XXXXXXX ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                OSL_MAG , XXXXXXX , KC_WHOM , XXXXXXX , XXXXXXX , XXXXXXX ,
                KC_NO   , XXXXXXX , KC_LCTL , KC_LSFT , KC_LALT , XXXXXXX ,
    XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX ,
    XXXXXXX   , CLOSE   , XXXXXXX , QK_LLCK , XXXXXXX
),
[MAG] = LAYOUT_LR(
    _______   , _______ , _______ , _______ , _______ , _______ ,
    QK_BOOT   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    QK_RBT    , TO_NUM  , TO_NAV  , TO_SYM  , TO_MUS  , TO_EXT  ,
    DB_TOGG   , TO_FUN  , TO_WIN  , TO_GAM  , TO_FAC  , XXXXXXX , XXXXXXX ,
                          DF_EN   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,

                _______ , _______ , _______ , _______ , _______ , _______ ,
                KC_NO   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX   , LOCK    , KC_SLEP , XXXXXXX , XXXXXXX , XXXXXXX , KC_PWR  ,
    XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX , DF_RU
),
[GAM] = LAYOUT_LR(
    KC_GRV    , KC_1    , KC_2    , KC_3	, KC_4	  , KC_5    ,
    KC_T      , KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    ,
    KC_G      , KC_LSFT , KC_A    , KC_S    , KC_D    , KC_F    ,
    KC_B      , KC_LCTL , KC_Z    , KC_X    , KC_C    , KC_V    , KC_ENT  ,
                          KC_DEL  , KC_BSPC , KC_LCTL , KC_SPC  , KC_LSFT ,

                KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , TG_GAM  ,
                KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
                KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_UP     , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_MINS ,
    KC_LEFT   , KC_DOWN , KC_RGHT , KC_LALT , KC_LGUI
),
[FAC] = LAYOUT_LR(
    KC_GRV    , KC_1    , KC_2    , KC_3	, KC_4	  , KC_5    ,
    KC_ESC    , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,
    KC_TAB    , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,
    KC_LSFT   , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_LBRC ,
                          KC_LGUI , KC_LALT , KC_LCTL , KC_BSPC , KC_SPC  ,

                KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , TG_FAC  ,
                KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
                KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
    KC_RBRC   , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
    KC_ENT    , KC_DEL  , KC_RCTL , KC_RALT , KC_RGUI
),
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
#ifdef COMBO_ENABLE
const uint16_t H_CM_COMBO[]     PROGMEM = { CTL_H,      KC_COMM,    COMBO_END };
const uint16_t F_N_COMBO[]      PROGMEM = { KC_F,       NUM_N,      COMBO_END };
const uint16_t RU_H_CM_COMBO[]  PROGMEM = { CTL_SFT,    RU_BE,      COMBO_END };
const uint16_t RU_YO_COMBO[]    PROGMEM = { RU_KA,      RU_IE,      COMBO_END};
// clang-format off
combo_t key_combos[] = {
    COMBO(H_CM_COMBO,       KC_QUOT),   // 0: H   and ,  => '
    COMBO(F_N_COMBO,        OSL(FUN)),  // 1: F   and N  => FUN layer
    COMBO(RU_YO_COMBO,      RU_YO),     // 2:
    COMBO(RU_H_CM_COMBO,    KC_QUOT),   // 3: ER  and O  => '
};
// clang-format on
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case 0:
        case 1:
            if (!layer_state_is(EN)) {
                return false;
            }
            break;
        case 2:
        case 3:
            if (!layer_state_is(RU)) {
                return false;
            }
            break;
        default:
            break;
    }
    return true;
}
#endif //*COMBO_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Custom shift keys (https://getreuer.info/posts/keyboards/custom-shift-keys)
///////////////////////////////////////////////////////////////////////////////
#ifdef CUSTOM_SHIFT_KEYS_ENABLE
const custom_shift_key_t custom_shift_keys[] = {
    {WIN_DOT, KC_QUES}, /* .    -> ?    */
    {KC_COMM, KC_EXLM}, /* ,    -> !    */
    {KC_MINS, KC_SCLN}, /* -    -> ;    */
    {KC_SLSH, KC_BSLS}, /* /    -> \    */
    {KC_LPRN, KC_LCBR}, /* (    -> {    */
    {KC_RPRN, KC_RCBR}, /* )    -> }    */
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
#endif //*CUSTOM_SHIFT_KEYS_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Handedness for Chordal Hold (https://github.com/qmk/qmk_firmware/pull/24560)
///////////////////////////////////////////////////////////////////////////////
#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_LR(
    '*', '*', '*', '*', '*', '*',
    'L', 'L', 'L', 'L', 'L', 'L',
    'L', 'L', 'L', 'L', 'L', 'L',
    'L', 'L', 'L', 'L', 'L', 'L', 'L',
              '*', '*', '*', '*', '*',

         '*', '*', '*', '*', '*', '*',
         'R', 'R', 'R', 'R', 'R', 'R',
         'R', 'R', 'R', 'R', 'R', 'R',
    'R', 'R', 'R', 'R', 'R', 'R', 'R',
    '*', '*', '*', '*', '*'
);
#endif //*CHORDAL_HOLD
