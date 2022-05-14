#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "config.h"

/*
 *  ____
 * / ___|  ___  ___ _ __ ___   __ _ _ __  _ __
 * \___ \ / _ \/ _ \ '_ ` _ \ / _` | '_ \| '_ \
 *  ___) |  __/  __/ | | | | | (_| | | | | | | |
 * |____/ \___|\___|_| |_| |_|\__,_|_| |_|_| |_|
 *
 */

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_7,
  DANCE_8,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
			KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,       KC_J,       KC_L,         KC_U,         DE_Y,         KC_BSPC, 
			LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), LT(4,KC_G), LT(4,KC_M), LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), 
			DE_Z,         KC_X,         KC_C,         KC_D,         KC_V,       KC_K,       KC_H,         KC_COMM,      KC_DOT,       DE_SLSH, 
			LT(1,KC_SPC), LSFT_T(KC_SPC),                                       LSFT_T(KC_SPC), LT(2,KC_SPC)),
	[1] = LAYOUT_split_3x5_2(
      DE_EXLM,         DE_AT,          DE_HASH,         DE_DLR,          DE_PERC,    DE_CIRC,    DE_AMPR,      DE_ASTR,      DE_SCLN,      DE_COLN,
      LSFT_T(DE_ADIA), LCTL_T(DE_SS),  LALT_T(DE_ODIA), LGUI_T(DE_UDIA), DE_EQL,     DE_PLUS,    TD(DANCE_0),  TD(DANCE_1),  TD(DANCE_2),  LSFT_T(KC_ENT),
      DE_EURO,         KC_NO,          KC_NO,           KC_NO,           KC_NO,      DE_MINS,    KC_NO,        DE_LABK,      DE_RABK,      DE_QUES,
      KC_NO,           KC_NO,                                                        KC_NO,      MO(3)),      
	[2] = LAYOUT_split_3x5_2(
      TD(DANCE_3),     DE_ACUT,        DE_LCBR,         DE_RCBR,         DE_UNDS,    TD(DANCE_7),    KC_7,        KC_8,        KC_9,        TD(DANCE_8), 
      LSFT_T(KC_ESC),  DE_PIPE,        DE_LPRN,         DE_RPRN,         DE_EQL,     DE_PLUS,    LGUI_T(KC_4),  LALT_T(KC_5),  LCTL_T(KC_6),  LSFT_T(KC_ENT), 
      KC_NO,           DE_TILD,        DE_LBRC,         DE_RBRC,         DE_BSLS,    KC_0,      KC_1,        KC_2,        KC_3,        DE_ASTR, 
      MO(3),           KC_NO,                                            KC_NO,      KC_NO),
	[3] = LAYOUT_split_3x5_2(
      KC_MUTE,         KC_WH_L,        KC_MS_U,         KC_WH_R,         KC_WH_U,    KC_NO,      KC_MRWD,      KC_MPLY,     KC_MFFD,     KC_NO, 
      KC_VOLU,         KC_MS_L,        KC_MS_D,         KC_MS_R,         KC_WH_D,    KC_NO,      KC_BTN1,      KC_BTN3,     KC_BTN2,     KC_NO, 
      KC_VOLD,         KC_NO,          KC_NO,           KC_NO,           KC_NO,      KC_NO,      KC_ACL0,      KC_ACL1,     KC_ACL2,     RESET, 
      KC_NO,           KC_TRNS,                                                      KC_TRNS,    KC_NO),
	[4] = LAYOUT_split_3x5_2(
      KC_F1,           KC_F2,          KC_F3,           KC_F4,           KC_F5,      KC_F6,      KC_F7,        KC_F8,       KC_F9,       KC_F10, 
      LSFT_T(KC_HOME), LCTL_T(KC_INS), LALT_T(KC_PGUP), LGUI_T(KC_PGDN), KC_DEL, KC_LEFT, LGUI_T(KC_DOWN), LALT_T(KC_UP), LCTL_T(KC_RGHT), LSFT_T(KC_END), 
      KC_NO,           KC_NO,          KC_NO,           KC_NO,           KC_NO,      KC_NO,      KC_NO,        KC_NO,       KC_F11,      KC_F12, 
      KC_NO,           KC_NO,                                            KC_NO,      KC_NO)
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[9];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_ACUT);
        tap_code16(DE_ACUT);
        tap_code16(DE_ACUT);
    }
    if(state->count > 3) {
        tap_code16(DE_ACUT);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(DE_ACUT); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(DE_ACUT); register_code16(DE_ACUT); break;
        case DOUBLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_ACUT); register_code16(DE_ACUT);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(DE_ACUT); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(DE_ACUT); break;
        case DOUBLE_HOLD: unregister_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_ACUT); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_QUOT);
        tap_code16(DE_QUOT);
        tap_code16(DE_QUOT);
    }
    if(state->count > 3) {
        tap_code16(DE_QUOT);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(DE_QUOT); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(DE_QUOT); register_code16(DE_QUOT); break;
        case DOUBLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_QUOT); register_code16(DE_QUOT);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(DE_QUOT); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(DE_QUOT); break;
        case DOUBLE_HOLD: unregister_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_QUOT); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_DQUO);
        tap_code16(DE_DQUO);
        tap_code16(DE_DQUO);
    }
    if(state->count > 3) {
        tap_code16(DE_DQUO);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(DE_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(DE_DQUO); register_code16(DE_DQUO); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_DQUO); register_code16(DE_DQUO);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(DE_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(DE_DQUO); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_DQUO); break;
    }
    dance_state[2].step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[3].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_MINUS);
        tap_code16(KC_KP_MINUS);
        tap_code16(KC_KP_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_MINUS);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_KP_MINUS); break;
        case SINGLE_HOLD: register_code16(DE_COLN); break;
        case DOUBLE_TAP: register_code16(KC_KP_MINUS); register_code16(KC_KP_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_MINUS); register_code16(KC_KP_MINUS);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_MINUS); break;
        case SINGLE_HOLD: unregister_code16(DE_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_MINUS); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_COMMA); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_COMMA); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[8].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};

