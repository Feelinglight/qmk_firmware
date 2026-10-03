#pragma once

#include QMK_KEYBOARD_H

const uint16_t PROGMEM MO5_combo[]                  = {KC_BSPC, KC_N, COMBO_END};
const uint16_t PROGMEM left_square_bracket_combo[]  = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM right_square_bracket_combo[] = {KC_H, KC_J, COMBO_END};

combo_t key_combos[] = {COMBO(MO5_combo, MO(5)), COMBO(left_square_bracket_combo, LCTL(KC_INS)), COMBO(right_square_bracket_combo, LSFT(KC_INS))};

const uint16_t PROGMEM encoder_map[][2][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [2] = {ENCODER_CCW_CW(MS_UP, MS_DOWN), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [3] = {ENCODER_CCW_CW(MS_LEFT, MS_RGHT), ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
    [4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [5] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
};

// --------------- key overrides ---------------

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// const key_override_t *key_overrides[] = {
// &delete_key_override
// };
