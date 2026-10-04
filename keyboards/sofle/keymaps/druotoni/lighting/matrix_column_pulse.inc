RGB_MATRIX_EFFECT(MATRIX_COLUMN_PULSE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/* Обычные столбцы каждой половины разделены 16 единицами координат.
 * Крайние клавиши больших пальцев относятся к ближайшему столбцу. */
static uint8_t matrix_pulse_column(uint8_t x) {
    if (x < 112) {
        return x >= 80 ? 5 : (x + 8) / 16;
    }

    return x <= 144 ? 6 : 6 + (x - 144 + 8) / 16;
}

static bool MATRIX_COLUMN_PULSE(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    /* При начальной скорости 100 импульс длится 500 мс.
     * Клавиши изменения скорости меняют длительность на 32 мс за шаг. */
    const uint16_t duration = 700 - 2 * rgb_matrix_config.speed;
    const uint8_t  value    = rgb_matrix_config.hsv.v;

    for (uint8_t i = led_min; i < led_max; i++) {
        if (!(g_led_config.flags[i] & LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, 0, 0, 0);
            continue;
        }

        const uint8_t column = matrix_pulse_column(g_led_config.point[i].x);
        uint16_t      age    = UINT16_MAX;

        /* Повторное нажатие в столбце перезапускает его импульс. */
        for (uint8_t j = 0; j < g_last_hit_tracker.count; j++) {
            if (column == matrix_pulse_column(g_last_hit_tracker.x[j]) && g_last_hit_tracker.tick[j] < age) {
                age = g_last_hit_tracker.tick[j];
            }
        }

        uint8_t green = 0;
        if (age < duration) {
            /* y=7 — верхний ряд; y=89 — импульс миновал нижние клавиши. */
            const int16_t head     = 7 + (uint32_t)age * 82 / duration;
            const int16_t distance = head - g_led_config.point[i].y;
            if (distance >= 0 && distance < 24) {
                green = (uint16_t)value * (24 - distance) / 24;
            }
        }

        rgb_matrix_set_color(i, 0, green, 0);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif
