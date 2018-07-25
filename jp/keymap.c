#include "dz60.h"
#include "layout_jp.h"

//Space and Shift設定。Space + IJKLでカーソル移動など
#define KC_SANS LT(_FN,KC_SPC)
//カーソルのワード単位での移動。Ctrl + 左やCtrl + 右と同じ
#define KC_LWORD LCTL(KC_LEFT)
#define KC_RWORD LCTL(KC_RGHT)

enum keyboard_layers {
	_DEF,
	_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEF] = LAYOUT_JP(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_JYEN, KC_BSPC,
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
	KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RO, KC_RSFT,
	MO(_FN), KC_LGUI, KC_LALT, KC_MHEN, KC_SANS, KC_HENK, KC_KANA, KC_RALT, KC_APP, KC_RCTL),

[_FN] = LAYOUT_JP(
	RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
	KC_LCAP, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_PGUP, KC_UP, KC_PGDN, _______, _______, KC_SLCK,
	KC_LCTL, _______, _______, _______, _______, _______, KC_LWORD, KC_LEFT, KC_DOWN, KC_RGHT, KC_RWORD, _______, KC_PAUS, KC_PENT,
	_______, RGB_TOG, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END, _______, _______, KC_PSCR,
	_______, _______, _______, _______, KC_SPC, _______, _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
			return true;
}

const uint16_t PROGMEM fn_actions[] = {
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
};

