#include QMK_KEYBOARD_H

enum layers { _BASE, _LOWER, _RAISE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_GRV,
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LALT, KC_LGUI, KC_LCTL, MO(_LOWER), KC_ENT,    KC_SPC, MO(_RAISE), KC_RCTL, KC_RGUI, KC_RALT
    ),
    [_LOWER] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, KC_END,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_LOWER] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_UP, KC_DOWN)   },
    [_RAISE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(GP12);
}

static bool knob_was_down = false;

void housekeeping_task_user(void) {
    bool knob_down = !gpio_read_pin(GP12);
    if (knob_down && !knob_was_down) {
        tap_code(KC_MUTE);
    }
    knob_was_down = knob_down;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("LAYER\n"), false);
        switch (get_highest_layer(layer_state)) {
            case _BASE:  oled_write_P(PSTR("Base \n"), false); break;
            case _LOWER: oled_write_P(PSTR("Lower\n"), false); break;
            case _RAISE: oled_write_P(PSTR("Raise\n"), false); break;
            default:     oled_write_P(PSTR("???  \n"), false);
        }
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.caps_lock ? PSTR("CAPS \n") : PSTR("     \n"), false);
    } else {
        oled_write_P(PSTR("WPM\n"), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}
#endif