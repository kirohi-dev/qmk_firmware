#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

// this keymap is convert from ergodash_mini_layout_mine.json

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MINS, KC_EQL, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LANG2, KC_LANG1, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EXLM, KC_LCTL, KC_LGUI, KC_LALT, KC_GRV, MO(2), KC_SPC, KC_DEL, KC_BSPC, KC_ENT, MO(1), KC_LPRN, KC_RPRN, KC_PGUP, KC_PGDN),
        [1] = LAYOUT(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_UNDS, KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, KC_DQUO, KC_LSFT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPC, KC_ENT, KC_N, KC_M, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), MO(3), KC_SPC, KC_DEL, KC_BSPC, KC_ENT, MO(1), KC_HOME, KC_PGDN, KC_PGUP, KC_END),
        [2] = LAYOUT(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_UNDS, KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, KC_DQUO, KC_LSFT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_SPC, KC_ENT, KC_N, KC_M, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_F11, KC_F12, LALT(KC_GRV), MO(2), KC_SPC, KC_DEL, KC_BSPC, KC_ENT, MO(3), KC_HOME, KC_PGDN, KC_PGUP, KC_END),
        [3] = LAYOUT(KC_TRNS, RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_BRTG, BL_INC, BL_DEC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
