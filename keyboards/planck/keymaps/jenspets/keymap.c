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

/* Rgblight ideas borrowed from https://gist.github.com/muppetjones/3dff33c414311feed57a479cee6b574f */

#include QMK_KEYBOARD_H
#include "muse.h"

/* From users/jenspets/ */
#include <jenspets_keymap.h>

#define LAYOUT_ortho_4x12_wrap(...)  LAYOUT_ortho_4x12(__VA_ARGS__)

#ifdef USE_WIDE_MOD
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak
     * ,----------------------------------------------------------------------------------------------------------------.
     * | Tab        |  RALT/Q |    W   |    F   |     P    |    B   |   J  |    L    |    U   |    Y   | RALT/; |  RAlt |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Esc/Ctrl   | LGUI/A  | LALT/R | LCTL/S |  LSFT/T  |    G   |   M  |  RSFT/N | RCTL/E | LALT/I | LGUI/O |   '   |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Shift/Caps |     Z   |    X   |    C   |     D    |    V   |   K  |    H    |    ,   |    .   |    /   | Enter |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | NAV        |    NUM  |   GUI  |   Alt  |  Lwr/Tab |  Space |  BS  | Rse/Esc |  Left  |  Down  |   Up   | Right |
     * `----------------------------------------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_4x12_wrap(BASE_R2_L, KC_TAB, KC_RALT, BASE_R2_R,
					BASE_R3_L, LCTL_T(KC_ESC), KC_QUOT, BASE_R3_R, 
					BASE_R4_L, LSFT_T(KC_CAPS), KC_ENT, BASE_R4_R,
					TG(_NAV), KC_LEFT, KC_RGHT, BASE_T_L, KC_LGUI, KC_LALT, BASE_T_R, KC_DOWN, KC_UP, TG(_NUM)),
    /* Qwerty
     * ,-----------------------------------------------------------------------------------------.
     * | Tab        |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | RAlt |
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc/Ctrl   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift/Caps |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | NAV        | NUM  | GUI  | Alt  |Lower | Space| BS   |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12_wrap(QWR_R2_L, KC_TAB, KC_RALT, QWR_R2_R,
					QWR_R3_L, LCTL_T(KC_ESC), KC_QUOT, QWR_R3_R, 
					QWR_R4_L, LSFT_T(KC_CAPS), KC_ENT, QWR_R4_R,
					TG(_NAV), KC_LEFT, KC_RGHT, QWR_T_L, KC_LGUI, KC_LALT, QWR_T_R, KC_DOWN, KC_UP, TG(_NUM)),

    /* Lower
     * ,----------------------------------------------------------------------------------------.
     * |       |  `   |   @  |  {  |   }  |  %   |  ^   |   &    |   |   |  \   |   ~    |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * |       | Esc  |   !  |  (  |   )  |  '   |  *   |   -    |   =   | NUHS | S-NUHS |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * | ----- | Caps |   $  |  [  |   ]  |  "   |  #   |   _    |   +   | NUBS | S-NUBS |      |
     * |-------+------+------+-----+------+------+------+----- --+-------+------+--------+------|
     * | ----- | ---- | ---- | --- | ---- | ---- |      | Adjust |       |      |        |      |
     * `----------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_wrap(LOW_R2_L, KC_TRNS, KC_TRNS, LOW_R2_R,
				  LOW_R3_L, KC_TRNS, KC_TRNS, LOW_R3_R,
				  LOW_R4_L, KC_TRNS, KC_TRNS, LOW_R4_R,
				  KC_TRNS, KC_TRNS, KC_TRNS, LOW_T_L, KC_TRNS, KC_TRNS, LOW_T_R, KC_TRNS, KC_TRNS, KC_TRNS),
    /* Raise
     * ,-------------------------------------------------------------------------------------.
     * | `     |   1  |   2  |  3  |   4  |   5  |   6  |    7   |   8  |   9  |   0  |   BS |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | Del   |  F1  |  F2  |  F3 |  F4  |  F5  |  F6  |    -   |   =  |   [  |   ]  |  \   |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | ----- |  F7  |  F8  | F9  | F10  | F11  | F12  |  NAV   | NUM  | Home | End  | Mute |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | ----- | ---- | ---- | --- |Adjust| Enter| Del  | -----  | Next | VolD | VolU | Play |
     * `-------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_wrap(RSE_R2_L, KC_GRV, KC_BSPC, RSE_R2_R,
				 RSE_R3_L, KC_DEL, KC_BSLS, RSE_R3_R,
				 RSE_R4_L, KC_TRNS, KC_MUTE, RSE_R4_R,
				 KC_TRNS, KC_MNXT, KC_MPLY, RSE_T_L, KC_TRNS, KC_TRNS, RSE_T_R, KC_VOLD, KC_VOLU, KC_TRNS),
#    ifdef USE_PLOVER
    /* Plover
     * ,------------------------------------------------------------------------------------.
     * |  1    |   1  |   1  |  1  |   1  |   1  |   1  |   1   |   1  |   1  |  1   |   1  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * | XXXXX |   Q  |   W  |  E  |   R  |   T  |   Y  |   U   |   I  |   O  |   P  |   [  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * | XXXXX |   A  |   S  |  D  |   F  |   G  |   H  |   J   |   K  |   L  |   :  |   '  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * |Colemak| XXXX | XXXX |  C  |   V  | XXXX | XXXX |   N   |   M  | XXXX | XXXX | XXXX |
     * `------------------------------------------------------------------------------------'
     */
    [_PLOVER] = LAYOUT_ortho_4x12(KC_1,         KC_1,   KC_1, KC_1, KC_1,  KC_1,  KC_1, KC_1, KC_1,  KC_1,    KC_1,    KC_1,
				  KC_NO,        KC_Q,   KC_W, KC_E, KC_R,  KC_T,  KC_Y, KC_U, KC_I,  KC_O,    KC_P, KC_LBRC,
				  KC_NO,        KC_A,   KC_S, KC_D, KC_F,  KC_G,  KC_H, KC_J, KC_K,  KC_L, KC_SCLN, KC_QUOT,
				  TO(_COLEMAK), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO,   KC_NO,   KC_NO),
#    endif
    /* Adjust
     * ,-------------------------------------------------------------------------------------------------------------.
     * | ---- | Reset | Debug | RGB_tog | RGB_mod | RGB_hui | RGB_hud | RGB_sai | RGB_vai | RGB_sad | RGB_vad | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | ----- | MU_mod|  AU_on  | AU_off  | LAG_nrm | LAG_swp | Qwerty  | Colemak |  -----  | Plover  | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | MU_de | MU_in |  MU_on  | MU_off  |  MI_on  | MI_off  | TERM_on | Term_off|  -----  |  -----  | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | ----- | ----- |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  | ---- |
     * `-------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12_wrap(ADJ_R2_L, KC_TRNS, KC_TRNS, ADJ_R2_R,
				  ADJ_R3_L, KC_TRNS, KC_TRNS, ADJ_R3_R,
				  ADJ_R4_L, KC_TRNS, KC_TRNS, ADJ_R4_R,
				  KC_TRNS, KC_TRNS, KC_TRNS, ADJ_T_L, KC_TRNS, KC_TRNS, ADJ_T_R, KC_TRNS, KC_TRNS, KC_TRNS),
     /* Navigation
     * ,-------------------------------------------------------------------------------------------------------.
     * |  Tab     | XXXXX | M_WH_L |   M_up |  M_WH_R | M_WH_U | M_BT1 | M_BT2 | M_BT3 | M_BT4 | M_BT5 | PrScr |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * | Ctrl/Esc | XXXXX | M_left |  M_dwn | M_right | M_WH_D | XXXXX |  Left |  Down |   Up  | Right |  Shft |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * | Shft     | XXXXX |  XXXXX |  XXXXX |  XXXXX  |  XXXXX | XXXXX | XXXXX |  Ins  |  Home |  PgUp | ----- | 
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------| 
     * |   ----   | ----- | M_acl1 | M_acl2 |  -----  |   Spc  | ----- | ----- |  Del  |  End  | PgDwn | XXXXX |
     * `-------------------------------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_4x12_wrap(NAV_R2_L, KC_TAB, KC_PSCR, NAV_R2_R,
				    NAV_R3_L, LCTL_T(KC_ESC), KC_RSFT, NAV_R3_R,
				    NAV_R4_L, KC_LSFT, KC_TRNS, NAV_R4_R,
				    KC_TRNS, KC_ACL1, KC_ACL2, NAV_T_L, KC_TRNS, KC_TRNS, NAV_T_R, KC_DEL, KC_END, KC_TRNS),
     /* Number
     * ,----------------------------------------------------------------------------------------.
     * |   XXXXX  | XXXXX |  Home |   Up  |  End  |  PgUp | NumLock | N_Ent | P7 | P8 | P9 | P/ |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * | Ctrl/Esc | XXXXX |  Left |  Down | Right | PgDwn |  XXXXX  |  Tab  | P4 | P5 | P6 | P* |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   Shft   | XXXXX | XXXXX | XXXXX | XXXXX | XXXXX |   Del   |   P=  | P1 | P2 | P3 | P- |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   -----  | ----- |  GUI  |  LAlt | XXXXX |  Spc  |    BS   | XXXXX | P0 |  , | P. | P+ |
     * `----------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_4x12_wrap(NUM_R2_L, KC_NO, KC_PSLS, NUM_R2_R,
			       NUM_R3_L, LCTL_T(KC_ESC), KC_PAST, NUM_R3_R,
			       NUM_R4_L, KC_LSFT, KC_PMNS, NUM_R4_R,
			       KC_TRNS, KC_TRNS, KC_TRNS, NUM_T_L, KC_LGUI, KC_LALT, NUM_T_R, KC_COMM, KC_PDOT, KC_TRNS)
};

#else /* !USE_WIDE_MOD */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak
     * ,----------------------------------------------------------------------------------------------------------------.
     * | Tab        |  RALT/Q |    W   |    F   |     P    |    B   |   J  |    L    |    U   |    Y   | RALT/; |  RAlt |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Esc/Ctrl   | LGUI/A  | LALT/R | LCTL/S |  LSFT/T  |    G   |   M  |  RSFT/N | RCTL/E | LALT/I | LGUI/O |   '   |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | Shift/Caps |     Z   |    X   |    C   |     D    |    V   |   K  |    H    |    ,   |    .   |    /   | Enter |
     * |------------+---------+--------+--------+----------+--------+------+---------+--------+--------+--------+-------|
     * | NAV        |    NUM  |   GUI  |   Alt  |  Lwr/Tab |  Space |  BS  | Rse/Esc |  Left  |  Down  |   Up   | Right |
     * `----------------------------------------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_4x12_wrap(KC_TAB, BASE_R2_L, BASE_R2_R, KC_RALT,
				   LCTL_T(KC_ESC), BASE_R3_L, BASE_R3_R, KC_QUOT,
				   LSFT_T(KC_CAPS), BASE_R4_L, BASE_R4_R, KC_ENT,
				   TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, BASE_T_L, BASE_T_R, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    /* Qwerty
     * ,-----------------------------------------------------------------------------------------.
     * | Tab        |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | RAlt |
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc/Ctrl   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift/Caps |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | NAV        | NUM  | GUI  | Alt  |Lower | Space| BS   |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12_wrap(KC_TAB, QWR_R2_L, QWR_R2_R, KC_RALT,
				   LCTL_T(KC_ESC), QWR_R3_L, QWR_R3_R, KC_QUOT,
				   LSFT_T(KC_CAPS), QWR_R4_L, QWR_R4_R, KC_ENT,
				   TG(_NAV), TG(_NUM), KC_LGUI, KC_LALT, QWR_T_L, QWR_T_R, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* Lower
     * ,----------------------------------------------------------------------------------------.
     * |       |  `   |   @  |  {  |   }  |  %   |  ^   |   &    |   |   |  \   |   ~    |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * |       | Esc  |   !  |  (  |   )  |  '   |  *   |   -    |   =   | NUHS | S-NUHS |      |
     * |-------+------+------+-----+------+------+------+--------+-------+------+--------+------|
     * | ----- | Caps |   $  |  [  |   ]  |  "   |  #   |   _    |   +   | NUBS | S-NUBS |      |
     * |-------+------+------+-----+------+------+------+----- --+-------+------+--------+------|
     * | ----- | ---- | ---- | --- | ---- | ---- |      | Adjust |       |      |        |      |
     * `----------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_wrap(KC_TRNS, LOW_R2_L, LOW_R2_R, KC_TRNS,
				  KC_TRNS, LOW_R3_L, LOW_R3_R, KC_TRNS,
				  KC_TRNS, LOW_R4_L, LOW_R4_R, KC_TRNS,
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOW_T_L, LOW_T_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    /* Raise
     * ,-------------------------------------------------------------------------------------.
     * | `     |   1  |   2  |  3  |   4  |   5  |   6  |    7   |   8  |   9  |   0  |   BS |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | Del   |  F1  |  F2  |  F3 |  F4  |  F5  |  F6  |    -   |   =  |   [  |   ]  |  \   |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | ----- |  F7  |  F8  | F9  | F10  | F11  | F12  |  NAV   | NUM  | Home | End  | Mute |
     * |-------+------+------+-----+------+------+------+--------+------+------+------+------|
     * | ----- | ---- | ---- | --- |Adjust| Enter| Del  | -----  | Next | VolD | VolU | Play |
     * `-------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_wrap(KC_GRV, RSE_R2_L, RSE_R2_R, KC_BSPC,
				 KC_DEL, RSE_R3_L, RSE_R3_R, KC_BSLS,
				 KC_TRNS, RSE_R4_L, RSE_R4_R, KC_MUTE,
				 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSE_T_L, RSE_T_R, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
#    ifdef USE_PLOVER
    /* Plover
     * ,------------------------------------------------------------------------------------.
     * |  1    |   1  |   1  |  1  |   1  |   1  |   1  |   1   |   1  |   1  |  1   |   1  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * | XXXXX |   Q  |   W  |  E  |   R  |   T  |   Y  |   U   |   I  |   O  |   P  |   [  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * | XXXXX |   A  |   S  |  D  |   F  |   G  |   H  |   J   |   K  |   L  |   :  |   '  |
     * |-------+------+------+-----+------+------+------+-------+------+------+------+------|
     * |Colemak| XXXX | XXXX |  C  |   V  | XXXX | XXXX |   N   |   M  | XXXX | XXXX | XXXX |
     * `------------------------------------------------------------------------------------'
     */
    [_PLOVER] = LAYOUT_ortho_4x12(KC_1,         KC_1,   KC_1, KC_1, KC_1,  KC_1,  KC_1, KC_1, KC_1,  KC_1,    KC_1,    KC_1,
				  KC_NO,        KC_Q,   KC_W, KC_E, KC_R,  KC_T,  KC_Y, KC_U, KC_I,  KC_O,    KC_P, KC_LBRC,
				  KC_NO,        KC_A,   KC_S, KC_D, KC_F,  KC_G,  KC_H, KC_J, KC_K,  KC_L, KC_SCLN, KC_QUOT,
				  TO(_COLEMAK), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO,   KC_NO,   KC_NO),
#    endif
    /* Adjust
     * ,-------------------------------------------------------------------------------------------------------------.
     * | ---- | Reset | Debug | RGB_tog | RGB_mod | RGB_hui | RGB_hud | RGB_sai | RGB_vai | RGB_sad | RGB_vad | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | ----- | MU_mod|  AU_on  | AU_off  | LAG_nrm | LAG_swp | Qwerty  | Colemak |  -----  | Plover  | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | MU_de | MU_in |  MU_on  | MU_off  |  MI_on  | MI_off  | TERM_on | Term_off|  -----  |  -----  | ---- |
     * |------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+------|
     * | ---- | ----- | ----- |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  |  -----  | ---- |
     * `-------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12_wrap(KC_TRNS, ADJ_R2_L, ADJ_R2_R, KC_TRNS,
				  KC_TRNS, ADJ_R3_L, ADJ_R3_R, KC_TRNS,
				  KC_TRNS, ADJ_R4_L, ADJ_R4_R, KC_TRNS,
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJ_T_L, ADJ_T_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
     /* Navigation
     * ,-------------------------------------------------------------------------------------------------------.
     * |  Tab     | XXXXX | M_WH_L |   M_up |  M_WH_R | M_WH_U | M_BT1 | M_BT2 | M_BT3 | M_BT4 | M_BT5 | PrScr |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * | Ctrl/Esc | XXXXX | M_left |  M_dwn | M_right | M_WH_D | XXXXX |  Left |  Down |   Up  | Right |  Shft |
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------|
     * | Shft     | XXXXX |  XXXXX |  XXXXX |  XXXXX  |  XXXXX | XXXXX | XXXXX |  Ins  |  Home |  PgUp | ----- | 
     * |----------+-------+--------+--------+---------+--------+-------+-------+-------+-------+-------+-------| 
     * |   ----   | ----- | M_acl1 | M_acl2 |  -----  |   Spc  | ----- | ----- |  Del  |  End  | PgDwn | XXXXX |
     * `-------------------------------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_4x12_wrap(KC_TAB, NAV_R2_L, NAV_R2_R, KC_PSCR,
			       LCTL_T(KC_ESC), NAV_R3_L, NAV_R3_R, KC_RSFT,
			       KC_LSFT, NAV_R4_L, NAV_R4_R, KC_TRNS,
			       KC_TRNS, KC_TRNS, KC_ACL1, KC_ACL2, NAV_T_L, NAV_T_R, KC_DEL, KC_END, KC_PGDN, KC_NO),
     /* Number
     * ,----------------------------------------------------------------------------------------.
     * |   XXXXX  | XXXXX |  Home |   Up  |  End  |  PgUp | NumLock | N_Ent | P7 | P8 | P9 | P/ |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * | Ctrl/Esc | XXXXX |  Left |  Down | Right | PgDwn |  XXXXX  |  Tab  | P4 | P5 | P6 | P* |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   Shft   | XXXXX | XXXXX | XXXXX | XXXXX | XXXXX |   Del   |   P=  | P1 | P2 | P3 | P- |
     * |----------+--------+------+-------+-------+-------+---------+-------+----+----+----+----|
     * |   -----  | ----- |  GUI  |  LAlt | XXXXX |  Spc  |    BS   | XXXXX | P0 |  , | P. | P+ |
     * `----------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_4x12_wrap(KC_NO, NUM_R2_L, NUM_R2_R, KC_PSLS,
			       LCTL_T(KC_ESC), NUM_R3_L, NUM_R3_R, KC_PAST,
			       KC_LSFT, NUM_R4_L, NUM_R4_R, KC_PMNS,
			       KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, NUM_T_L, NUM_T_R, KC_P0, KC_COMM, KC_PDOT, KC_PPLS)
};
#endif /* USE_WIDE_MOD */
