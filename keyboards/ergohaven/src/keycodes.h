#pragma once
#include "quantum.h"

#define PREVWRD   LCTL(KC_LEFT)
#define NEXTWRD   LCTL(KC_RIGHT)
#define CTRLUP    LCTL(KC_UP)
#define CTRLDN    LCTL(KC_DOWN)
#define LANG      LALT(KC_LSFT)

#define CT_Q      LCTL_T(KC_Q)
#define CT_CM     RCTL_T(KC_COMM)
#define SF_Z      LSFT_T(KC_Z)
#define SF_SS     RSFT_T(KC_SLSH)
#define AL_X      LALT_T(KC_X)
#define AL_DT     RALT_T(KC_DOT)
#define LO_TB     LT(LOWER, KC_TAB)

#define APP_A     LSG(KC_A)
#define APP_S     LSG(KC_S)
#define APP_D     LSG(KC_D)
#define APP_F     LSG(KC_F)
#define APP_G     LSG(KC_G)
#define APP_X     LSG(KC_X)
#define APP_C     LSG(KC_C)
#define APP_V     LSG(KC_V)
#define APP_B     LSG(KC_B)

enum ergohaven_custom_keycodes {
    EH_START    = QK_KB,
    EH_PRINFO   = EH_START,
    EH_RESERV1,
    EH_END      = QK_KB_MAX,
};
