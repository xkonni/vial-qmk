// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "lib/layer_status/layer_status.h"

// QWERTY
#define ESC_LCT     MT(MOD_LCTL, KC_ESC)
#define QUO_LWR     LT(_LOWER, KC_QUOT)
#define Z_LALT      MT(MOD_LALT, KC_Z)
#define LT1_LGU     LM(1, MOD_LGUI)
#define FN_MO13     QK_TRI_LAYER_LOWER
#define FN_MO23     QK_TRI_LAYER_UPPER
// RAISE
#define RSE_GRV     LSFT(KC_GRAVE)
#define RSE_1       LSFT(KC_1)
#define RSE_2       LSFT(KC_2)
#define RSE_3       LSFT(KC_3)
#define RSE_4       LSFT(KC_4)
#define RSE_5       LSFT(KC_5)
#define RSE_6       LSFT(KC_6)
#define RSE_7       LSFT(KC_7)
#define RSE_8       LSFT(KC_8)
#define RSE_9       LSFT(KC_9)
#define RSE_0       LSFT(KC_0)
#define RSE_MNS     LSFT(KC_MINS)
#define RSE_EQL     LSFT(KC_EQL)
#define RSE_LBR     LSFT(KC_LBRC)
#define RSE_RBR     LSFT(KC_RBRC)
#define RSE_BSL     LSFT(KC_BSLS)

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
           ESC_LCT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, QUO_LWR,
           KC_LSFT, Z_LALT,  KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                      LT1_LGU, FN_MO13, KC_SPC,       KC_ENTER,FN_MO23, KC_RALT
),
[_LOWER] = LAYOUT(
  KC_TRNS, KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, KC_TRNS,
           KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,   KC_NO,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_TRNS,
           KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_PSCR,
                                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),
[_RAISE] = LAYOUT(
  KC_TRNS, RSE_GRV, RSE_1,   RSE_2,   RSE_3,   RSE_4,   RSE_5,        RSE_6,   RSE_7,   RSE_8,   RSE_9,   RSE_0,   KC_TRNS, KC_TRNS,
           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        RSE_MNS, RSE_EQL, RSE_LBR, RSE_RBR, RSE_BSL, KC_NO,
                                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
),
[_ADJUST] = LAYOUT(
  KC_TRNS, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_TRNS,
           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F12,
           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                      KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();
        return false;
    }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
