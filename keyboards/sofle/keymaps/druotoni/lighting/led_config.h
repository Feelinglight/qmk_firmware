#pragma once

/* Реакция на нажатия и синхронизация половинок. */
#define RGB_MATRIX_KEYPRESSES
#define SPLIT_TRANSPORT_MIRROR
#define LED_HITS_TO_REMEMBER 24

/* Дополнительный режим: цифровой дождь. */
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define RGB_DIGITAL_RAIN_DROPS 12

/* Режим по умолчанию, предел яркости и начальная скорость. */
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_MATRIX_COLUMN_PULSE
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#define RGB_MATRIX_DEFAULT_SPD 100

/* Таймаут нижней подсветки: 15 минут бездействия. */
#define SOFLE_UNDERGLOW_TIMEOUT_MS (15UL * 60UL * 1000UL)
