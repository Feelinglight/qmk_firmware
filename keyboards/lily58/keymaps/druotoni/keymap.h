#pragma once

#include QMK_KEYBOARD_H

const uint16_t PROGMEM MO3_combo[] = {KC_BSPC, MO(2), COMBO_END};
const uint16_t PROGMEM left_square_bracket_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM right_square_bracket_combo[] = {KC_H, KC_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(MO3_combo, MO(4)),
    COMBO(left_square_bracket_combo, KC_LEFT_BRACKET),
    COMBO(right_square_bracket_combo, KC_RIGHT_BRACKET)
};

// --------------- key overrides ---------------

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// const key_override_t *key_overrides[] = {
// &delete_key_override
// };
