// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer {
    _BASE, _SYM, _FN, _MOVE

};

#define LT3_ESC LT(_MOVE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    // [0] = LAYOUT_ortho_4x10(
    //     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    //     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,    KC_DOT,    KC_SLASH,
    //     KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9
    // )
    [_BASE] = LAYOUT_ortho_4x10(
        KC_Q,    KC_W,         KC_E,         KC_R,         KC_T,           KC_Y,    KC_U,             KC_I,            KC_O,    KC_P,
        KC_A,    ALT_T(KC_S),  CTL_T(KC_D),  CMD_T(KC_F),  KC_G,           KC_H,    KC_J,             KC_K,            KC_L,    KC_SCLN,
        KC_Z,    KC_X,         KC_C,         KC_V,         KC_B,           KC_N,    CMD_T(KC_M),  CTL_T(KC_COMMA),     ALT_T(KC_DOT),  KC_SLSH,
        KC_LSFT, TT(_FN),      KC_BSPC,      LT(_MOVE, KC_ENT), LGUI_T(KC_TAB), KC_SPC,  LT(_SYM, KC_ESC), LSFT_T(KC_QUOT), KC_LEFT, KC_RGHT
    ),

    [_SYM] = LAYOUT_ortho_4x10( /* Right */
        KC_HASH,    KC_2,          KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_AT,
        KC_BSLS,    KC_UNDERSCORE, KC_LPRN,  KC_RPRN,  KC_1,     KC_0,    KC_PLUS,  KC_MINUS, KC_EQUAL, KC_ASTR,
        KC_EXLM,    KC_AMPR,       KC_LBRC,  KC_RBRC,  KC_CIRC,  KC_DLR,  KC_LCBR,  KC_RCBR,  KC_PERC,  KC_PIPE,
        KC_NO,      KC_NO,         KC_GRV,   KC_TILDE, KC_DQUO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,    QK_BOOT
    ),
    [_MOVE] = LAYOUT_ortho_4x10( /* Tab */
        G(KC_Q),  G(KC_W),  G(KC_TAB),  G(KC_GRV),  KC_NO,    KC_NO,    KC_NO,   KC_HOME,       KC_END,    KC_PSCR,
        _______,  _______,  _______,    _______,    _______,  KC_LEFT,  KC_DOWN, KC_UP,         KC_RIGHT,  KC_TILDE,
        _______,  _______,  _______,    _______,    _______,  _______,  KC_NO,   C(S(KC_TAB)),  C(KC_TAB), KC_CAPS,
        _______,  _______,  _______,    _______,    _______,  _______,  _______, KC_CAPS,       _______,   _______
    ),

    // [_FN] = LAYOUT_ortho_4x10(
    // _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F12,_______,
    // _______, _______, G(KC_F9), G(KC_F4), _______, _______, KC_F4, KC_F5, KC_F6, KC_F11, _______,
    // _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F10, _______,
    // _______, _______, _______, _______, _______,   _______,   TG(_SYM), RGB_TOG, KC_VOLD, KC_VOLU, RGB_VAD
    // ),
};
