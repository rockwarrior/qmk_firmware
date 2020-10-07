#include QMK_KEYBOARD_H

// mod tap functions
#define ESC_FN1     LT(1, KC_ESC)
#define ENT_CMD     MT(MOD_LGUI, KC_ENT)

// vim navigation
#define cD          LCTL(KC_D)
#define cE          LCTL(KC_E)
#define cU          LCTL(KC_U)
#define cY          LCTL(KC_Y)

// clion commands
#define BUILD       LCMD(KC_F9)
#define BACK        LCMD(LALT(KC_LEFT))
#define FWD         LCMD(LALT(KC_RIGHT))
#define MVUP        LCMD(LSFT(KC_UP))
#define MVDOWN      LCMD(LSFT(KC_DOWN))
#define REFACTOR    LSFT(KC_F6)
#define HDRSRC      LCMD(LCTL(KC_UP))
#define LIST        LCMD(KC_F12)
#define WHERE       LCMD(LALT(KC_F7))
#define GOTO        LCMD(KC_B)
#define ESC         LSFT(KC_ESC)
#define OPEN        LCMD(KC_E)
#define TABL        LCMD(LSFT(KC_LBRC))
#define TABR        LCMD(LSFT(KC_RBRC))
#define BEAUTIFY    LCMD(LCTL(LALT(KC_B))) // custom command
#define FLASH       LCMD(LCTL(LALT(KC_F))) // custom command
#define STEPOVER    KC_F8
#define STEPIN      LSFT(KC_F7)

#define APP         LCMD(KC_TAB)

enum custom_keycodes {
    xNEXT = SAFE_RANGE,
    xPREV,
    xNEW,
    xKILL,
    xVERT,
    xHORZ,
    xNAME,
    xMOVL,
    xMOVR,
    xMOVU,
    xMOVD,
    xRSZL,
    xRSZR,
    xRSZU,
    xRSZD,
    xAPP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE layer: Default Layer
   * ,--------------------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |  | Grv |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |  | Del |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * | TabFn1  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   EnterCmd  |
   * |--------------------------------------------------------------------------------------------+
   * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift       | Up  |
   * +--------------------------------------------------------------------------------------------+-----+
   * | Ctrl  | Alt   | Cmd  |               Space                | Cmd  | Alt  | Fn   | Left| Down|Right|
   * `--------------------------------------------------------------------------------------------------´
   */
  [0] = LAYOUT(
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_GRV,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL,
        ESC_FN1,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     ENT_CMD,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,
        KC_LCTL,KC_LALT,KC_LGUI,          KC_SPC,                       KC_RCMD,KC_RALT,MO(4),       KC_LEFT,KC_DOWN,KC_RGHT
    ),
  /* Fn1 layer
   * ,--------------------------------------------------------------------------------------------------.
   * |    | !   | @   |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  _  |  +  |            |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |        |     |     |  cE  |     |     | cY | cU  |     |     |     |  {  |  }  |   |    |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |         |     |     | cD |  Fn2 |     | Left | Down | Up | Right | :  | "  |            |
   * |--------------------------------------------------------------------------------------------+
   * |            |     |     |     |     |     |     |     |  <  | >   |  ?  |             |     |
   * +--------------------------------------------------------------------------------------------+-----+
   * |       |       |      |                                    |      |      |      |     |     |     |
   * `--------------------------------------------------------------------------------------------------´
   */
  [1] = LAYOUT(
        _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,KC_PLUS,_______,     _______,
        _______,_______,_______,cE     ,_______,_______,cY     ,cU     ,_______,_______,_______,KC_LCBR,KC_RCBR,KC_PIPE,     _______,
        _______,MO(2)  ,_______,cD     ,MO(3)  ,xAPP   ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_COLN,KC_DQT ,    _______,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_LT  ,KC_GT  ,KC_QUES,_______,    _______,
        _______,_______,_______,                _______,              _______,_______,_______,      _______,_______,_______
    ),
  /* Fn2 layer
   * ,--------------------------------------------------------------------------------------------------.
   * |    |     |     |     |     |     |     |     |     |     |     |     |     |            |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |        |     |     |      |     |     |    |      |      |      |   |    |     |        |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |         |     | TMUXS |    |     |     | TMUXL | TMUXD | TMUXU | TMUXR |     |    |        |
   * |--------------------------------------------------------------------------------------------+
   * |          |     | TMUXX | TMUXC | TMUXV | TMUXP | TMUXN |    | TMUXT |     |     |          |     |
   * +--------------------------------------------------------------------------------------------+-----+
   * |       |       |      |                                    |      |      |      |     |     |     |
   * `--------------------------------------------------------------------------------------------------´
   */
  [2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,xHORZ  ,_______,_______,_______,xMOVL  ,xMOVD  ,xMOVU  ,xMOVR  ,_______,_______,    _______,
        _______,_______,xKILL  ,xNEW   ,xVERT  ,xPREV  ,xNEXT  ,_______,xNAME  ,_______,_______,_______,    xRSZU  ,
        _______,_______,_______,                _______,              _______,_______,_______,      xRSZL  ,xRSZD  ,xRSZR
    ),
/* Fn3 layer
   * ,--------------------------------------------------------------------------------------------------.
   * |    |     |     |     |     |     |     |     |     |     |     |     |     |    ESC     |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |        |     |     |      |     |     |    |WHERE |HDRSRC| LIST | P |    |     |  REF   |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |         |     |     |    |      |     |  BACK  | TABL | TABR | FWD | GOTO |    |  OPEN  |
   * |--------------------------------------------------------------------------------------------+
   * |            |     |     |     |     |     |     |     |     |     |     |             |     |
   * +--------------------------------------------------------------------------------------------+-----+
   * |       |       |      |                BUILD               |      |      |      |     |     |     |
   * `--------------------------------------------------------------------------------------------------´
   */
  [3] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,ESC     ,     _______,
        _______,_______,_______,_______,_______,_______,_______,WHERE  ,HDRSRC ,LIST   ,_______,_______,_______,REFACTOR,     _______,
        _______,_______,_______,_______,_______,_______,BACK   ,TABL   ,TABR   ,FWD    ,GOTO   ,_______,        OPEN    ,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,
        _______,_______,_______,                _______,                _______,_______,_______,    _______,_______,_______
    ),
/* Fn4 layer
   * ,--------------------------------------------------------------------------------------------------.
   * |    | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |            |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |        |     |     |      |     |     |    |     |     |       |    |    |     |        |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |         |     |     |    |      |     |       |       |      |      |      |      |     |
   * |--------------------------------------------------------------------------------------------+
   * |            |     |     |     |     |     |     |     |     |     |     |             |     |
   * +--------------------------------------------------------------------------------------------+-----+
   * |       |       |      |                                    |      |      |      |     |     |     |
   * `--------------------------------------------------------------------------------------------------´
   */
  [4] = LAYOUT(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,
        _______,_______,_______,                _______,                _______,_______,_______,    _______,_______,_______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case xAPP:
            // app switcher
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB));
            } else {
                SEND_STRING(SS_UP(X_LGUI));
            }
            break;
        case xPREV:
            // tmux: previous window
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"p");
            }
            break;
        case xNEXT:
            // tmux: next window
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"n");
            }
            break;
        case xNEW:
            // tmux: new window
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"c"SS_LCTRL("a")",");
            }
            break;
        case xKILL:
            // tmux: kill window
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"x");
            }
            break;
        case xVERT:
            // tmux: vertical split
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"%");
            }
            break;
        case xHORZ:
            // tmux: horizontal split
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"\"");
            }
            break;
        case xNAME:
            // tmux: rename window title
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")",");
            }
            break;
        case xRSZL:
            // tmux: resize pane left
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"H");
            }
            break;
        case xRSZR:
            // tmux: resize pane right
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"L");
            }
            break;
        case xRSZU:
            // tmux: resize pane up
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"K");
            }
            break;
        case xRSZD:
            // tmux: resize pane down
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")"J");
            }
            break;
        case xMOVL:
            // tmux: move pane focus left
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")SS_TAP(X_LEFT));
            }
            break;
        case xMOVR:
            // tmux: move pane focus right
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")SS_TAP(X_RGHT));
            }
            break;
        case xMOVU:
            // tmux: move pane focus up
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")SS_TAP(X_UP));
            }
            break;
        case xMOVD:
            // tmux: move pane focus down
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("a")SS_TAP(X_DOWN));
            }
            break;
    }
    return true;
}

