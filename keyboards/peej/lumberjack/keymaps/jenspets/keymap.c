/* -*- c-file-style: "qmk" -*- */
/* Copyright 2022 Jens-Petter Sandvik
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <jenspets_keymap.h>

#define LAYOUT_wrap(...)  LAYOUT_ortho_5x12(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  
    /* Colemak
     * ,----------------------------------------------------------------------------------------------------------------.
     * | Grave      |     1   |    2   |    3   |     4    |    5   |   6  |    7    |    8   |    9   |   0    | PrScr |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Tab        |  RALT/Q |    W   |    F   |     P    |    B   |   J  |    L    |    U   |    Y   | RALT/; |  RAlt |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Esc/Ctrl   | LGUI/A  | LALT/R | LCTL/S |  LSFT/T  |    G   |   M  |  RSFT/N | RCTL/E | LALT/I | LGUI/O |   '   |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Shift/Caps |     Z   |    X   |    C   |     D    |    V   |   K  |    H    |    ,   |    .   |    /   | Enter |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | NAV        |    NUM  |   GUI  |   Alt  |  Lwr/Tab |  Space |  BS  | Rse/Esc |  Left  |  Down  |   Up   | Right |
     * `----------------------------------------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_5x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PSCR,
				   KC_TAB, RALT_T(KC_Q), KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, RALT_T(KC_SCLN), KC_RALT,
				   LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT,
				   LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
				   TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, LT(_LOWER, KC_TAB), SH_T(KC_SPC), KC_BSPC, LT(_RAISE, KC_ESC), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    /* Qwerty
     * ,------------------------------------------------------------------------------------------.
     * | Grave      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | PrScr |
     * |------------+------+------+------+------+------+------+------+------+------+------+-------|
     * | Tab        |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  RAlt |
     * |------------+------+------+------+------+------+------+------+------+------+------+-------|
     * | Esc/Ctrl   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '   |
     * |------------+------+------+------+------+------+------+------+------+------+------+-------|
     * | Shift/Caps |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter |
     * |------------+------+------+------+------+------+------+------+------+------+------+-------|
     * | NAV        | NUM  | GUI  | Alt  |Lower | Space| BS   |Raise | Left | Down |  Up  | Right |
     * `------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PSCR,
				  KC_TAB, RALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P), KC_RALT,
				  LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
				  LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
				  TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, MO(_LOWER), SH_T(KC_SPC), KC_BSPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    /* Lower (new)
     * ,----------------------------------------------------------------------------------------.
     * |       |      |      |     |      |      |      |        |       |      |        |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * |       |  `   |   @  |  {  |   }  |  %   |  ^   |   &    |   |   |  \   |   ~    |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * |       | Esc  |   !  |  (  |   )  |  '   |  *   |   -    |   =   | NUHS | S-NUHS |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * | ----- | Caps |   $  |  [  |   ]  |  "   |  #   |   _    |   +   | NUBS | S-NUBS |      |
     * |-------+------+------+-----+------+------+------+----- --+-------+------+--------+------|
     * | ----- | ---- | ---- | --- | ---- | ---- |      | Adjust |       |      |        |      |
     * `----------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_5x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
				 KC_TRNS, KC_GRV, KC_AT, KC_LCBR, KC_RCBR, KC_PERC, KC_CIRC, KC_AMPR, KC_PIPE, KC_BSLS, KC_TILD, KC_TRNS,
				 KC_TRNS,   KC_ESC, KC_EXLM, KC_LPRN, KC_RPRN, KC_QUOT, KC_ASTR, KC_MINS, KC_EQL, KC_NUHS, LSFT(KC_NUHS), KC_TRNS,
				 KC_TRNS, KC_CAPS, KC_DLR, KC_LBRC, KC_RBRC, LSFT(KC_QUOT), KC_HASH, KC_UNDS, KC_PLUS, KC_NUBS, LSFT(KC_NUBS), KC_TRNS,
				 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    
    /* Raise
     * ,-------------------------------------------------------------------------------------.
     * |  F11  |  F1  |  F2  | F3  |  F4  |  F5  |  F6  |   F7   |  F8  |  F9  |  F10 |  F12 |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | `     |   1  |   2  |  3  |   4  |   5  |   6  |    7   |   8  |   9  |   0  |   BS |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | Del   |  F1  |  F2  |  F3 |  F4  |  F5  |  F6  |    -   |   =  |   [  |   ]  |  \   |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | ----- |  F7  |  F8  | F9  | F10  | F11  | F12  |  NAV   | NUM  | Home | End  | Mute |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | ----- | ---- | ---- | --- |Adjust| Enter| Del  | -----  | Next | VolD | VolU | Play |
     * `-------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_5x12(KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12,
				 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
				 KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
				 KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, TG(_NAV), TG(_NUM), KC_PGUP, KC_PGDN, KC_MUTE,
				 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_ENT, KC_DEL, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
    /* Plover
     * ,------------------------------------------------------------------------------------.
     * |  1    |   1  |   1  |  1  |   1  |   1  |   1  |   1   |   1  |   1  |  1   |   1  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * |  1    |   1  |   1  |  1  |   1  |   1  |   1  |   1   |   1  |   1  |  1   |   1  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * | XXXXX |   Q  |   W  |  E  |   R  |   T  |   Y  |   U   |   I  |   O  |   P  |   [  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * | XXXXX |   A  |   S  |  D  |   F  |   G  |   H  |   J   |   K  |   L  |   :  |   '  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * |Colemak| XXXX | XXXX |  C  |   V  | XXXX | XXXX |   N   |   M  | XXXX | XXXX | XXXX |
     * `------------------------------------------------------------------------------------'
     */
    [_PLOVER] = LAYOUT_ortho_5x12(KC_1,         KC_1,   KC_1, KC_1, KC_1,  KC_1,  KC_1, KC_1, KC_1,  KC_1,    KC_1,    KC_1,
				  KC_1,         KC_1,   KC_1, KC_1, KC_1,  KC_1,  KC_1, KC_1, KC_1,  KC_1,    KC_1,    KC_1,
				  KC_NO,        KC_Q,   KC_W, KC_E, KC_R,  KC_T,  KC_Y, KC_U, KC_I,  KC_O,    KC_P, KC_LBRC,
				  KC_NO,        KC_A,   KC_S, KC_D, KC_F,  KC_G,  KC_H, KC_J, KC_K,  KC_L, KC_SCLN, KC_QUOT,
				  TO(_COLEMAK), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO,   KC_NO,   KC_NO),
    /* Adjust
     * ,-------------------------------------------------------------------------------------------------------------.
     * |      |       |       |         |         |         |         |         |         |         |         |      |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | Reset | Debug | RGB_tog | RGB_mod | RGB_hui | RGB_hud | RGB_sai | RGB_vai | RGB_sad | RGB_vad | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | ----- | MU_mod|  AU_on  | AU_off  | LAG_nrm | LAG_swp | Qwerty  | Colemak |  -----  | Plover  | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | MU_de | MU_in |  MU_on  | MU_off  |  MI_on  | MI_off  | TERM_on | Term_off|  -----  |  -----  | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | ----- | ----- |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  | ---- |
     * `-------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_5x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
				  KC_TRNS, RESET, DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS,
				  KC_TRNS, KC_TRNS, MU_MOD, AU_ON, AU_OFF, LAG_NRM, LAG_SWP, DF(_QWERTY), DF(_COLEMAK), KC_TRNS, TO(_PLOVER), KC_TRNS,
				  KC_TRNS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_TRNS,
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* Navigation
     * ,-------------------------------------------------------------------------------------------------------.
     * |          |       |        |        |         |        |       |       |       |       |       |       |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * |  Tab     | XXXXX | M_WH_L |   M_up |  M_WH_R | M_WH_U | M_BT1 | M_BT2 | M_BT3 | M_BT4 | M_BT5 | PrScr |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * | Ctrl/Esc | XXXXX | M_left |  M_dwn | M_right | M_WH_D | XXXXX |  Left |  Down |   Up  | Right |  Shft |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * | Shft     | XXXXX |  XXXXX |  XXXXX |  XXXXX  |  XXXXX | XXXXX | XXXXX |  Ins  |  Home |  PgUp | ----- | 
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------| 
     * |   ----   | ----- | M_acl1 | M_acl2 |  -----  |   Spc  | ----- | ----- |  Del  |  End  | PgDwn | XXXXX |
     * `-------------------------------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_5x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			       KC_TAB, KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_PSCR,
			       LCTL_T(KC_ESC), KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RSFT,
			       KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_TRNS,
			       KC_TRNS, KC_TRNS, KC_ACL1, KC_ACL2, KC_TRNS, KC_SPC, KC_TRNS, TG(_NAV), KC_DEL, KC_END, KC_PGDN, KC_NO),
    /* Number
     * ,----------------------------------------------------------------------------------------.
     * |          |       |       |       |       |       |         |       |    |    |    |    |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   XXXXX  | XXXXX |  Home |   Up  |  End  |  PgUp | NumLock | N_Ent | P7 | P8 | P9 | P/ |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * | Ctrl/Esc | XXXXX |  Left |  Down | Right | PgDwn |  XXXXX  |  Tab  | P4 | P5 | P6 | P* |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   Shft   | XXXXX | XXXXX | XXXXX | XXXXX | XXXXX |   Del   |   P=  | P1 | P2 | P3 | P- |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   -----  | ----- |  GUI  |  LAlt | XXXXX |  Spc  |    BS   | XXXXX | P0 |  , | P. | P+ |
     * `----------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_5x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			       KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NLCK, KC_PENT, KC_P7, KC_P8, KC_P9, KC_PSLS,
			       LCTL_T(KC_ESC), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_TAB, KC_P4, KC_P5, KC_P6, KC_PAST,
			       KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_PEQL, KC_P1, KC_P2, KC_P3, KC_PMNS,
			       KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_NO, KC_SPC, KC_BSPC, TG(_NUM), KC_P0, KC_COMM, KC_PDOT, KC_PPLS)
  };
