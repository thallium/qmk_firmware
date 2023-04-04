/* Copyright 2018 Carlos Filoteo
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

enum layer {
    _BASE, _SYM, _FN, _MOVE

};

#define LT3_ESC LT(3, KC_ESC)

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 2, HSV_RED}
// );
//
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {6, 1, HSV_PINK}
// );
// // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {4, 1, HSV_MAGENTA}
// );
// // Light LEDs 13 & 14 in green when keyboard layer 3 is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {3, 2, HSV_CYAN}
// );
// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_capslock_layer,
//     my_layer1_layer,    // Overrides caps lock layer
//     my_layer2_layer,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
// );
//
// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// }
//
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }
//
// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
//     rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _MOVE));
//     return state;
// }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LT3_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLSH, KC_QUOT,
  KC_NO, TT(_FN), KC_LGUI, KC_LALT,  KC_LCTL, LGUI_T(KC_SPC), MO(1), RSFT_T(KC_LEFT), KC_DOWN, KC_UP, KC_RGHT
),

[_SYM] = LAYOUT( /* Right */
  _______, KC_HASH,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_AT,    _______,
  LGUI(KC_TAB), KC_BSLS, KC_UNDERSCORE, KC_LPRN, KC_RPRN,  KC_1, KC_0, KC_PLUS, KC_MINUS, KC_EQUAL, KC_ASTR, _______,
  LGUI(KC_LSFT), KC_EXLM,  KC_AMPR,  KC_LBRC,  KC_RBRC,  KC_CIRC,  KC_DLR,  KC_LCBR,  KC_RCBR,  KC_PERC,  KC_PIPE,  S(KC_QUOT),
  TG(_MOVE), _______, _______, _______, _______,  _______,  _______, KC_COMM, KC_DOT,  KC_SLSH, QK_REBOOT
),


// [_LAUNCH] = LAYOUT(
//   RESET , _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F12,_______,
//   _______, _______, _______, G(KC_F9), G(KC_F4), _______, _______, LE, GE, KC_F6, KC_F11, _______,
//   _______, _______, _______, _______, _______, _______, _______,  KC_F1, KC_F2, KC_F3, KC_F10, _______,
//   RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, G(KC_F11), _______, _______, _______, _______, _______
// ),


[_MOVE] = LAYOUT( /* Tab */
  KC_ESC,  G(KC_Q) ,G(KC_W),G(KC_TAB),G(KC_GRV), KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_PSCR, A(KC_BSPC),
  _______,  _______,_______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_TILDE, KC_GRV,
  _______, _______, _______, _______, _______, _______, _______, KC_NO, C(S(KC_TAB)),C(KC_TAB), KC_CAPS, _______,
  _______, _______, _______, _______, _______,     LGUI(KC_SPACE),   _______, _______, _______, _______, _______
),

[_FN] = LAYOUT(
  QK_REBOOT, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F12,_______,
  TG(_MOVE),_______, _______, G(KC_F9), G(KC_F4), _______, _______, KC_F4, KC_F5, KC_F6, KC_F11, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F10, _______,
  _______, _______, _______, _______, _______,   _______,   TG(_SYM), RGB_TOG, KC_VOLD, KC_VOLU, RGB_VAD
),
};
