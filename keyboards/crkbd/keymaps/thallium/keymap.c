/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer {
    _BASE, _SYM, _FN, _MOVE

};

enum TD{
    TD_CTRL_PAUSE,
};

// Tap Dance definitions
/* qk_tap_dance_action_t tap_dance_actions[] = {                     */
/*     // Tap once for Escape, twice for PAUSE(kill program)         */
/*     [TD_CTRL_PAUSE] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_PAUSE), */
/* };                                                                */

#define LT3_ESC LT(3, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT3_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MT(MOD_LSFT,KC_TAB),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  MT(MOD_RSFT,KC_QUOT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LCTL, TT(_FN),     KC_SPC,   MO(1), KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_HASH,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,   KC_AT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LGUI(KC_TAB), KC_BSLASH, KC_UNDERSCORE, KC_LPRN, KC_RPRN, KC_1,           KC_0, KC_PLUS, KC_MINUS, KC_EQUAL, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LGUI(KC_LSFT), KC_EXLM,  KC_AMPR,  KC_LBRC,  KC_RBRC,  KC_CIRC,  KC_DLR,  KC_LCBR,  KC_RCBR,  KC_PERC,  KC_PIPE,  S(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
    [_MOVE] = LAYOUT( /* Tab */
    KC_ESC,  KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, _______, _______, KC_HOME, KC_END, KC_PSCR, KC_DELETE,
    _______,  _______,_______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_TILDE, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, KC_F16, KC_F14, KC_F15, KC_CAPS, _______,
                                        KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
    ),

//[2] = LAYOUT_split_3x6_3(
////,-----------------------------------------------------.                    ,-----------------------------------------------------.
//     KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
////|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
////|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
////|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                        KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
//                                    //`--------------------------'  `--------------------------'
//),
    [_FN] = LAYOUT( 
    RESET, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F12,_______,
    TG(_MOVE),RGB_TOG, RGB_MOD, G(KC_F9), G(KC_F4), _______, _______, KC_F4, KC_F5, KC_F6, KC_F11, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F10, _______,
                                    KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
    /* _______, _______, _______, _______, _______,   _______,   TG(_SYM), RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD */
    ),

//[3] = LAYOUT_split_3x6_3(
////,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
////|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
////|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
////|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                        KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
//                                    //`--------------------------'  `--------------------------'
//)
};
