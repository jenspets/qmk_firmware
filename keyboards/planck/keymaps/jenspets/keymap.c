/* -*- c-file-style: "qmk" -*- */
#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

/* Navigation and number pad layers */
//#define L_NAV 7
//#define L_NUM 8

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _PLOVER,
    _ADJUST,
    _NAV,
    _NUM
};

#ifdef SWAP_HANDS_ENABLE
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_RALT,
				   LCTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
				   LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
				   TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, MO(_LOWER), SH_T(KC_SPC), KC_BSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [_QWERTY] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RALT,
				  LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
				  LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
				  TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, MO(_LOWER), SH_T(KC_SPC), KC_BSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [_DVORAK] = LAYOUT_ortho_4x12(KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_RALT,
				  LCTL_T(KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, RSFT_T(KC_SLSH),
				  LSFT_T(KC_CAPS), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT,
				  TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, MO(_LOWER), SH_T(KC_SPC), KC_BSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [_LOWER] = LAYOUT_ortho_4x12(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
				 KC_DEL,	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
				 KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME, KC_END, KC_MUTE,
				 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, MO(_ADJUST), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    [_RAISE] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
				 KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
				 KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_MUTE,
				 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_DEL, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    [_PLOVER] = LAYOUT_ortho_4x12(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,
				  KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
				  KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
				  TO(_COLEMAK), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO, KC_NO, KC_NO),
    [_ADJUST] = LAYOUT_ortho_4x12(KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS,
				  KC_TRNS, KC_TRNS, MU_MOD, AU_ON, AU_OFF, LAG_NRM, LAG_SWP, DF(_QWERTY), DF(_COLEMAK), DF(_DVORAK), TO(_PLOVER), KC_TRNS,
				  KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS,
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_NAV] = LAYOUT_ortho_4x12(KC_TAB, KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_PSCR,
			       LCTL_T(KC_ESC), KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RSFT,
			       KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_TRNS,
			       KC_TRNS, KC_TRNS, KC_ACL1, KC_ACL2, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_DEL, KC_END, KC_PGDN, KC_NO),
    [_NUM] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NLCK, KC_PENT, KC_P7, KC_P8, KC_P9, KC_PSLS,
			       LCTL_T(KC_ESC), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_TAB, KC_P4, KC_P5, KC_P6, KC_PAST,
			       KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_PEQL, KC_P1, KC_P2, KC_P3, KC_PMNS,
			       KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_BSPC, KC_NO, KC_P0, KC_COMM, KC_DOT, KC_PPLS)
};
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_RALT, LCTL_T(KC_ESC), LSFT_T(KC_A), KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, RSFT_T(KC_O), RSFT_T(KC_QUOT), LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, TG(7), TG(8), KC_LGUI, KC_LALT, MO(3), KC_SPC, KC_BSPC, MO(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [_QWERTY] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RALT, LCTL_T(KC_ESC), LSFT_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, RSFT_T(KC_SCLN), RSFT_T(KC_QUOT), LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, TG(7), TG(8), KC_LGUI, KC_LALT, MO(3), KC_SPC, KC_BSPC, MO(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [_DVORAK] = LAYOUT_ortho_4x12(KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_RALT, LCTL_T(KC_ESC), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, RSFT_T(KC_SLSH), LSFT_T(KC_CAPS), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT, TG(7), TG(8), KC_LGUI, KC_LALT, MO(3), KC_SPC, KC_BSPC, MO(4), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    [_LOWER] = LAYOUT_ortho_4x12(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_NUHS), LSFT(KC_NUBS), KC_HOME, KC_END, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, MO(6), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    [_RAISE] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(6), KC_TRNS, KC_DEL, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    [_PLOVER] = LAYOUT_ortho_4x12(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, TO(0), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO, KC_NO, KC_NO),
    [_ADJUST] = LAYOUT_ortho_4x12(KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, MU_MOD, AU_ON, AU_OFF, LAG_NRM, LAG_SWP, DF(0), DF(1), DF(2), TO(5), KC_TRNS, KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_NAV] = LAYOUT_ortho_4x12(KC_TAB, KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_PSCR, LCTL_T(KC_ESC), KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RSFT, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL1, KC_ACL2, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_DEL, KC_END, KC_PGDN, KC_NO),
    [_NUM] = LAYOUT_ortho_4x12(KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NLCK, KC_PENT, KC_P7, KC_P8, KC_P9, KC_PSLS, LCTL_T(KC_ESC), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_TAB, KC_P4, KC_P5, KC_P6, KC_PAST, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_PEQL, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI, KC_NO, KC_SPC, KC_BSPC, KC_NO, KC_P0, KC_COMM, KC_DOT, KC_PPLS)
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    unsigned char color[3];
  
    switch (get_highest_layer(state)) {
    case _NAV:
	rgblight_setrgb (0x00,  0x00, 0xFF);
	break;
    case _NUM:
	rgblight_setrgb (0xFF,  0x00, 0x00);
	break;
    default: //  for any other layers, or the default layer
	rgblight_setrgb (0x00,  0xFF, 0x00);
	break;
    }
    return state;
}

/* #ifdef SWAP_HANDS_ENABLE */
/* __attribute__ ((weak)) */
/* // swap-hands action needs a matrix to define the swap */
/* const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = */
/*   { */
/*    {{5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}}, */
/*    {{5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}, */
/*    {{5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}}, */
/*    {{5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}}, */
   
/*    {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}}, */
/*    {{5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}}, */
/*    {{5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}}, */
/*    {{5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}}, */
/* }; */
/* #endif */

