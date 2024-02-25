#include QMK_KEYBOARD_H

enum keymap_layer {
    KM_JP = 0,
    KM_FN1,
    KM_FN2,
    KM_TENKEY,
};

enum custom_keycodes {
    CK_BTUSB = USER00,
    CK_RESET = USER01,
    CK_BATLV = USER02,
    CK_LKMOD = USER03,
    CK_INUSB = USER04,
    CK_VIM_O = USER05,
    CK_VIM_D = USER06,
    CK_VIM_D0 = USER07,
    CK_VIM_DD = USER08,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KM_JP] = LAYOUT_yang_jp(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_INT3, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_INT1, KC_UP, KC_RSFT,
        MO(KM_FN1), LT(KM_TENKEY,KC_GRV), KC_LGUI, KC_LALT, KC_INT5, LT(KM_FN2,KC_SPC), KC_INT4, KC_RALT, KC_DEL, MO(KM_FN1), KC_LEFT, KC_DOWN, KC_RGHT),

    [KM_FN1] = LAYOUT_yang_jp(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, CK_BTUSB, _______,  CK_BATLV, _______, _______, _______, CK_INUSB, KC_PSCR, _______, _______, KC_UP, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, KC_ENT,
        _______, CK_LKMOD, _______, _______, _______, CK_RESET, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, _______, KC_RSFT, _______,
        _______, _______, _______, _______, _______, KC_SPC, _______, _______,  _______, _______, KC_DEL, KC_RGUI, KC_RCTL),

    [KM_FN2] = LAYOUT_yang_jp(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CK_VIM_D0, XXXXXXX, CK_VIM_O, KC_BSPC, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, CK_VIM_D, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT, XXXXXXX, XXXXXXX, KC_ENT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_DEL, XXXXXXX, KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),

    [KM_TENKEY ]= LAYOUT_yang_jp(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM_LOCK, KC_TAB, KC_KP_SLASH, KC_KP_ASTERISK, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_BSPC, XXXXXXX,
        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_ENTER, XXXXXXX, KC_KP_ENTER,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER, KC_KP_ENTER, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, KC_KP_0, KC_KP_0, KC_KP_DOT, KC_PENT, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CK_VIM_O:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_END));
        SEND_STRING (SS_TAP(X_ENTER));
      }
      return false;

    case CK_VIM_D:
      if (record->event.pressed) {
        SEND_STRING (SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT));
        SEND_STRING (SS_LCTL("x"));
      }
      return false;

    case CK_VIM_D0:
      if (record->event.pressed) {
        SEND_STRING (SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_UP(X_LSFT));
        SEND_STRING (SS_LCTL("x"));
      }
      return false;

    case CK_VIM_DD:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_HOME) SS_TAP(X_HOME));
        SEND_STRING (SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT));
        SEND_STRING (SS_LCTL("x"));
      }
      return false;

    default:
      return true; // Process all other keycodes normally
  }
}
