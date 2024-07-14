#include QMK_KEYBOARD_H
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
#define _QWERT 7

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

bool ukraineLanguge = false;

const uint16_t PROGMEM other_combo[]      = {LT(_RAISE, QK_LEAD), TT(_PROG), COMBO_END};
const uint16_t PROGMEM tab_combo[]        = {LT(_PROG, KC_S), LT(_DIGITS, KC_T), COMBO_END};
const uint16_t PROGMEM prog_layer_combo[] = {LT(_PROG, KC_S), LT(_DIGITS, KC_T), KC_R, COMBO_END};

const uint16_t PROGMEM enter_combo[]        = {LT(_PROG, KC_E), LT(_DIGITS, KC_N), COMBO_END};
const uint16_t PROGMEM digits_layer_combo[] = {LT(_PROG, KC_E), LT(_DIGITS, KC_N), KC_I, COMBO_END};

const uint16_t PROGMEM semicolon_combo[] = {MT(MOD_LCTL | MOD_LALT, KC_H), KC_COMM, COMBO_END};
const uint16_t PROGMEM slash_combo[]     = {MT(MOD_LCTL | MOD_LALT, KC_H), KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM k_combo[]         = {KC_J, KC_V, COMBO_END};

const uint16_t PROGMEM qwerty_tab_combo[]     = {LT(_PROG, KC_D), LT(_DIGITS, KC_F), COMBO_END};
const uint16_t PROGMEM qwerty_enter_combo[]   = {LT(_PROG, KC_J), LT(_DIGITS, KC_K), KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [OTHER_COMBO] = COMBO(other_combo, KC_DIGITS),
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [ENTER_COMBO] = COMBO(enter_combo, QK_LEAD),
    [DIGITS_LAYER_COMBO] = COMBO(digits_layer_combo, KC_ENT),
    [PROG_LAYER_COMBO] = COMBO(prog_layer_combo, TG(_PROG)),
    [SEMICOLON_COMBO] = COMBO(semicolon_combo, KC_COLN),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLSH),
    [K_COMBO] = COMBO(k_combo, KC_K),
    [QWRT_TAB_COMBO] = COMBO(qwerty_tab_combo, KC_TAB),
    [QWRT_ENTER_COMBO] = COMBO(qwerty_enter_combo, KC_ENT),
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
    TD_KC_PAREN
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
    [TD_KC_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR)
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
    KC_C,   KC_R,    LT(_PROG, KC_S),    LT(_DIGITS, KC_T),    KC_G,               KC_M,   LT(_DIGITS,KC_N), LT(_PROG, KC_E),    KC_I,    KC_A,
    KC_Q,   KC_J,    KC_V,    KC_D,    KC_K,                                       KC_X,   MT(MOD_LCTL | MOD_LALT, KC_H),    KC_COMM, KC_DOT,  TD(TD_KC_QUOT_KC_DQUO),
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
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, DIGITS,
                 KC_F11,  KC_F12,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,
                                                     _______,_______, _______,  _______),

/* _PROG
 * ,----------------------------------,                             ,----------------------------------,
 * |      |   r  |      |      |      |                             |      |      |      |      |      |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  [   |  {   |  =   |  (   |  *   |                             |   -  |  )   |  _   |  }   |  ]   |
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

[_PROG] = LAYOUT(
    _______,  KC_GRV, _______, _______, _______,                        _______, _______, _______, _______, _______,
    TD(TD_KC_BRACKET), TD(TD_KC_PAREN), TD(TD_KC_CBR), KC_LPRN, KC_ASTR,                          KC_MINS, KC_RPRN, KC_UNDS, KC_RCBR, KC_RBRC,
    KC_INSERT,  KC_SCLN,KC_COLN, KC_PLUS, TD(TD_KC_LEFT_BRACKET_KC_LEFT_PAREN),                           KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,  PROG,
              _______, _______,                                                   _______, _______,
              CTL_BSPC, SFT_ESC, KC_TAB, KC_LGUI, KC_GRV,           _______, _______,   _______, _______,_______),

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
    KC_C,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,     MT(MOD_LCTL | MOD_LALT, KC_E),    KC_I,    KC_A,
    KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,                                        KC_X,    KC_H,    KC_COMM, KC_DOT,  TD(TD_KC_QUOT_KC_DQUO),
            TD(TD_KC_EQUAL_KC_PLUS), TD(TD_KC_MINUS_KC_UNDERSCORE),                          TD(TD_KC_RIGHT_BRACKET_KC_UNDERSCORE), TD(TD_KC_LEFT_BRACKET_KC_LEFT_PAREN),
            CTL_BSPC, SFT_ESC, KC_TAB, KC_LGUI, KC_GRV,                                      ALT_SPC, TT(_PROG), RAISE, SFT_ENT, SFT_ENT
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
                          KC_TAB, KC_SPACE, KC_ESC, KC_LGUI, KC_RALT,                                      ALT_SPC, TT(_PROG), LT(_RAISE, QK_LEAD), SFT_ENT, SFT_ENT)

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
        KC_A,    KC_S,    LT(_PROG, KC_D), LT(_DIGITS, KC_F),   KC_G,                     KC_H,   LT(_PROG, KC_J), LT(_DIGITS, KC_K)    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
          TD(TD_KC_EQUAL_KC_PLUS), TD(TD_KC_MINUS_KC_UNDERSCORE),                          TD(TD_KC_RIGHT_BRACKET_KC_UNDERSCORE), TD(TD_KC_LEFT_BRACKET_KC_LEFT_PAREN),
            CTL_BSPC, SFT_ESC, KC_TAB, KC_LGUI, KC_GRV,                                      ALT_SPC, TT(_PROG), LT(_RAISE, QK_LEAD), SFT_ENT, SFT_ENT)
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

void leader_start_user(void) {}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_E)) {
        SEND_STRING("zilainfo\"gmail.com");
    } else if (leader_sequence_one_key(KC_B)) {
        layer_on(_BASE_CUSTOM);
    } else if (leader_sequence_one_key(QK_LEAD)) {
        layer_on(_PROG);
    } else {
        layer_on(_DIGITS);
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
  return true;
}

#define NUM_LAYER_TIMEOUT 500 //configure your timeout in milliseconds

void matrix_scan_user(void) {
  if (get_highest_layer(layer_state) == _DIGITS) {
    if (last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
      layer_off(_DIGITS);
    }
  }else if(get_highest_layer(layer_state) == _PROG) {
    if (last_input_activity_elapsed() > NUM_LAYER_TIMEOUT) {
      layer_off(_PROG);
    }
  }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {    
        case QWRT_TAB_COMBO:
            if (pressed) {
                if (IS_LAYER_ON(_QWERTY)) {
                    // Do something different if on LAYER1
                    tap_code(KC_TAB);
             }
            }
            break;
        case QWRT_ENTER_COMBO:
            if (pressed) {
                if (IS_LAYER_ON(_QWERTY)) {
                    // Do something different if on LAYER1
                    tap_code(KC_ENT);
                }
            }
            break;
        default:
            break;
    }
}