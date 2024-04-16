#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
  SS_LT, SS_GT, SS_HELLO
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)
#define KC_NAIN LT(_NAV, KC_INS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   XXXXXXX,
        KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   SYM_L,
        KC_NAGR,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_LBRC,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
        KC_CTPL,   KC_LGUI, KC_INS,  KC_LALT,   KC_LCTL, KC_DEL,
                                    KC_BSPC, KC_6,
                                    KC_PGUP, KC_PGDN,
                                                        // right hand
                                                              XXXXXXX, KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_EQL,
                                                                SYM_L, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_NAMI,
                                                              KC_RBRC, KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                                                                       KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,

                                                                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SPC, KC_RALT,
                                                                     // XXXXXXX,  KC_RALT,   KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,
                                                     XXXXXXX, KC_ENT,
                                                     KC_HOME, KC_END
    ),


    [_SYMB] = LAYOUT_5x7(
        _______, KC_F1,   KC_F2 , KC_F3 , KC_F4 , KC_F5 ,_______,                        _______, KC_F6,   KC_F7, KC_F8, KC_F9,  KC_F10,  XXXXXXX,
        _______, KC_TILD, KC_EXLM, KC_AT ,KC_HASH,KC_DLR,KC_PERC,                        _______, KC_PSLS, KC_P7, KC_P8, KC_P9,  KC_PMNS, XXXXXXX,
        _______, _______,_______,_______,_______,_______,KC_LBRC,                        _______, KC_PAST, KC_P4, KC_P5, KC_P6,  KC_PPLS, XXXXXXX,
        _______, _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,                                         XXXXXXX, KC_P1, KC_P2, KC_P3,  XXXXXXX, XXXXXXX,
        _______, _______,_______,_______,_______,_______,                                         XXXXXXX, KC_P2, KC_P3, KC_EQL, KC_UNDS, XXXXXXX,
                                 _______,KC_PSCR,                                                          KC_P0, KC_P0,
                                                _______,_______,                         _______,_______
    ),

    [_NAV] = LAYOUT_5x7(
        KC_NUM, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , XXXXXXX,                        XXXXXXX, KC_F6, KC_F7 , KC_F8 , KC_F9 , KC_F10 , XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_LBRC,                        KC_F11, KC_F12, KC_NUM ,KC_INS ,KC_SCRL,KC_MUTE, XXXXXXX,
        XXXXXXX,XXXXXXX,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,KC_VOLU, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLD, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,
                                XXXXXXX,XXXXXXX,                                                        KC_EQL ,XXXXXXX,
                                                XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX
    ),

    [_ADJUST] = LAYOUT_5x7(
        XXXXXXX, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,XXXXXXX,                        XXXXXXX, KC_F6, KC_F7 , KC_F8 , KC_F9 , KC_F10 , XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_LBRC,                        KC_RBRC,XXXXXXX,KC_NUM ,KC_INS ,KC_SCRL,KC_MUTE, XXXXXXX,
        XXXXXXX,XXXXXXX,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,KC_VOLU, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLD, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,
                                XXXXXXX,XXXXXXX,                                                        KC_EQL ,XXXXXXX,
                                                XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX
    )
};


