#include "dz60.h"
#include "layout_jp.h"

enum keyboard_layers {
	_WIN,
	_UNIX,
	_ORG,
	_EDWIN,
	_EDUNI,
	_MOUSE,
	_FN
};

#define KC_SSWIN LT(_EDWIN,KC_SPC)
#define KC_SSUNI LT(_EDUNI,KC_SPC)
#define KC_SHENK LT(_MOUSE,KC_HENK)
#define KC_SMHEN LT(_FN,KC_MHEN)
#define KC_BWORD LCTL(KC_LEFT)
#define KC_FWORD LCTL(KC_RGHT)
#define CTRL_A LCTL(KC_A)
#define CTRL_A_DEL LALT(LCTL(KC_DEL))

enum dz60_keycodes
{
    QWERTY = SAFE_RANGE,
    DYNKEY,
    DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"


enum user_macro {
  UM_CTRL,
  UM_H,
  UM_D,
  UM_A,
  UM_E,
  UM_LB,
  UM_F01,
  UM_F02,
  UM_F03,
  UM_F04,
  UM_F05,
  UM_F06,
  UM_F07,
  UM_F08,
  UM_F09,
  UM_F10,
  UM_F11,
  UM_F12,
  UM_K,
  UM_U,
  UM_SLEFT,
  UM_SRGHT,
  UM_SUP,
  UM_SDOWN,
  UM_ESCB,
  UM_ESCF,
};

//Tap Dance Declarations
enum {
  TD_LEFT,
  TD_RGHT,
  TD_UP,
  TD_DOWN,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LEFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME)
 ,[TD_RGHT]  = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END)
 ,[TD_UP]  = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP)
 ,[TD_DOWN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_JP(
        KC_ESC, M(UM_F01), M(UM_F02), M(UM_F03), M(UM_F04), M(UM_F05), M(UM_F06), M(UM_F07), M(UM_F08), M(UM_F09), M(UM_F10), M(UM_F11), M(UM_F12), KC_JYEN, KC_BSPC,
        KC_TAB, KC_Q, KC_W, M(UM_E), KC_R, KC_T, KC_Y, M(UM_U), KC_I, KC_O, KC_P, KC_LBRC, M(UM_LB),
        M(UM_CTRL), M(UM_A), KC_S, M(UM_D), KC_F, KC_G, M(UM_H), KC_J, M(UM_K), KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RO, KC_RSFT,
        MO(_FN), KC_LGUI, KC_LALT, KC_SMHEN, KC_SSWIN, KC_SHENK, KC_KANA, KC_RALT ,KC_APP, KC_RCTL),

    [_UNIX] = LAYOUT_JP(
        KC_ESC, M(UM_F01), M(UM_F02), M(UM_F03), M(UM_F04), M(UM_F05), M(UM_F06), M(UM_F07), M(UM_F08), M(UM_F09), M(UM_F10), M(UM_F11), M(UM_F12), KC_JYEN, KC_BSPC,
        MT(MOD_LCTL,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RO, KC_RSFT,
        MO(_FN), KC_LGUI, KC_LALT, KC_SMHEN, KC_SSUNI, KC_SHENK, KC_KANA, KC_RALT ,KC_APP, KC_RCTL),

    [_ORG] = LAYOUT_JP(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_JYEN, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RO, KC_RSFT,
        MO(_FN), KC_LGUI, KC_LALT, KC_SMHEN, KC_SPC, KC_SHENK, KC_KANA, KC_RALT ,KC_APP, KC_RCTL),

   [_EDWIN] = LAYOUT_JP(
        DYN_REC_STOP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        _______, _______, _______, DYN_REC_START2, DYN_REC_START1, _______, _______, KC_PGUP, KC_UP, KC_PGDN, _______, _______, _______,
        KC_LCTL, _______, _______, DYN_MACRO_PLAY2, DYN_MACRO_PLAY1, _______, KC_BWORD, KC_LEFT, KC_DOWN, KC_RGHT, KC_FWORD, _______, _______, _______,
        _______, _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, KC_HOME, M(UM_SLEFT), M(UM_SRGHT), KC_END, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_EDUNI] = LAYOUT_JP(
        DYN_REC_STOP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        _______, _______, _______, DYN_REC_START2, DYN_REC_START1, _______, _______, KC_PGUP, KC_UP, KC_PGDN, _______, _______, _______,
    	KC_LCTL, _______, _______, DYN_MACRO_PLAY2, DYN_MACRO_PLAY1, _______, M(UM_ESCB), KC_LEFT, KC_DOWN, KC_RGHT, M(UM_ESCF), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, M(UM_SLEFT), M(UM_SRGHT), KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_MOUSE] = LAYOUT_JP(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______, _______,
        _______, _______, KC_BTN3, KC_BTN2, KC_ACL1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_L, _______, KC_WH_R, _______, _______, _______,
        _______, _______, _______, _______, KC_BTN1, _______, _______, _______, _______, _______),


    [_FN] = LAYOUT_JP(
        RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_LCAP, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, _______,
        KC_LCTL, _______, DF(_ORG), DF(_UNIX), DF(_WIN), _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______, KC_PENT,
        _______, RGB_TOG, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

static bool ctrl_pressed;
//char befor_key, after_key;
uint16_t befor_key, after_key;
static bool trgt_pressed;

void ctrl_plus(keyrecord_t *record)
{
	if (record->event.pressed) {
		if (ctrl_pressed) {
 			trgt_pressed = true;
	unregister_code(KC_LCTL);
	register_code(after_key);
		} else {
 		trgt_pressed = false;
 		register_code(befor_key);
 		}
 	} else {
		if (trgt_pressed) {
	unregister_code(after_key);
		} else {
	unregister_code(befor_key);
		}
		if (ctrl_pressed) {
	register_code(KC_LCTL);
		}
	}
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
	    case UM_CTRL:
	        if (record->event.pressed) {
	            register_code(KC_LCTL);
	            ctrl_pressed = true;
	        } else {
	            unregister_code(KC_LCTL);
	            ctrl_pressed = false;
	               }
	        break;
	    case UM_H:
		befor_key = KC_H;
		after_key = KC_BSPC;
		ctrl_plus(record);
	        break;
	     case UM_D:
		befor_key = KC_D;
		after_key = KC_DEL;
		ctrl_plus(record);
	        break;
	     case UM_A:
		befor_key = KC_A;
		after_key = KC_HOME;
		ctrl_plus(record);
	        break;
	     case UM_E:
		befor_key = KC_E;
		after_key = KC_END;
		ctrl_plus(record);
	        break;
	     case UM_LB:
		befor_key = KC_RBRC;
		after_key = KC_ESC;
		ctrl_plus(record);
	        break;
	     case UM_F01:
		befor_key = KC_1;
		after_key = KC_F1;
		ctrl_plus(record);
	        break;
	     case UM_F02:
		befor_key = KC_2;
		after_key = KC_F2;
		ctrl_plus(record);
	        break;
	     case UM_F03:
		befor_key = KC_3;
		after_key = KC_F3;
		ctrl_plus(record);
	        break;
	     case UM_F04:
		befor_key = KC_4;
		after_key = KC_F4;
		ctrl_plus(record);
	        break;
	     case UM_F05:
		befor_key = KC_5;
		after_key = KC_F5;
		ctrl_plus(record);
	        break;
	     case UM_F06:
		befor_key = KC_6;
		after_key = KC_F6;
		ctrl_plus(record);
	        break;
	     case UM_F07:
		befor_key = KC_7;
		after_key = KC_F7;
		ctrl_plus(record);
	        break;
	     case UM_F08:
		befor_key = KC_8;
		after_key = KC_F8;
		ctrl_plus(record);
	        break;
	     case UM_F09:
		befor_key = KC_9;
		after_key = KC_F9;
		ctrl_plus(record);
	        break;
	     case UM_F10:
		befor_key = KC_0;
		after_key = KC_F10;
		ctrl_plus(record);
	        break;
	     case UM_F11:
		befor_key = KC_MINS;
		after_key = KC_F11;
		ctrl_plus(record);
	        break;
	     case UM_F12:
		befor_key = KC_EQL;
		after_key = KC_F12;
		ctrl_plus(record);
	        break;
	     case UM_K:
	        if (record->event.pressed) {
	            if (ctrl_pressed) {
	                trgt_pressed = true;
	                unregister_code(KC_LCTL);
	                register_code(KC_LSFT);
	                register_code(KC_END);
	                unregister_code(KC_END);
	                unregister_code(KC_LSFT);
	                register_code(KC_DEL);
	                unregister_code(KC_DEL);
	            } else {
	                trgt_pressed = false;
	                register_code(KC_K);
	            }
	        } else {
	            if (trgt_pressed) {
	                unregister_code(KC_DEL);
	            } else {
	                unregister_code(KC_K);
	            }
	            if (ctrl_pressed) {
	                register_code(KC_LCTL);
	            }
	        }
	        break;
	     case UM_U:
	        if (record->event.pressed) {
	            if (ctrl_pressed) {
	                trgt_pressed = true;
	                unregister_code(KC_LCTL);
	                register_code(KC_LSFT);
	                register_code(KC_HOME);
	                unregister_code(KC_HOME);
	                unregister_code(KC_LSFT);
	                register_code(KC_DEL);
	                unregister_code(KC_DEL);
	            } else {
	                trgt_pressed = false;
	                register_code(KC_U);
	            }
	        } else {
	            if (trgt_pressed) {
	                unregister_code(KC_DEL);
	            } else {
	                unregister_code(KC_U);
	            }
	            if (ctrl_pressed) {
	                register_code(KC_LCTL);
	            }
	        }
	        break;
        case UM_SLEFT:
            return MACRODOWN(T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), END);
        case UM_SRGHT:
            return MACRODOWN(T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), T(RGHT), END); 
        case UM_SUP:
            return MACRODOWN(T(UP),  T(UP), T(UP), T(UP), T(UP), T(UP), T(UP), END); 
        case UM_SDOWN:
            return MACRODOWN(T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), T(DOWN), END);
        case UM_ESCB:
            return MACRODOWN(T(ESC), T(B), END);
        case UM_ESCF:
            return MACRODOWN(T(ESC), T(F), END);
        }
        return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    uint16_t macro_kc = (keycode == MO(_EDWIN) && (keycode == MO(_EDUNI)) ? DYN_REC_STOP : keycode);
    if (!process_record_dynamic_macro(macro_kc, record))
    {
        return false;
    }

    return true;
};

