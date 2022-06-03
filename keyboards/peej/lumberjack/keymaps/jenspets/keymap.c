/* Copyright 2020 Paul James
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

enum layers {
  _COLEMAK = 0,
  _QWERTY,
  _FNC
};

#define FN MO(_FNC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,------------------------------------------. ,-----------------------------------------.
 * |   `   |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | AltG |
 * |-------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  Tab  |  Q   |  W   |  F   |  P   |  B   | |  J   |  L   |  U   |  Y   |  ;   |   \  |
 * |-------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc/C |  A   |  R   |  S   |  T   |  G   | |  M   |  N   |  E   |  I   |  O   |  '   |
 * |-------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Sh/Ca |  Z   |  X   |  C   |  D   |  V   | |  K   |  H   |  ,   |  .   |  /   | Entr |
 * |-------+------+------+------+------+------| |------+------+------+------+------+------|
 * |  Ctrl | QWER | Cmd  | Alt  | SFn  | Spac | | BkSp |  Fn  | Left | Down |  Up  | Rght |
 * `------------------------------------------' `-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_5x12(
    KC_GRV,          KC_1,        KC_2,    KC_3,    KC_4,               KC_5,   KC_6,    KC_7, KC_8,    KC_9,    KC_0,    KC_RALT,
    KC_TAB,          KC_Q,        KC_W,    KC_F,    KC_P,               KC_B,   KC_J,    KC_L, KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    CTL_T(KC_ESC),   KC_A,        KC_R,    KC_S,    KC_T,               KC_G,   KC_M,    KC_N, KC_E,    KC_I,    KC_O,    KC_QUOT,
    LSFT_T(KC_CAPS), KC_Z,        KC_X,    KC_C,    KC_D,               KC_V,   KC_K,    KC_H, KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,         DF(_QWERTY), KC_LGUI, KC_LALT, LM(_FNC, MOD_LSFT), KC_SPC, KC_BSPC, FN,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
 
/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |   `  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | RAlt |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Shft |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  ,   |  .   |  /   | Entr |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl | COLE | Cmd  | Alt  | SFn  | Spac | | BkSp |  Fn  | Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_GRV,          KC_1,         KC_2,    KC_3,    KC_4,               KC_5,   KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_RALT,
    KC_TAB,          KC_Q,         KC_W,    KC_E,    KC_R,               KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
    CTL_T(KC_ESC),   KC_A,         KC_S,    KC_D,    KC_F,               KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_T(KC_CAPS), KC_Z,         KC_X,    KC_C,    KC_V,               KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,         DF(_COLEMAK), KC_LGUI, KC_LALT, LM(_FNC, MOD_LSFT), KC_SPC, KC_BSPC, FN,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Function
* ,------------------------------------------. ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |   {  | |   }  |      |      |      |  Ins |  F12 |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |   (  | |   )  |   -  |   =  |      | Home | PgUp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |   [  | |   ]  |ISO # |ISO / |      |  End | PgDn |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |  Del |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------' `-----------------------------------------'
 */

[_FNC] = LAYOUT_ortho_5x12(
    _______,    KC_F1,   KC_F2,   KC_F3,  KC_F4,      KC_F5,      KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_F10, KC_F11,
    _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), _______, _______ , _______,  KC_INS, KC_F12,
    _______, _______, _______, _______, _______,    S(KC_9),    S(KC_0), KC_MINS,   KC_EQL, _______, KC_HOME, KC_PGUP,
    _______, _______, _______, _______, _______,    KC_LBRC,    KC_RBRC, KC_NUHS,  KC_NUBS, _______,  KC_END, KC_PGDN,
    _______, _______, _______, _______, _______,    _______,     KC_DEL, _______,  KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
)

};
