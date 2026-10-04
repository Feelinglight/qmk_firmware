#include QMK_KEYBOARD_H

/* Нижняя подсветка белая во всех активных режимах RGB и гаснет после
 * бездействия. При выключении RGB или переходе в сон её отключает QMK. */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint8_t value = last_input_activity_elapsed() > SOFLE_UNDERGLOW_TIMEOUT_MS ? 0 : rgb_matrix_config.hsv.v;

    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
            rgb_matrix_set_color(i, value, value, value);
        }
    }

    return true;
}
