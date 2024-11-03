/* Copyright 2023 Brian Low
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
#include "lib/layer_status/layer_status.h"

// QWERTY
#define ESC_LCT     MT(MOD_LCTL, KC_ESC)
#define FN_MO13     QK_TRI_LAYER_LOWER
#define FN_MO23     QK_TRI_LAYER_UPPER
// RAISE
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
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ESC_LCT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                     KC_NO,   KC_LALT, KC_LGUI, FN_MO13, KC_SPC,    KC_ENT,  FN_MO23, KC_RCMD, KC_RALT, KC_NO
),
[_LOWER] = LAYOUT(
    KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    ESC_LCT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,     KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_RAISE] = LAYOUT(
    KC_F12,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_NO,   RSE_1,  RSE_2,   RSE_3,   RSE_4,   RSE_5,                       RSE_6,   RSE_7,   RSE_8,   RSE_9,   RSE_0,   KC_TRNS,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   RSE_MNS, RSE_EQL, RSE_LBR, RSE_RBR, RSE_BSL, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[_ADJUST] = LAYOUT(
    KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

#if defined(OLED_ENABLE)
bool oled_task_user(void) {
    render_layer_status();
    return false;
}
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif
