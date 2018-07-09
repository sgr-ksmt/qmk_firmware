#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define XXXXXXX KC_NO
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | \ |    | 1  ! | 2  @ | 3  # | 4  $ | 5  % | \  | |           | \  | | 6  ^ | 7  & | 8  * | 9  ( | 0  ) |  -  _  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | `  ~ |           | '  " |   Y  |   U  |   I  |   O  |   P  |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | = +  |           | `  ~ |   N  |   M  | ,  < | .  > | /  ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | L2   |  L1  | Alt  | Cmd  | EISU |                                       | KANA | Cmd  | [  { | ]  } | L2 \ |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |space |      |      |       |  Up  |        |Space |
 *                                 |   /  | \ |  |------|       |------|  = +   |  /   |
 *                                 |  L1  |      |      |       | Down |        |  L2  |
 *                                 `--------------------'       `----------------------'
 *  N ... For thunderbird
 *  : ... In case ErgoDox EZ is detected as JIS keyboard
 *  PgDn ... Used as IME on/off on Windows(VMWare Fusion)
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_BSLS,        KC_1,           KC_2,    KC_3,    KC_4,     KC_5,   KC_BSLS,
        KC_TAB,         KC_Q,           KC_W,    KC_E,    KC_R,     KC_T,   KC_GRV,
        CTL_T(KC_ESC),  KC_A,           KC_S,    KC_D,    KC_F,     KC_G,
        KC_LSFT,        KC_Z,           KC_X,    KC_C,    KC_V,     KC_B,   KC_EQL,
        LT(MDIA,KC_NO), LT(SYMB,KC_NO), KC_LALT, KC_LGUI, KC_LANG2,
                                                       XXXXXXX, XXXXXXX,
                                                                XXXXXXX,
                                     LT(SYMB, KC_SPC), KC_BSLS, XXXXXXX,
        // right hand
             KC_BSLS, KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_MINS,
             KC_QUOT, KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
                      KC_H,   KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
             KC_GRV,  KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              KC_LANG1, KC_RGUI, KC_LBRC, KC_RBRC, LT(MDIA,KC_BSLS),
             KC_LEFT, KC_RIGHT,
             KC_UP,
             KC_DOWN, KC_EQL,   KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   (  |   )  |   |  |      |           |      |      |      |      |  +   |   =  |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   {  |   }  |   &  |------|           |------| Left | Down | Up   | Right|   :  |  Enter |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   *  |      |           |      |      |      |      |      |   ↑  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |   ←  |   ↓  |   →  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_PIPE, _______,
       _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, KC_AMPR,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_ASTR, _______,
       _______, _______, _______, _______, _______,
                                       _______, _______,
                                                _______,
                               _______,_______, _______,
       // right hand
       _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
       _______, _______, _______, _______, KC_PLUS,  KC_EQL,  KC_BSPC,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_COLN, KC_ENT,
       KC_PGUP, _______, _______, _______, _______,  KC_UP,   _______,
                         _______, _______, KC_LEFT,  KC_DOWN, KC_RIGHT,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Prev |VolDn |VolUp | Next |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Rclk | Lclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       RESET,   _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN2, KC_BTN1,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MUTE, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
