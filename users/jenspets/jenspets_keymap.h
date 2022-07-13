#pragma once

#ifndef SWAP_HANDS_ENABLE
#ifdef SH_T
#undef SH_T
#endif
#define SH_T(kc) kc
#endif

#ifndef AUDIO_ENABLE
#undef MU_MOD
#undef AU_ON
#undef AU_OFF
#undef MUV_DE
#undef MUV_IN
#undef MU_ON
#undef MU_OFF
#undef MI_ON
#undef MI_OFF
#define MU_MOD KC_NO
#define AU_ON KC_NO
#define AU_OFF KC_NO
#define MUV_DE KC_NO
#define MUV_IN KC_NO
#define MU_ON KC_NO
#define MU_OFF KC_NO
#define MI_ON KC_NO
#define MI_OFF KC_NO
#endif

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _SYMBOLS,
    _LOWER,
    _RAISE,
#ifdef USE_PLOVER
    _PLOVER,
#endif
    _ADJUST,
    _NAV,
    _NUM
};

#define BASE_R2_L RALT_T(KC_Q), KC_W, KC_F, KC_P, KC_B
#define BASE_R2_R KC_J, KC_L, KC_U, KC_Y, RALT_T(KC_SCLN)
#define BASE_R3_L LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G
#define BASE_R3_R KC_M, RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)
#define BASE_R4_L LT(_NAV, KC_Z), KC_X, KC_C, KC_D, KC_V
#define BASE_R4_R KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH
#define BASE_T_L  LT(_LOWER, KC_TAB), SH_T(KC_SPC)
#define BASE_T_R  KC_BSPC, LT(_RAISE, KC_ESC)

#define LOW_R2_L KC_GRV, KC_AT, KC_LCBR, KC_RCBR, KC_PERC
#define LOW_R2_R KC_CIRC, KC_AMPR, KC_PIPE, KC_BSLS, KC_TILD
#define LOW_R3_L KC_ESC, KC_EXLM, KC_LPRN, KC_RPRN, KC_QUOT
#define LOW_R3_R KC_ASTR, KC_MINS, KC_EQL, KC_NUHS, LSFT(KC_NUHS)
#define LOW_R4_L KC_CAPS, KC_DLR, KC_LBRC, KC_RBRC, LSFT(KC_QUOT)
#define LOW_R4_R KC_HASH, KC_UNDS, KC_PLUS, KC_NUBS, LSFT(KC_NUBS)
#define LOW_T_L  KC_TRNS, KC_TRNS
#define LOW_T_R  KC_TRNS, MO(_ADJUST)

#define RSE_R2_L KC_1, KC_2, KC_3, KC_4, KC_5
#define RSE_R2_R KC_6, KC_7, KC_8, KC_9, KC_0
#define RSE_R3_L KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RSE_R3_R KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC
#define RSE_R4_L KC_F7, KC_F8, KC_F9, KC_F10, KC_F11
#define RSE_R4_R KC_F12, TG(_NAV), TG(_NUM), KC_PGUP, KC_PGDN
#define RSE_T_L  MO(_ADJUST), KC_ENT
#define RSE_T_R  KC_DEL, KC_TRNS

#define ADJ_R2_L RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI
#define ADJ_R2_R RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD
#define ADJ_R3_L KC_TRNS, MU_MOD, AU_ON, AU_OFF, LAG_NRM
#ifdef USE_PLOVER
#define ADJ_R3_R LAG_SWP, DF(_QWERTY), DF(_COLEMAK), TO(_PLOVER), KC_TRNS
#else
#define ADJ_R3_R LAG_SWP, DF(_QWERTY), DF(_COLEMAK), KC_TRNS, KC_TRNS
#endif
#define ADJ_R4_L MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON
#define ADJ_R4_R MI_OFF, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS
#define ADJ_T_L  KC_TRNS, KC_PSCR
#define ADJ_T_R  KC_INS, KC_TRNS

#define NAV_R2_L KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define NAV_R2_R KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5
#define NAV_R3_L KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define NAV_R3_R KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define NAV_R4_L KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI
#define NAV_R4_R KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
#define NAV_T_L  KC_TRNS, KC_SPC
#define NAV_T_R  KC_TRNS, TG(_NAV)

#define NUM_R2_L KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP
#define NUM_R2_R KC_NLCK, KC_P7, KC_P8, KC_P9, KC_PENT
#define NUM_R3_L KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define NUM_R3_R KC_NO, KC_TAB, KC_P4, KC_P5, KC_P6, KC_TAB
#define NUM_R4_L KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define NUM_R4_R KC_P0, KC_P1, KC_P2, KC_P3, KC_DEL
#define NUM_T_L  KC_NO, KC_SPC
#define NUM_T_R  KC_BSPC, TG(_NUM)
