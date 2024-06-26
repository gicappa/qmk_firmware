#include QMK_KEYBOARD_H

// helpers
#define _______ KC_TRNS

// layers
#define BASE 0
#define FNKC 1
#define CODE 2
#define ONAN 3
#define ARRW 4
#define MEDI 5

// layer selectors
#define _L1_Q   LT(FNKC, KC_Q)
#define _L1_P   LT(FNKC, KC_P)
#define _L2_Z   LT(CODE, KC_Z)
#define _L2_SLA LT(CODE, KC_SLASH)
#define _L3_SPC LT(ONAN, KC_SPACE)
#define _L4_A   LT(ARRW, KC_A)
#define _L5_FN  TT(MEDI)
#define _SPAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACE_AND_LAYER_3 _L3_SPC

//tap-mod
#define _F MT(MOD_LSFT, KC_F)
#define _J MT(MOD_RSFT, KC_J)
#define _D MT(MOD_LALT, KC_D)
#define _K MT(MOD_RALT, KC_K)
#define _S MT(MOD_LCTL, KC_S)
#define _L MT(MOD_RCTL, KC_L)
#define _E MT(MOD_LGUI, KC_E)
#define _I MT(MOD_RGUI, KC_I)
#define _R MT(MOD_LALT, KC_R)
#define _U MT(MOD_RALT, KC_U)

//shortcut for common commands
#define _CMD_Q   LGUI(KC_Q)
#define _CMD_W   LGUI(KC_W)
#define _COPY    LGUI(KC_C)
#define _PASTE   LGUI(KC_V)
#define _UNDO    LGUI(KC_Z)
#define _CUT     LGUI(KC_X)
#define _ALL     LGUI(KC_A)
#define _SAVE    LGUI(KC_S)
#define _OPEN    LGUI(KC_O)
#define _FIND    LGUI(KC_F)

// CMD+TAB and CMD+SHIFT+TAB definitions
enum custom_keycodes {
    KC_GUI_TAB = SAFE_RANGE,
    KC_GUI_SHIFT_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base (QWERTY) Layer [BASE] active by default
     * ,----------------------------------------------------------------------------------------------------.
     * | ` ~ |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |   Bkspc  |
     * |----------------------------------------------------------------------------------------------------+
     * | Tab    |Q^FNKC|   W  | E\cmd| R\alt|   T  |   Y  |U\Ralt|I\Rcmd|   O  |P^FNKC|   [  |   ]  |   \   |
     * |----------------------------------------------------------------------------------------------------+
     * | Caps    |A^CURS|S\ctl |D\alt |F\sft |   G  |   H  |J\Rsft|K\Ralt|L\Rctl|   ;  |   '  |    Enter    |
     * |----------------------------------------------------------------------------------------------------+
     * |           |Z^CODE|   X  |   C  | V    |   B  |   N  |   M  |   ,  |   .  |/^CODE|                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |             Space\cmd                   |       |       |       | Fn^MISC|
     * `----------------------------------------------------------------------------------------------------'
     */
	LAYOUT_60_ansi(
		QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  _L1_Q,   KC_W,    _E,      _R,      KC_T,    KC_Y,    _U,      _I,      KC_O,    _L1_P,   KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, _L4_A,   _S,      _D,      _F,      KC_G,    KC_H,    _J,      _K,      _L,      KC_SCLN, KC_QUOT, KC_ENT,
		XXXXXXX, _L2_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  _L2_SLA, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, _SPAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACE_AND_LAYER_3, XXXXXXX, XXXXXXX, XXXXXXX, _L5_FN
    ),

   /* Functions Layer [FNKC] active by holding Q or P
     * ,----------------------------------------------------------------------------------------------------.
     * | ` ~ |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |     DEL  |
     * |----------------------------------------------------------------------------------------------------+
     * |        |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F4  |      |      |QK_BOOT|
     * |----------------------------------------------------------------------------------------------------+
     * |         |      |      |      |      |      |      |  F5  |  F6  |  F7  |  F8  |      |             |
     * |----------------------------------------------------------------------------------------------------+
     * |           |      |      |      |      |      |      |  F9  | F10  | F11  | F12  |                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |                                         |       |       |       |        |
     * `----------------------------------------------------------------------------------------------------'
     */
	LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
		_______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, QK_BOOT,
		_______, _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
		_______, _______, _______,                   _______,                            _______, _______, _______, _______
    ),

    /* Coding Layer [CODE] active by holding Z or /
     * ,----------------------------------------------------------------------------------------------------.
     * | ` ~ |      |      |      |      |      |      |      |      |      |      |      |      |    DEL   |
     * |----------------------------------------------------------------------------------------------------+
     * |        |      |  &   |  ~   |  `   |      |      |  [   |  +   |  ]   |      |      |      |QK_BOOT|
     * |----------------------------------------------------------------------------------------------------+
     * |         |      |  $   |  \   |  |   |      |      |  (   |  =   |  )   |      |      |             |
     * |----------------------------------------------------------------------------------------------------+
     * |           |      |  %   |  ^   |  *   |      |      |  {   |  -   |  }   |      |                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |                                         |       |       |       |        |
     * `----------------------------------------------------------------------------------------------------'
     */
	LAYOUT_60_ansi(
		QK_GESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
		_______, _______, KC_AMPR, KC_TILD, KC_GRV,  _______, _______, KC_LBRC, KC_PLUS, KC_RBRC, _______, _______, _______, QK_BOOT,
		_______, _______, KC_DLR,  KC_BSLS, KC_PIPE, _______, _______, KC_LPRN, KC_EQL,  KC_RPRN, _______, _______, _______,
		_______, _______, KC_PERC, KC_CIRC, KC_ASTR, _______, _______, KC_LCBR, KC_MINS, KC_RCBR, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______, _______, _______
    ),

    /* One Hand Layer [ONAN] active by holding Z or /
     * ,----------------------------------------------------------------------------------------------------.
     * | ` ~ |      |      |      |      |      |      |      |      |      |      |      |      |    DEL   |
     * |----------------------------------------------------------------------------------------------------+
     * |        |CMD+Q |CMD+W |CS+TAB|CM+TAB|  `   |      |      |      |      |      |      |      |QK_BOOT|
     * |----------------------------------------------------------------------------------------------------+
     * |         |CMD+A |CMD+S |CMD+O |CMD+F |  E   |      |      |      |      |      |      |             |
     * |----------------------------------------------------------------------------------------------------+
     * |           |CMD+Z |CMD+X |CMD+C |CMD+V |      |      |      |      |      |      |                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |                                         |       |       |       |        |
     * `----------------------------------------------------------------------------------------------------'
     */
	LAYOUT_60_ansi(
		KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
		_______, _CMD_Q, _CMD_W,  G_S_TAB, GUI_TAB, KC_GRV,  _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
		_______, _ALL,   _SAVE,   _OPEN,   _FIND,   KC_E,    _______, _______, _______, _______, _______, _______, _______,
		_______, _UNDO,  _CUT,    _COPY,   _PASTE,  _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______,                  _______,                            _______, _______, _______, _______
    ),

    /* Arrows Layer [ARRW] active by holding A
     * ,----------------------------------------------------------------------------------------------------.
     * |     |      |      |      |      |      |      |      |      |      |      |      |      |          |
     * |----------------------------------------------------------------------------------------------------+
     * |        |      |      |      |      |      |      |PAG UP|  UP  |PAG DN|PrnScr|ScrLck| Pause|       |
     * |----------------------------------------------------------------------------------------------------+
     * |         |      |      |      |      |      |      | LEFT | DOWN | RIGHT| RIGHT|      |             |
     * |----------------------------------------------------------------------------------------------------+
     * |           |      |      |      |      |      |      | HOME |  INS |  END |      |                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |                  ENTER                  |       |       |       |        |
     * `----------------------------------------------------------------------------------------------------'
     */
	LAYOUT_60_ansi(
		KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
		_______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_UP,   KC_PGUP, KC_PSCR, KC_SCRL, KC_PAUS, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_INS,  KC_END,  _______, _______,
		_______, _______, _______,                   KC_ENT,                             _______, _______, _______, _______
    ),

     /* Media/Lights [MEDI] active by 2 taps on CTRL right
     * ,----------------------------------------------------------------------------------------------------.
     * |     |      |      |      |      |      |      |      |      |      |      |      |      |          |
     * |----------------------------------------------------------------------------------------------------+
     * |        | RGB T|  Mode| Hue+ | Hue- | Sat+ | Sat- | Bri+ | Bri- |      |      |      |      |       |
     * |----------------------------------------------------------------------------------------------------+
     * |         |      |      |      |      |      |      |      |      |      |      |      |             |
     * |----------------------------------------------------------------------------------------------------+
     * |           |      |      |Blit -|Blit T|Blit +|Blit C|      |      |      |      |                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |                                         |       |       |       |        |
     * `----------------------------------------------------------------------------------------------------'
     * RGB T = RGB Toggle / Mode  = RGB mode
     * Blit = Backlight / Blit T = Toggle / Blit C = Cycle through levels
     */
	LAYOUT_60_ansi(
		KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, BL_DOWN,  BL_TOGG, BL_UP,  BL_STEP, _______, _______, _______, _______, _______,
		_______, _______, _______,                   _______,                            _______, _______, _______, _______
    ),

    /* Blank
     * ,----------------------------------------------------------------------------------------------------.
     * |     |      |      |      |      |      |      |      |      |      |      |      |      |          |
     * |----------------------------------------------------------------------------------------------------+
     * |        |      |      |      |      |      |      |      |      |      |      |      |      |       |
     * |----------------------------------------------------------------------------------------------------+
     * |         |      |      |      |      |      |      |      |      |      |      |      |             |
     * |----------------------------------------------------------------------------------------------------+
     * |           |      |      |      |      |      |      |      |      |      |      |                  |
     * |----------------------------------------------------------------------------------------------------+
     * |       |        |        |                                         |       |       |       |        |
     * `----------------------------------------------------------------------------------------------------'
     */

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_GUI_TAB:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case KC_GUI_SHIFT_TAB:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_TAB);

            } else {
                unregister_code(KC_TAB);
            }
            return false;
    }
    return true;
}
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

//     switch (id) {
//         case KC_GUI_TAB:
//             return (record->event.pressed ? MACRO( D(LGUI), D(TAB), END ) : MACRO( U(TAB), END ));
//         case KC_GUI_SHIFT_TAB:
//             return (record->event.pressed ? MACRO( D(LGUI), D(LSFT), D(TAB), END ) : MACRO( U(TAB), END ));
//     }
//     return MACRO_NONE;
// }
