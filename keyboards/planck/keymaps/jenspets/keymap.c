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
#include <jenspets.h>

#define LAYOUT_ortho_4x12_wrap(...)  LAYOUT_ortho_4x12(__VA_ARGS__)

#ifdef USE_WIDE_MOD
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak
     * ,-----------------------------------------------------------------------------------------------------------------.
     * |    Q   |    W   |    F   |     P    |    B   |     Tab    |  RALT |    J   |    L    |    U   |    Y   |    ;   |
     * |--------+--------+--------+----------+--------+------------+-------+--------+---------+--------+--------+--&-----|
     * | LGUI/A | LALT/R | LCTL/S |  LSFT/T  |    G   |  Esc/Ctrl  |   '   |    M   |  RSFT/N | RCTL/E | LALT/I | LGUI/O |
     * |--------+--------+--------+----------+--------+------------+-------+--------+---------+--------+--------+--------|
     * | NAV/Z  |    X   |    C   |  RALT/D  |    V   | Shift/Caps | Enter |    K   |  RALT/H |    ,   |    .   |  NUM// | 
     * |--------+--------+--------+----------+--------+------------+-------+--------+---------+--------+--------+--------|
     * | NAV    |  Left  | Right  |  Lwr/Tab |  Space |   LGUI     |   J   |   BS   | Rse/Esc |  Down  |   Up   |   NUM  |
     * `-----------------------------------------------------------------------------------------------------------------'
     */
    [_COLEMAK] = LAYOUT_ortho_4x12_wrap(BASE_R2_L, KC_TAB, KC_RALT, BASE_R2_R,
					BASE_R3_L, LCTL_T(KC_ESC), KC_QUOT, BASE_R3_R, 
					BASE_R4_L, LSFT_T(KC_CAPS), KC_ENT, BASE_R4_R,
					TG(_NAV), KC_LEFT, KC_RGHT, BASE_T_L, KC_LGUI, KC_J, BASE_T_R, KC_DOWN, KC_UP, TG(_NUM)),

    /* Game
     * ,-------------------------------------------------------------------------------------.
     * | Tab   |   Q  |   W   |   E   |   R   |  T  | NO | ESC  |  NO  |  Up  |   NO  | BSPC |
     * |-------+------+-------+-------+-------+-----+----+------+------+------+-------+------|
     * | Ctrl  |   A  |   S   |   D   |   F   |  G  | NO |  NO  | Left | Down | Right |  P0  |
     * |-------+------+-------+-------+-------+-----+----+------+------+------+-------+------|
     * | Shift |   Z  |   X   |   C   |   V   |  B  | NO |  NO  |  NO  |  NO  |  NO   |Enter |
     * |-------+------+-------+-------+-------+-----+----+------+------+------+-------+------|
     * | NO    |  NO  |   NO  | GAME2 | Space |  NO | NO |  BS  |  NO  |  NO  |  NO   |  NO  |
     * `-------------------------------------------------------------------------------------'
     */
    [_GAME] = LAYOUT_ortho_4x12_wrap(GAME_R2_L, KC_T, KC_NO, GAME_R2_R,
				     GAME_R3_L, KC_G, KC_NO, GAME_R3_R, 
				     GAME_R4_L, KC_B, KC_NO, GAME_R4_R,
				     KC_NO, KC_NO, KC_NO, GAME_T_L, KC_NO, KC_NO, GAME_T_R, KC_NO, KC_NO, KC_NO),

    /* Game2
     * ,----------------------------------------------------------------------------------.
     * |  F1 |  F2  |  F3  |  F4  |  F5  |  F6  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |-----+------+------+------+------+------+------+------+------+------+------+------|
     * |  1  |   2  |   3  |   4  |   5  |  6   |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |-----+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |-----+------+------+------+------+------+------+------+------+------+------+------|
     * |  NO |  NO  |  NO  |      |  NO  |  NO  |  NO  |  NO  | GAME |  NO  |  NO  |  NO  |
     * `----------------------------------------------------------------------------------'
     */
    [_GAME2] = LAYOUT_ortho_4x12_wrap(GAME2_R2_L, KC_F6, KC_NO, GAME2_R2_R,
					GAME2_R3_L, KC_6, KC_NO, GAME2_R3_R, 
					GAME2_R4_L, KC_NO, KC_NO, GAME2_R4_R,
					KC_NO, KC_NO, KC_NO, GAME2_T_L, KC_NO, KC_NO, GAME2_T_R, KC_NO, KC_NO, KC_NO),

    
    /* Qwerty
     * ,-----------------------------------------------------------------------------------------------------------.
     * |    Q   |    W   |    E   |    R   |   T   |    Tab     |  RAlt |   Y  |    U   |    I   |    O   |    P   |
     * |--------+--------+--------+--------+-------+------------+-------+------+--------+--------+--------+--------|
     * | LGUI/A | LALT/S | LCTL/D | LSFT/F |   G   |  Esc/Ctrl  |   '   |   H  | RSFT/J | RCTL/K | LALT/L | LGUI/; |
     * |--------+--------+--------+--------+-------+------------+-------+------+--------+--------+--------+--------|
     * |  NAV/Z |    X   |    C   | RALT/V |   B   | Shift/Caps | Enter |   N  | RALT/M |    ,   |    .   |  NUM// |
     * |--------+--------+--------+--------+-------+------------+-------+------+--------+--------+--------+--------|
     * |   NAV  |  Left  |  Right |  Lower | Space |    LGUI    |  LALT | BSPC |  Raise |  Down  |   Up   |   NUM  |
     * `-----------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12_wrap(QWR_R2_L, KC_TAB, KC_RALT, QWR_R2_R,
					QWR_R3_L, LCTL_T(KC_ESC), KC_QUOT, QWR_R3_R, 
					QWR_R4_L, LSFT_T(KC_CAPS), KC_ENT, QWR_R4_R,
					TG(_NAV), KC_LEFT, KC_RGHT, QWR_T_L, KC_LGUI, KC_LALT, QWR_T_R, KC_DOWN, KC_UP, TG(_NUM)),

    /* Lower
     * ,------------------------------------------------------------------------------------------.
     * |   `   |  @   |   {  |  }  |   %  |      |      |   ^   |    &   |   |  |    \   |   ~    |
     * |-------+------+------+-----+------+------+------+-------+--------+------+--------+--------|
     * |  Esc  |   !  |   (  |  )  |  '   |      |      |   *   |    -   |   =  |  NUHS  | S-NUHS |
     * |-------+------+------+-----+------+------+------+-------+--------+------+--------+--------|
     * |  Caps |   $  |   [  |  ]  |  "   |      |      |   #   |    _   |   +  |  NUBS  | S-NUBS |
     * |-------+------+------+-----+------+------+------+-------+--------+------+--------+--------|
     * |       |      |      |     |      |      |      |       | ADJUST |      |        |        |
     * `------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_wrap(LOW_R2_L, KC_TRNS, KC_TRNS, LOW_R2_R,
				  LOW_R3_L, KC_TRNS, KC_TRNS, LOW_R3_R,
				  LOW_R4_L, KC_TRNS, KC_TRNS, LOW_R4_R,
				  KC_TRNS, KC_TRNS, KC_TRNS, LOW_T_L, KC_TRNS, KC_TRNS, LOW_T_R, KC_TRNS, KC_TRNS, KC_TRNS),
    /* Raise
     * ,--------------------------------------------------------------------------------------.
     * | F1  |  F2  |  F3  |   F4   |   F5  |     |      |   F6  |  F7  |  F8  |  F9  |  F10  |
     * |-----+------+------+--------+-------+-----+------+-------+------+------+------+-------|
     * |  9  |   7  |   3  |    1   |  Home |     |      |  PgUp |   0  |   2  |   6  |   8   |
     * |-----+------+------+--------+-------+-----+------+-------+------+------+------+-------|
     * | F11 |  F12 |  Ins |    5   |  End  |     | Mute |  PgDn |   4  |  NAV |  NUM | PrScr |
     * |-----+------+------+--------+-------+-----+------+-------+------+------+------+-------|
     * |     | Next | Play | ADJUST | Enter |     |      |  Del  |      | VolD | VolU |       |
     * `--------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_wrap(RSE_R2_L, KC_GRV, KC_BSPC, RSE_R2_R,
				 RSE_R3_L, KC_DEL, KC_BSLS, RSE_R3_R,
				 RSE_R4_L, KC_TRNS, KC_MUTE, RSE_R4_R,
				 KC_TRNS, KC_MNXT, KC_MPLY, RSE_T_L, KC_TRNS, KC_TRNS, RSE_T_R, KC_VOLD, KC_VOLU, KC_TRNS),


    /* Audio
     * ,------------------------------------------------------------------------------------.
     * |    NO  |   NO   |  NO  |   NO  |  NO  |      |      | NO |  NO  |  NO  |  NO  | NO |
     * |--------+--------+------+-------+------+------+------+----+------+------+------+----|
     * |    NO  |  Next  | AuOn | AuOff |  NO  |      |      | NO | Mute | VolU | VolD | NO |
     * |--------+--------+------+-------+------+------+------+----+------+------+------+----|
     * | AuPrev | AuNext | MuOn | MuOff | MiOn |      |      | NO | Play | Prev | Next |    |
     * |-------=+--------+------+-------+------+------+------+----+------+------+------+----|
     * |        |        |      |       |      |      |      |    |      |      |      |    |
     * `------------------------------------------------------------------------------------'
     */
    [_AUDIO] = LAYOUT_ortho_4x12_wrap(AUD_R2_L, KC_TRNS, KC_TRNS, AUD_R2_R,
				  AUD_R3_L, KC_TRNS, KC_TRNS, AUD_R3_R,
				  AUD_R4_L, KC_TRNS, KC_TRNS, AUD_R4_R,
				  KC_TRNS, KC_TRNS, KC_TRNS, AUD_T_L, KC_TRNS, KC_TRNS, AUD_T_R, KC_TRNS, KC_TRNS, KC_TRNS),

#ifdef USE_PLOVER
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
#endif
    /* Adjust
     * ,-------------------------------------------------------------------------------------------------------.
     * | Reset | Debug | RGB_tog | RGB_mod | RGB_hui |   |   | RGB_hud | RGB_sai | RGB_sad | RGB_vai | RGB_vad |
     * |-------+-------+---------+---------+---------+---+---+---------+---------+---------+---------+---------|
     * |   NO  |   NO  |    NO   |    NO   | LAG_nrm |   |   | LAG_swp | COLEMAK |   GAME  |  QWERTY | PLOVER  |
     * |-------+-------+---------+---------+---------+---+---+---------+---------+---------+---------+---------|
     * |   NO  |   NO  |    NO   |    NO   |   NO    |   |   |    NO   |         |         |         |         | 
     * |-------+-------+---------+---------+---------+---+---+---------+---------+---------+---------+---------|
     * |       |       |         |         |  PrScr  |   |   |   Ins   |         |         |         |         |
     * `-------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12_wrap(ADJ_R2_L, KC_TRNS, KC_TRNS, ADJ_R2_R,
				  ADJ_R3_L, KC_TRNS, KC_TRNS, ADJ_R3_R,
				  ADJ_R4_L, KC_TRNS, KC_TRNS, ADJ_R4_R,
				  KC_TRNS, KC_TRNS, KC_TRNS, ADJ_T_L, KC_TRNS, KC_TRNS, ADJ_T_R, KC_TRNS, KC_TRNS, KC_TRNS),
     /* Navigation
     * ,-----------------------------------------------------------------------------------------------------.
     * |  NO | M_WH_L |   M_up |  M_WH_R | M_WH_U |    Tab   | PrScr | M_BT4 | M_BT1 | M_BT3 | M_BT2 | M_BT5 | 
     * |-----+--------+--------+---------+--------+----------+-------+-------+-------+-------+-------+-------|
     * |  NO | M_left |  M_dwn | M_right | M_WH_D | Ctrl/Esc | Shift |   NO  |  Left |  Down |   Up  | Right |
     * |-----+--------+--------+---------+--------+----------+-------+-------+-------+-------+-------+-------|
     * |     |  LAlt  |  LCtrl |  LShift |  LGui  |          |       |  Tab  |  Home |  PgDn |  PgUp |  End  |
     * |-----+--------+--------+---------+--------+----------+-------+-------+-------+-------+-------+-------| 
     * |     |        |        |         |   Spc  |          |       |       |  NAV  |  Del  |       |       |
     * `-----------------------------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_4x12_wrap(NAV_R2_L, KC_TAB, KC_PSCR, NAV_R2_R,
				    NAV_R3_L, LCTL_T(KC_ESC), KC_RSFT, NAV_R3_R,
				    NAV_R4_L, KC_TRNS, KC_TRNS, NAV_R4_R,
				    KC_TRNS, KC_ACL1, KC_ACL2, NAV_T_L, KC_TRNS, KC_TRNS, NAV_T_R, KC_DEL, KC_TRNS, KC_TRNS),
     /* Number
     * ,--------------------------------------------------------------------------------------.
     * | NumLock |  Home |  Up  |  End  |  PgUp |     NO   |  P+  | P= |  P7 | P8 | P9 | PEnt |
     * |---------+-------+------+-------+-------+----------+------+----+-----+----+----+------|
     * |    NO   |  Left | Down | Right | PgDwn | Ctrl/Esc |  P,  | P. |  P4 | P5 | P6 |  Tab |
     * |---------+-------+------+-------+-------+----------+------+----+-----+----+----+------|
     * |    P/   |   P*  |  P-  |   P+  |   P,  |   Shift  |  P-  | P0 |  P1 | P2 | P3 |  Del | 
     * |---------+-------+------+-------+-------+----------+------+----+-----+----+----+------|
     * |         |       |      |   NO  |  Spc  |    LGui  | LAlt | BS | NUM |  , | P. |      |
     * `--------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_4x12_wrap(NUM_R2_L, KC_NO, KC_KP_PLUS, NUM_R2_R,
			       NUM_R3_L, LCTL_T(KC_ESC), KC_PCMM, NUM_R3_R,
			       NUM_R4_L, KC_LSFT, KC_PMNS, NUM_R4_R,
			       KC_TRNS, KC_TRNS, KC_TRNS, NUM_T_L, KC_LGUI, KC_LALT, NUM_T_R, KC_PCMM, KC_PDOT, KC_TRNS)
};

#else /* !USE_WIDE_MOD */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Colemak
     * ,------------------------------------------------------------------------------------------------------------------.
     * |     Tab    |    Q   |    W   |    F   |     P    |    B   |    J    |    L    |    U   |    Y   |    ;   |  RALT |
     * |------------+--------+--------+--------+----------+--------+---------+---------+--------+--------+--------+-------|
     * |  Esc/Ctrl  | LGUI/A | LALT/R | LCTL/S |  LSFT/T  |    G   |    M    |  RSFT/N | RCTL/E | LALT/I | LGUI/O |   '   |
     * |------------+--------+--------+--------+----------+--------+---------+---------+--------+--------+--------+-------|
     * | Shift/Caps | NAV/Z  |    X   |    C   |  RALT/D  |    V   |    K    |  RALT/H |    ,   |    .   |  NUM// | Enter | 
     * |------------+--------+--------+--------+----------+--------+---------+---------+--------+--------+--------+-------|
     * |     NAV    |   NUM  |  LGUI  |    J   |  Lwr/Tab |  Space |    BS   | Rse/Esc |   Left  |  Down |   Up   | Right |
     * `------------------------------------------------------------------------------------------------------------------'
     */
 
    [_COLEMAK] = LAYOUT_ortho_4x12_wrap(KC_TAB, BASE_R2_L, BASE_R2_R, KC_RALT,
				   LCTL_T(KC_ESC), BASE_R3_L, BASE_R3_R, KC_QUOT,
				   LSFT_T(KC_CAPS), BASE_R4_L, BASE_R4_R, KC_ENT,
				   TG(_NAV), TG(_NUM), KC_LGUI, KC_J, BASE_T_L, BASE_T_R, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),
    /* Game
     * ,-------------------------------------------------------------------------------------.
     * | NO | Tab   |   Q  |   W   |   E   |   R   |  NO  |  NO  |  Up  |   NO  | BSPC | ESC |
     * |----+-------+------+-------+-------+-------+------+------+------+------+-------+-----|
     * | NO | Ctrl  |   A  |   S   |   D   |   F   |  NO  | Left | Down | Right |  P0  |  NO | 
     * |----+-------+------+-------+-------+-------+------+------+------+------+-------+-----|
     * | NO | Shift |   Z  |   X   |   C   |   V   |  NO  |  NO  |  NO  |  NO   |Enter |  NO | 
     * |----+-------+------+-------+-------+-------+------+------+------+------+-------+-----|
     * | NO | NO    |  NO  |   NO  | GAME2 | Space |  BS  |  NO  |  NO  |  NO   |  NO  |  NO | 
     * `-------------------------------------------------------------------------------------'
     */
    [_GAME] = LAYOUT_ortho_4x12_wrap(KC_NO, GAME_R2_L, GAME_R2_R, KC_ESC,
				     KC_NO, GAME_R3_L, GAME_R3_R, KC_NO,
				     KC_NO, GAME_R4_L, GAME_R4_R, KC_NO,
				     KC_NO, KC_NO, KC_NO, KC_NO, GAME_T_L, GAME_T_R, KC_NO, KC_NO, KC_NO, KC_NO),

    /* Game2
     * ,----------------------------------------------------------------------------------.
     * |  NO  |  F1 |  F2  |  F3  |  F4  |  F5  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |------+-----+------+------+------+------+------+------+------+------+------+------|
     * |  NO  |  1  |   2  |   3  |   4  |   5  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |------+-----+------+------+------+------+------+------+------+------+------+------|
     * |  NO  | Esc |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |------+-----+------+------+------+------+------+------+------+------+------+------|
     * |  NO  |  NO |  NO  |  NO  |      |  NO  |  NO  | GAME |  NO  |  NO  |  NO  |  NO  |
     * `----------------------------------------------------------------------------------'
     */
    [_GAME2] = LAYOUT_ortho_4x12_wrap(KC_NO, GAME2_R2_L, GAME2_R2_R, KC_NO, 
					KC_NO, GAME2_R3_L, GAME2_R3_R, KC_NO,  
					KC_NO, GAME2_R4_L, GAME2_R4_R, KC_NO, 
					KC_NO, KC_NO, KC_NO, KC_NO, GAME2_T_L, GAME2_T_R, KC_NO, KC_NO, KC_NO, KC_NO),

    
    /* Qwerty
     * ,-------------------------------------------------------------------------------------------------------------.
     * |    Tab     |    Q   |    W   |    E   |    R    |   T   |   Y  |    U    |    I   |    O   |    P   |  RAlt |
     * |------------+--------+--------+--------+---------+-------+------+---------+--------+--------+--------+-------|
     * |  Esc/Ctrl  | LGUI/A | LALT/S | LCTL/D |  LSFT/F |   G   |   H  |  RSFT/J | RCTL/K | LALT/L | LGUI/; |   '   |
     * |------------+--------+--------+--------+---------+-------+------+---------+--------+--------+--------+-------|
     * | Shift/Caps |  NAV/Z |    X   |    C   |  RALT/V |   B   |   N  |  RALT/M |    ,   |    .   |  NUM// | Enter |
     * |------------+--------+--------+--------+---------+-------+------+---------+--------+--------+--------+-------|
     * |     NAV    |   NUM  |  LGUI  |  LAlt  | Lwr/Tab | Space |  BS  | Rse/Esc |  Left  |  Down  |   Up   | Right |
     * `-------------------------------------------------------------------------------------------------------------'
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
     * |       | Caps |   $  |  [  |   ]  |  "   |  #   |   _    |   +   | NUBS | S-NUBS |      |
     * |-------+------+------+-----+------+------+------+----- --+-------+------+--------+------|
     * |       |      |      |     |      |      |  Del | ADJUST |       |      |        |      |
     * `----------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_wrap(KC_TRNS, LOW_R2_L, LOW_R2_R, KC_TRNS,
				  KC_TRNS, LOW_R3_L, LOW_R3_R, KC_TRNS,
				  KC_TRNS, LOW_R4_L, LOW_R4_R, KC_TRNS,
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOW_T_L, LOW_T_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Raise
     * ,--------------------------------------------------------------------------------------.
     * |     |  F1  |  F2  |  F3  |   F4   |   F5  |   F6  |  F7  |  F8  |  F9  |  F10  |     |
     * |-----+------+------+--------+-------+-----+------+-------+------+------+------+-------|
     * |     |   9  |   7  |   3  |    1   |  Home |  PgUp |   0  |   2  |   6  |   8   |     |
     * |-----+------+------+--------+-------+-----+------+-------+------+------+------+-------|
     * |     |  F11 |  F12 |  Ins |    5   |  End  |  PgDn |   4  |  NAV |  NUM | PrScr |     |
     * |-----+------+------+--------+-------+-----+------+-------+------+------+------+-------|
     * |     |      | Next | Play | ADJUST | Enter |  Del  |      | VolD | VolU |       |     |
     * `--------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_wrap(KC_TRNS, RSE_R2_L, RSE_R2_R, KC_TRNS,
				 KC_TRNS, RSE_R3_L, RSE_R3_R, KC_TRNS,
				 KC_TRNS, RSE_R4_L, RSE_R4_R, KC_TRNS,
				 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSE_T_L, RSE_T_R, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS),

    /* Audio
     * ,-----------------------------------------------------------------------------------.
     * |     |   NO   |   NO   |  NO  |   NO  |  NO  | NO |  NO  |  NO  |  NO  | NO |      |
     * |-----+--------+--------+-------+------+------+----+------+------+------+----+------|
     * |     |   NO   |  Next  | AuOn | AuOff |  NO  | NO | Mute | VolU | VolD | NO |      |
     * |-----+--------+--------+-------+------+------+----+------+------+------+----+------|
     * |     | AuPrev | AuNext | MuOn | MuOff | MiOn | NO | Play | Prev | Next |    |      |
     * |-----+--------+--------+-------+------+------+----+------+------+------+----+------|
     * |     |        |        |      |       |      |    |      |      |      |    |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_AUDIO] = LAYOUT_ortho_4x12_wrap(KC_TRNS, AUD_R2_L, AUD_R2_R, KC_TRNS, 
				  KC_TRNS, AUD_R3_L, AUD_R3_R, KC_TRNS, 
				  KC_TRNS, AUD_R4_L, AUD_R4_R, KC_TRNS, 
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AUD_T_L, AUD_T_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

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
     * ,------------------------------------------------------------------------------------------------------------.
     * | Reset | Reset | Debug | RGB_tog | RGB_mod | RGB_hui | RGB_hud | RGB_sai | RGB_sad | RGB_vai | RGB_vad |    |
     * |-------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+----|
     * |       |   NO  |   NO  |    NO   |    NO   | LAG_nrm | LAG_swp | COLEMAK |   GAME  |  QWERTY | PLOVER  |    |
     * |-------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+----|
     * |       |   NO  |   NO  |    NO   |    NO   |   NO    |    NO   |         |         |         |         |    | 
     * |-------+-------+-------+---------+---------+---------+---------+---------+---------+---------+---------+----|
     * |       |       |       |         |         |  PrScr  |   Ins   |         |         |         |         |    |
     * `------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_4x12_wrap(QK_BOOT, ADJ_R2_L, ADJ_R2_R, KC_TRNS,
				  KC_TRNS, ADJ_R3_L, ADJ_R3_R, KC_TRNS,
				  KC_TRNS, ADJ_R4_L, ADJ_R4_R, KC_TRNS,
				  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJ_T_L, ADJ_T_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Navigation
     * ,-----------------------------------------------------------------------------------------------------.
     * |    Tab   |  NO | M_WH_L |   M_up |  M_WH_R | M_WH_U | M_BT4 | M_BT1 | M_BT3 | M_BT2 | M_BT5 | PrScr | 
     * |-----+--------+--------+---------+--------+----------+-------+-------+-------+-------+-------+-------|
     * | Ctrl/Esc |  NO | M_left |  M_dwn | M_right | M_WH_D |   NO  |  Left |  Down |   Up  | Right | Shift |
     * |-----+--------+--------+---------+--------+----------+-------+-------+-------+-------+-------+-------|
     * |          |     |  LAlt  |  LCtrl |  LShift |  LGui  |  Tab  |  Home |  PgDn |  PgUp |  End  |       |
     * |-----+--------+--------+---------+--------+----------+-------+-------+-------+-------+-------+-------| 
     * |          |     |        |        |         |   Spc  |       |  NAV  |  Del  |       |       |       |
     * `-----------------------------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_4x12_wrap(KC_TAB, NAV_R2_L, NAV_R2_R, KC_PSCR,
			       LCTL_T(KC_ESC), NAV_R3_L, NAV_R3_R, KC_RSFT,
			       KC_TRNS, NAV_R4_L, NAV_R4_R, KC_TRNS,
			       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NAV_T_L, NAV_T_R, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Number
     * ,--------------------------------------------------------------------------------------.
     * |     NO   | NumLock |  Home |  Up  |  End  |  PgUp | P= |  P7 | P8 | P9 | PEnt |  P+  |
     * |----------+---------+-------+------+-------+-------+----+-----+----+----+------+------|
     * | Ctrl/Esc |    NO   |  Left | Down | Right | PgDwn | P. |  P4 | P5 | P6 |  Tab |  P,  |
     * |----------+---------+-------+------+-------+-------+----+-----+----+----+------+------|
     * |   Shift  |    P/   |   P*  |  P-  |   P+  |   P,  | P0 |  P1 | P2 | P3 |  Del |  P-  | 
     * |----------+---------+-------+------+-------+-------+----+-----+----+----+------+------|
     * |    LGui  |         |       |      |   NO  |  Spc  | BS | NUM |  , | P. |      | LAlt |
     * `--------------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_ortho_4x12_wrap(KC_NO, NUM_R2_L, NUM_R2_R, KC_KP_PLUS,
			       LCTL_T(KC_ESC), NUM_R3_L, NUM_R3_R, KC_PAST,
			       KC_LSFT, NUM_R4_L, NUM_R4_R, KC_PMNS,
			       KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, NUM_T_L, NUM_T_R, KC_PCMM, KC_PDOT, KC_TRNS, KC_LALT)
};
#endif /* USE_WIDE_MOD */
