#include QMK_KEYBOARD_H

/// For more documentation info, check out
/// @see https://docs.qmk.fm/#/feature_macros

//clang-format: off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [0] = LAYOUT(
        KC_MPLY,        KC_MPRV, KC_MNXT,       XXXXXXX,
        KC_MSEL,        XXXXXXX, KC_CALCULATOR, XXXXXXX,
        XXXXXXX,        XXXXXXX, XXXXXXX,       XXXXXXX,
        KC_MY_COMPUTER,          XXXXXXX,       XXXXXXX
    )
};
//clang-format: on

enum encoder_pos {
    TOP = 0,
    MIDDLE = 1,
    BOTTOM = 2
};

///
/// @brief Handles the rotary encoders
///
/// @param[in]  index      The index of the rotary being manipulated.
/// @param[in]  clockwise  If the motion is clockwise or counter clockwise.
///
bool
encoder_update_user(uint8_t index, bool clockwise)
{
    switch(index) {
        case 0:
            if (clockwise) {
                // Example of using tap_code which lets you use keycodes outside
                // of the keymap
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;

        case 1:
            if (clockwise) {
                // Cycle through the RGB hue just for kicks and giggles
                rgblight_increase_hue();
                tap_code16(KC_RIGHT);
            } else {
                rgblight_decrease_hue();
                tap_code16(KC_LEFT);
            }
            break;

        case 2:
            if (clockwise) {
                tap_code16(KC_DOWN);
            } else {
                tap_code16(KC_UP);
            }
            break;
    }

    return false;
}
