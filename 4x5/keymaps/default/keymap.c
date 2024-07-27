#include QMK_KEYBOARD_H
#include <stdbool.h>

#define RETRO_TAPPING_PER_KEY
#define DEBOUNCE 2
#define TAPPING_TERM_PER_KEY
#define LEADER_TIMEOUT 300

#define _BASE 0
#define _RAISE 1
#define _DIGITS 2
#define _PROG 3
#define _OTHER 4
#define _IDEA 5
#define _BASE_CUSTOM 6
#define _QWERTY 7
#define _PROG_2 8
#define _DIGITS_LEFT 9
#define _PROG_3 10
#define _DIGITS_RIGHT 11
#define _PROG_INVERTED 12

#define SFT_ESC SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC ALT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define DIGITS MO(_DIGITS)
#define PROG MO(_PROG)
#define OTHER MO(_OTHER)
#define BASE_CUSTOM MO(_BASE_CUSTOM)

#define NUM_LAYER_TIMEOUT 500 //configure your timeout in milliseconds
  
bool ukraineLanguge = false;

const uint16_t PROGMEM other_combo[]      = {LT(_RAISE, QK_LEAD), TT(_PROG), COMBO_END};
const uint16_t PROGMEM tab_combo[]        = {LT(_DIGITS_RIGHT, KC_S), LT(_PROG_3, KC_T), COMBO_END};
const uint16_t PROGMEM prog_layer_combo[] = {LT(_DIGITS_RIGHT, KC_S), LT(_PROG_3, KC_T), KC_R, COMBO_END};

const uint16_t PROGMEM enter_combo[]        = {LT(_DIGITS_LEFT, KC_E), LT(_PROG, KC_N), COMBO_END};
const uint16_t PROGMEM digits_layer_combo[] = {LT(_DIGITS_LEFT, KC_E), LT(_PROG, KC_N), KC_I, COMBO_END};

const uint16_t PROGMEM semicolon_combo[] = {MT(MOD_LCTL | MOD_LALT, KC_H), KC_COMM, COMBO_END};
const uint16_t PROGMEM slash_combo[]     = {MT(MOD_LCTL | MOD_LALT, KC_H), KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM k_combo[]         = {KC_J, KC_V, COMBO_END};

const uint16_t PROGMEM qwerty_tab_combo[]     = {LT(_PROG, KC_D), LT(_DIGITS, KC_F), COMBO_END};
const uint16_t PROGMEM qwerty_lead_combo[]    = {LT(_PROG, KC_J), LT(_DIGITS, KC_K), COMBO_END};
const uint16_t PROGMEM qwerty_enter_combo[]   = {LT(_PROG, KC_J), LT(_DIGITS, KC_K), KC_L, COMBO_END};

enum combo_events{
    OTHER_COMBO,
    TAB_COMBO,
    ENTER_COMBO,
    DIGITS_LAYER_COMBO,
    PROG_LAYER_COMBO,
    SEMICOLON_COMBO,
    SLASH_COMBO,
    K_COMBO,
    QWRT_TAB_COMBO,
    QWRT_ENTER_COMBO,
    QWRT_LEAD_COMBO, // This keeps track of the number of combos
};

combo_t key_combos[] = {
    [OTHER_COMBO] = COMBO(other_combo, _DIGITS),
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [ENTER_COMBO] = COMBO(enter_combo, QK_LEAD),
    [DIGITS_LAYER_COMBO] = COMBO(digits_layer_combo, KC_ENT),
    [PROG_LAYER_COMBO] = COMBO(prog_layer_combo, TG(_PROG)),
    [SEMICOLON_COMBO] = COMBO(semicolon_combo, KC_COLN),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLSH),
    [K_COMBO] = COMBO(k_combo, KC_K),
    [QWRT_TAB_COMBO] = COMBO_ACTION(qwerty_tab_combo),
    [QWRT_ENTER_COMBO] = COMBO_ACTION(qwerty_enter_combo),
    [QWRT_LEAD_COMBO] = COMBO_ACTION(qwerty_lead_combo),
};

enum {
    TD_KC_SCLN_COLN,
    TD_KC_QUOT_KC_DQUO,
    TD_KC_EQUAL_KC_PLUS,
    TD_KC_MINUS_KC_UNDERSCORE,
    TD_KC_LEFT_BRACKET_KC_LEFT_PAREN,
    TD_KC_RIGHT_BRACKET_KC_UNDERSCORE,
    TD_KC_CBR,
    TD_KC_BRACKET,
    TD_KC_PAREN,
    TD_KC_PLUS_KC_MINUS,
    TD_KC_LT_KC_GT,
    TD_KC_EXLM_KC_QUES,
    TD_KC_HASH_KC_AT,
    TD_KC_DOLLAR_KC_PERCENT,
    TD_KC_PIPE_KC_AMPERSAND,
    TD_KC_ASTERISK_KC_CIRCUMFLEX,
    TD_KC_UNDERSCORE_KC_TILDE,
    TD_KC_SLSH_KC_BSLS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_KC_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
    [TD_KC_QUOT_KC_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_KC_EQUAL_KC_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
    [TD_KC_MINUS_KC_UNDERSCORE] = ACTION_TAP_DANCE_DOUBLE(KC_UNDERSCORE, KC_MINUS),
    [TD_KC_EQUAL_KC_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
    [TD_KC_LEFT_BRACKET_KC_LEFT_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_BRACKET, KC_LEFT_PAREN),
    [TD_KC_RIGHT_BRACKET_KC_UNDERSCORE] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_BRACKET, KC_RIGHT_PAREN),
    [TD_KC_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_BRACKET, KC_RIGHT_BRACKET),
    [TD_KC_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [TD_KC_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_KC_PLUS_KC_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_MINUS),
    [TD_KC_LT_KC_GT] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
    [TD_KC_EXLM_KC_QUES] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_QUES),
    [TD_KC_HASH_KC_AT] = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_AT),
    [TD_KC_DOLLAR_KC_PERCENT] = ACTION_TAP_DANCE_DOUBLE(KC_DOLLAR, KC_PERCENT),
    [TD_KC_PIPE_KC_AMPERSAND] = ACTION_TAP_DANCE_DOUBLE(KC_PIPE, KC_AMPR),
    [TD_KC_ASTERISK_KC_CIRCUMFLEX] = ACTION_TAP_DANCE_DOUBLE(KC_ASTR, KC_CIRC),
    [TD_KC_UNDERSCORE_KC_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
    [TD_KC_SLSH_KC_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,----------------------------------,                             ,----------------------------------,
 * |   w  |   l  |   y  |   p  |   b  |                             |   z  |   f  |   o  |   u  |  :;  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   c  |   r  |   s  |   t  |   g  |                             |   m  |   n  |   e  |   i  |   a  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   q  |   j  |   v  |   d  |   k  |                             |   x  |   h  |   ,  |   .  |  ' " |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  =+  |  _-  |                                                         |  [(  |  ])  |
 *        '------+------'------                                            ,------,------+------'
 *                      |  BS  |                                           | SPACE|
 *                      |   +  |                                           |  +   |
 *                      | CTRL |                                           | ALT  |
 *                      '------|                                           '------|
 *                             '-------+---------,  ,-----------+-----------------'
 *                             | TAB   |ESC+SHIFT|  |   DIGITS  |HOLD_RAISE + PROG|
 *                             '-------+---------'  '-----------+-----------------'
 *                             |WINDOWS|    `    |  |ENTER+SHIFT|
 *                             '-------+---------'  '-----------'
*/

[_BASE] = LAYOUT(
    KC_W,   KC_L,    KC_Y,               KC_P,                 KC_B,               KC_Z,   KC_F,    KC_O,    KC_U,    TD(TD_KC_SCLN_COLN),
    KC_C,   KC_R,    LT(_DIGITS_RIGHT, KC_S),    LT(_PROG_3, KC_T),    KC_G,               KC_M,   LT(_PROG,KC_N), LT(_DIGITS_LEFT, KC_E),    KC_I,    KC_A,
    LT(_DIGITS_RIGHT,KC_Q),   KC_J,    KC_V,    KC_D,    KC_K,                                       KC_X,   MT(MOD_LCTL | MOD_LALT, KC_H),    KC_COMM, LT(_PROG_INVERTED,KC_DOT),  LT(_PROG,KC_QUOT),
            TD(TD_KC_EQUAL_KC_PLUS), TD(TD_KC_MINUS_KC_UNDERSCORE),                          TD(TD_KC_RIGHT_BRACKET_KC_UNDERSCORE), TD(TD_KC_LEFT_BRACKET_KC_LEFT_PAREN),
            CTL_BSPC, SFT_ESC, KC_TAB, KC_LGUI, KC_GRV,                                      ALT_SPC, TT(_PROG), LT(_RAISE, QK_LEAD), SFT_ENT, SFT_ENT
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  mute| PROG| PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | click| mleft| mdown|mright|      |                             | PgDn | left |  up | down | right |
 * |------+------+------+------+------|                             |------|-----+------+------+-------|
 * |   `  |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                            '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
*/

[_RAISE] = LAYOUT(
    _______, _______, KC_MU,   _______, _______,                                     KC_VOLU, _______, KC_MUTE, PROG, KC_PGUP,
    KC_MB1, KC_ML,   KC_MD,   KC_MR,   _______,                                      KC_MB2,KC_LEFT, KC_UP, KC_DOWN, KC_RGHT,
    KC_GRV, KC_WH_D, KC_WH_U, _______, _______,                                      KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
              _______, _______,                                                                      _______,  _______,
                                _______, _______,
                                                  _______, _______,  _______, _______,
                                                  _______, _______,   _______, _______
),

/* DIGITS
* ,----------------------------------,                             ,----------------------------------,
* | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
* |------+------+------+------+------|                             |-------------+------+------+------|
* |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
* |------+------+------+------+------|                             |------|------+------+------+------|
* |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  ?   |DIGITS|
* |------+------+------+-------------,                             ,-------------+------+------+------,
*        | F11  | F12  |                                                         |  -   |  =   |
*        '------+------'-------------'                             '-------------'------+------'
*                      |      |      |                             |      |      |
*                      |      |      |                             |      |      |
*                      |      |      |                             |      |      |
*                      '------+------'                             '------+------'
*                                    '------+------' '------+----,--'
*                                    |      |      | |      |      |
*                                    '------+------' '------+------'
*                                    |      |      | |      |      |
*                                    '------+------' '------+------'
*/
    [_DIGITS] = LAYOUT(
        KC_GT,   KC_LT,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, DIGITS,
                 KC_F11,  KC_F12,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,
                                                     _______,_______, _______,  _______),
/* DIGITS
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             | F6   | F7   | F8   | F9   | F10  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  6   |  7   |  8   |  9   |  0   |                             |      |      |      |      |DIGITS|
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |      |      |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_DIGITS_LEFT] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         _______, _______, _______, _______, _______,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                         _______, _______, _______, _______, DIGITS,
             KC_F11,  KC_F12,                                                                           _______, _______,
                               _______, _______,                                      _______, _______,
                                                 _______, _______,  
                                                 _______, _______, _______, _______
),
   [_DIGITS_RIGHT] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
             KC_F11,  KC_F12,                                                                           _______, _______,
                               _______, _______,                                      _______, _______,
                                                 _______, _______,  
                                                 _______, _______, _______, _______
),
/* _PROG
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |      |      |      |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  (   |  {   |  [   |  :;  |  ' " |                             |   -  |  )   |  _   |  }   |  ]   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |INSERT|  ;   |  :   |   +  |   '  |                             |  ^   |  &   |  *   |  ?   ||PROG |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |      |      |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+----,--'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_PROG_INVERTED] = LAYOUT(
    TD(TD_KC_ASTERISK_KC_CIRCUMFLEX),  TD(TD_KC_SLSH_KC_BSLS), TD(TD_KC_UNDERSCORE_KC_TILDE), TD(TD_KC_PLUS_KC_MINUS), TD(TD_KC_LT_KC_GT),                        _______, _______, _______, _______, _______,
    TD(TD_KC_PAREN), TD(TD_KC_CBR), TD(TD_KC_BRACKET), TD(TD_KC_SCLN_COLN), TD(TD_KC_QUOT_KC_DQUO),                          KC_MINS, LT(_PROG_2, KC_RPRN), KC_UNDS, KC_RCBR, KC_RBRC,
    KC_INSERT,  TD(TD_KC_PIPE_KC_AMPERSAND),TD(TD_KC_DOLLAR_KC_PERCENT), TD(TD_KC_HASH_KC_AT), TD(TD_KC_EXLM_KC_QUES),                           KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,  PROG,
              _______, _______,                                                   _______, _______,
              _______, _______,   _______, _______,_______,           _______, _______,   _______, _______,_______),

[_PROG] = LAYOUT(
    TD(TD_KC_ASTERISK_KC_CIRCUMFLEX),  TD(TD_KC_SLSH_KC_BSLS), TD(TD_KC_UNDERSCORE_KC_TILDE), TD(TD_KC_PLUS_KC_MINUS), TD(TD_KC_LT_KC_GT),                        _______, _______, _______, _______, _______,
    TD(TD_KC_PAREN), TD(TD_KC_CBR), TD(TD_KC_BRACKET), TD(TD_KC_SCLN_COLN), TD(TD_KC_QUOT_KC_DQUO),                          KC_MINS, LT(_PROG_2, KC_RPRN), KC_UNDS, KC_RCBR, KC_RBRC,
    KC_INSERT,  TD(TD_KC_PIPE_KC_AMPERSAND),TD(TD_KC_DOLLAR_KC_PERCENT), TD(TD_KC_HASH_KC_AT), TD(TD_KC_EXLM_KC_QUES),                           KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,  PROG,
              _______, _______,                                                   _______, _______,
              _______, _______,   _______, _______,_______,           _______, _______,   _______, _______,_______),
[_PROG_2] = LAYOUT(
    KC_CIRCUMFLEX,  KC_BSLS, KC_TILDE, KC_MINUS, KC_GT,                        _______, _______, _______, _______, _______,
    KC_RIGHT_PAREN, KC_RCBR, KC_RIGHT_BRACKET, KC_SCLN, KC_DQUO,                          KC_MINS, KC_RPRN, KC_UNDS, KC_RCBR, KC_RBRC,
    KC_INSERT,  KC_AMPERSAND,KC_PERCENT, KC_AT, KC_QUES,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,  PROG,
              _______, _______,                                                   _______, _______,
              _______, _______,   _______, _______,_______,           _______, _______,   _______, _______,_______),


[_PROG_3] = LAYOUT(
    KC_CIRCUMFLEX,  KC_BSLS, KC_TILDE, KC_MINUS, KC_GT,                        TD(TD_KC_LT_KC_GT), TD(TD_KC_PLUS_KC_MINUS), TD(TD_KC_UNDERSCORE_KC_TILDE), TD(TD_KC_SLSH_KC_BSLS), TD(TD_KC_ASTERISK_KC_CIRCUMFLEX),
    KC_RIGHT_PAREN, KC_RCBR, KC_RIGHT_BRACKET, KC_SCLN, KC_DQUO,                          TD(TD_KC_QUOT_KC_DQUO),  TD(TD_KC_SCLN_COLN), TD(TD_KC_BRACKET), TD(TD_KC_CBR), TD(TD_KC_PAREN),
    KC_INSERT,  KC_AMPERSAND,KC_PERCENT, KC_AT, KC_QUES,                           TD(TD_KC_EXLM_KC_QUES), TD(TD_KC_HASH_KC_AT), TD(TD_KC_DOLLAR_KC_PERCENT), TD(TD_KC_PIPE_KC_AMPERSAND),   TD(TD_KC_LT_KC_GT),
              _______, _______,                                                   _______, _______,
              _______, _______,   _______, _______,_______,           _______, _______,   _______, _______,_______),


[_OTHER] = LAYOUT(
    _______,  _______, _______, _______, _______,                        _______, _______, _______, _______, _______,
    KC_COPY, KC_PASTE, KC_UNDO, KC_AGAIN, KC_ASTR,                          DT_PRNT, DT_UP, DT_DOWN, KC_LEFT_GUI, KC_RIGHT_GUI,
    _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______,
              _______, _______,                                                   _______, _______,
              _______, _______, _______, _______, _______,           _______, _______,  _______, _______,_______),
              
/* Base
 * ,----------------------------------,                             ,----------------------------------,
 * |   w  |   l  |   y  |   p  |   b  |                             |   z  |   f  |   o  |   u  |  :;  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   c  |   r  |   s  |   t  |   g  |                             |   m  |   n  |   e  |   i  |   a  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   q  |   j  |   v  |   d  |   k  |                             |   x  |   h  |   ,  |   .  |  ' " |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  =+  |  _-  |                                                         |  [(  |  ])  |
 *        '------+------'------                                            ,------,------+------'
 *                      |  BS  |                                           | SPACE|
 *                      |   +  |                                           |  +   |
 *                      | CTRL |                                           | ALT  |
 *                      '------|                                           '------|
 *                             '-------+---------,  ,-----------+-----------------'
 *                             | TAB   |ESC+SHIFT|  |   DIGITS  |HOLD_RAISE + PROG|
 *                             '-------+---------'  '-----------+-----------------'
 *                             |WINDOWS|    `    |  |ENTER+SHIFT|
 *                             '-------+---------'  '-----------'
*/
[_IDEA] = LAYOUT(
    KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                                        KC_Z,    KC_F,    KC_O,    KC_U,    TD(TD_KC_SCLN_COLN),
    KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                                       KC_M,    KC_N,     MT(MOD_LCTL | MOD_LALT, KC_E),    KC_I,    KC_A,
    KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,                                       KC_X,    KC_H,    KC_COMM, KC_DOT,  TD(TD_KC_QUOT_KC_DQUO),
            TD(TD_KC_EQUAL_KC_PLUS), TD(TD_KC_MINUS_KC_UNDERSCORE),                          TD(TD_KC_RIGHT_BRACKET_KC_UNDERSCORE), TD(TD_KC_LEFT_BRACKET_KC_LEFT_PAREN),
            CTL_BSPC, SFT_ESC, KC_TAB, KC_LGUI, KC_GRV,                                      ALT_SPC, TT(_PROG), LT(_RAISE, QK_LEAD), SFT_ENT, SFT_ENT
),

    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |  BS  |                             | SPACE|ENTER |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | TAB  | HOME | | END  | DEL  |
     *                                    '------+------' '------+------'
     *                                    | Raise|  ~   | | GUI  | Lower|
     *                                    '------+------' '------+------'
     */
    [_BASE_CUSTOM] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                      KC_LBRC, KC_QUES,                                                        KC_MINS, BASE_CUSTOM,
                          KC_TAB, KC_SPACE, KC_ESC, KC_LGUI, KC_RALT,                                      ALT_SPC, TT(_PROG), LT(_RAISE, QK_LEAD), SFT_ENT, SFT_ENT),

    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |  BS  |                             | SPACE|ENTER |
     *                      |  +   |   +  |                             |  +   |  +   |
     *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | TAB  | HOME | | END  | DEL  |
     *                                    '------+------' '------+------'
     *                                    | Raise|  ~   | | GUI  | Lower|
     *                                    '------+------' '------+------'
     */
    [_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    LT(_PROG, KC_D), LT(_DIGITS, KC_F),   KC_G,                     KC_H,   LT(_PROG, KC_J), LT(_DIGITS, KC_K),    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
            TD(TD_KC_EQUAL_KC_PLUS), TD(TD_KC_MINUS_KC_UNDERSCORE),                          TD(TD_KC_RIGHT_BRACKET_KC_UNDERSCORE), TD(TD_KC_LEFT_BRACKET_KC_LEFT_PAREN),
            CTL_BSPC, SFT_ESC, KC_TAB, KC_LGUI, KC_GRV,                                       ALT_SPC, TT(_PROG), TT(_RAISE), SFT_ENT, SFT_ENT),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t * record) {
  switch (keycode) {
  case MT(MOD_LCTL | MOD_LALT, KC_E):
    return true;
  default:
    return false;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t * record) {
  switch (keycode) {
    case ALT_SPC:
        return 499;
    case CTL_BSPC:
        return 499;
    default:
        return TAPPING_TERM;
  }
}

void press_ctrl_shift(void) {
    // Press both CTRL (Left Control) and SHIFT (Left Shift) together
    register_code(KC_LCTL);  // Press CTRL key
    register_code(KC_LSFT);  // Press SHIFT key
    // Optionally, you can add a delay if needed
    wait_ms(100); // Wait for 100 milliseconds
    // Release both keys
    unregister_code(KC_LSFT); // Release SHIFT key
    unregister_code(KC_LCTL); // Release CTRL key
}

void leader_start_user(void) {
}

void leader_end_user(void) {

    if (leader_sequence_one_key(KC_E)) {
        SEND_STRING("zilainfo@gmail.com");
    } else if (leader_sequence_one_key(KC_B)) {
        layer_on(_BASE_CUSTOM);  
    } else if (leader_sequence_one_key(QK_LEAD)) {
        layer_on(_DIGITS);
    } else if (leader_sequence_one_key(KC_A)) {            
        press_ctrl_shift();
        layer_invert(_QWERTY);   
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        case LT(_RAISE, QK_LEAD):
            if (record -> tap.count && record -> event.pressed) {
                leader_start();
                return false; // Return false to ignore further processing of key
            }
        break;
    }

    return true;  // Process all other keycodes normally
}

// void matrix_scan_user(void) {
//   if (get_highest_layer(layer_state) == _DIGITS) {
//     if (last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
//       layer_off(_DIGITS);
//     }
//   }
// }

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case QWRT_TAB_COMBO:
            if (pressed) {
                if (IS_LAYER_ON(_QWERTY)) {
                    // If on QWERTY layer, tap the TAB key
                    tap_code(KC_TAB);
                }
            }
            break;

        case QWRT_ENTER_COMBO:
            if (pressed) {
                if (IS_LAYER_ON(_QWERTY)) {
                    // If on QWERTY layer, tap the ENTER key
                    tap_code(KC_ENT);
                }
            }
            break;

        case QWRT_LEAD_COMBO:
            if (pressed) {         
             press_ctrl_shift();
             layer_invert(_QWERTY);   
            }
            break;

        default:
            // Handle other combos if necessary
            break;
    }
}

void dance_q_finished(tap_dance_state_t *state, void *user_data) {
    if (layer_state_is(_PROG_INVERTED)) {
    uint16_t *keycodes = (uint16_t *)user_data;
            if (state->count == 1) {
            tap_code(keycodes[1]);
        } else if (state->count == 2) {
            // Do something on double tap, e.g., send a different key or command
        }
    }
}

// void dance_q_reset(tap_dance_state_t *state, void *user_data) {
//     if (layer_state_is(_PROG_INVERTED) && state->count == 1) {
//         uint16_t *keycodes = (uint16_t *)user_data;
//         unregister_code(keycodes[1]);
//     }
// }