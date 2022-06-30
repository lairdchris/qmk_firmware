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
 * Seemann's keymap for the Ferris Sweep keyboard.
 *
 * OS must be set to German keyboard layout (because of the umlauts).
 *
 */

enum sweep_layers {
  BASE,
  SYM,
  NUM,
  MOU,
  NAV
};

enum tap_dance_codes {
  ACUT_D,
  QUOT_D,
  DQUO_D,
  TAB_D,
  COLN_D,
  DOT_D,
  ADIA_D,
  UDIA_D,
  ODIA_D
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
* Second row is hold-key.
*
* Layer BASE
* ,------------------------------------------.     ,--------------------------------------------.
* |   q   |    w   |   f   |   p   |    b    |     |    j    |    l    |   u   |    y   | Bksp  |
* |       |        |       |       |         |     |         |         |       |        |       |
* |------------------------------------------+     |--------------------------------------------+
* |   a   |    r   |   s   |   t   |    g    |     |    m    |    n    |   e   |    i   |   o   |
* | Shift |  Ctrl  |  Alt  |  Gui  |  _MOU_  |     |  _MOU_  |   Gui   |  Alt  |  Ctrl  | Shift |
* |------------------------------------------+     |--------------------------------------------+
* |   z   |    x   |   c   |   d   |    v    |     |    k    |    h    |  ,    |    .   |   /   |
* |       |        |       |       |         |     |         |         |       |        |       |
* |------------------------------------------+     |--------------------------------------------+
* |                        | Space |  Space  |     |  Space  |  Space  |                        |
* |                        | _SYM_ |  Shift  |     |  Shift  |  _NUM_  |                        |
* \------------------------------------------/     \--------------------------------------------/
*/
	[BASE] = LAYOUT_split_3x5_2(
			KC_Q,             KC_W,           KC_F,            KC_P,            KC_B,            /* */   KC_J,           KC_L,            KC_U,          DE_Y,            KC_BSPC, 
			LSFT_T(KC_A),     LCTL_T(KC_R),   LALT_T(KC_S),    LGUI_T(KC_T),    LT(4,KC_G),      /* */   LT(4,KC_M),     LGUI_T(KC_N),    LALT_T(KC_E),  LCTL_T(KC_I),    LSFT_T(KC_O), 
			DE_Z,             KC_X,           KC_C,            KC_D,            KC_V,            /* */   KC_K,           KC_H,            KC_COMM,       KC_DOT,          DE_SLSH, 
			                                                   LT(1,KC_SPC),    LSFT_T(KC_SPC),  /* */   LSFT_T(KC_SPC), LT(2,KC_SPC)),
/*
* Layer SYM
* ,------------------------------------------.     ,--------------------------------------------.
* |   !   |    @   |   #   |   $   |    %    |     |    ^    |    &    |   *   |    ;   |   :   |
* |       |        |       |       |         |     |         |         |       |        |       |
* |------------------------------------------+     |--------------------------------------------+
* |   ä   |    ß   |   ö   |   ü   |    =    |     |    +    |    `    |   '   |    "   | Enter |
* |   Ä   |        |   Ö   |   Ü   |         |     |         |   Gui   |  Alt  |  Ctrl  | Shift |
* |------------------------------------------+     |--------------------------------------------+
* |   €   |        |       |       |         |     |    -    |         |   <   |    >   |   ?   |
* |       |        |       |       |         |     |         |         |       |        |       |
* |------------------------------------------+     |--------------------------------------------+
* |                        |       |         |     |         |         |                        |
* |                        |       |         |     |         |  _NAV_  |                        |
* \------------------------------------------/     \--------------------------------------------/
*/
	[SYM] = LAYOUT_split_3x5_2(
      DE_EXLM,         DE_AT,           DE_HASH,         DE_DLR,          DE_PERC,         /* */   DE_CIRC,        DE_AMPR,         DE_ASTR,       DE_SCLN,         DE_COLN,
      TD(ADIA_D),      DE_SS,           TD(ODIA_D),      TD(UDIA_D),      DE_EQL,          /* */   DE_PLUS,        TD(ACUT_D),      TD(QUOT_D),    TD(DQUO_D),      LSFT_T(KC_ENT),
      DE_EURO,         KC_NO,           KC_NO,           KC_NO,           KC_NO,           /* */   DE_MINS,        KC_NO,           DE_LABK,       DE_RABK,         DE_QUES,
                                                         KC_NO,           KC_NO,           /* */   KC_NO,          MO(3)),      
/*
* Layer NUM
* ,------------------------------------------.     ,--------------------------------------------.
* |  Tab  |    '   |   {   |   }   |    _    |     |    -    |    7    |   8   |    9   |   *   |
* |Gui+Tab|        |       |       |         |     |    :    |         |       |        |       |
* |------------------------------------------+     |--------------------------------------------+
* |  Esc  |    |   |   (   |   )   |    =    |     |    +    |    4    |   5   |    6   | Enter |
* | Shift |  Ctrl  |  Alt  |  Gui  |         |     |         |   Gui   |  Alt  |  Ctrl  | Shift |
* |------------------------------------------+     |--------------------------------------------+
* |       |    ~   |   [   |   ]   |    \    |     |    0    |    1    |   2   |    3   |   .   |
* |       |        |       |       |         |     |         |         |       |        |   ,   |
* |------------------------------------------+     |--------------------------------------------+
* |                        |       |         |     |         |         |                        |
* |                        | _NAV_ |         |     |         |         |                        |
* \------------------------------------------/     \--------------------------------------------/
*/
	[NUM] = LAYOUT_split_3x5_2(
      TD(TAB_D),       DE_ACUT,         DE_LCBR,         DE_RCBR,         DE_UNDS,         /* */   TD(COLN_D),     KC_7,            KC_8,          KC_9,            DE_ASTR, 
      LSFT_T(KC_ESC),  DE_PIPE,         DE_LPRN,         DE_RPRN,         DE_EQL,          /* */   DE_PLUS,        LGUI_T(KC_4),    LALT_T(KC_5),  LCTL_T(KC_6),    LSFT_T(KC_ENT), 
      KC_NO,           DE_TILD,         DE_LBRC,         DE_RBRC,         DE_BSLS,         /* */   KC_0,           KC_1,            KC_2,          KC_3,            TD(DOT_D), 
                                                         MO(3),           KC_NO,           /* */   KC_NO,          KC_NO),
/*
* Layer NAV
* ,------------------------------------------.     ,--------------------------------------------.
* |   F1  |   F2   |   F3  |   F4  |   F5    |     |   F6   |   F7    |   F8  |   F9   |  F10  |
* |       |        |       |       |         |     |        |         |       |        |       |
* |------------------------------------------+     |-------------------------------------------+
* | Home  |   Ins  |  PgUp | PgDown|   Del   |     |  Left  |   Down  |   Up  |  Right |  End  |
* | Shift |  Ctrl  |  Alt  |  Gui  |         |     |        |   Gui   |  Alt  |  Ctrl  | Shift |
* |------------------------------------------+     |-------------------------------------------+
* |       |        |       |       |         |     |        |         |       |   F11  |  F12  |
* |       |        |       |       |         |     |        |         |       |        |       |
* |------------------------------------------+     |-------------------------------------------+
* |                        |       |         |     |        |         |                        |
* |                        |       |         |     |        |         |                        |
* \------------------------------------------/     \-------------------------------------------/
*/
	[NAV] = LAYOUT_split_3x5_2(
      KC_F1,           KC_F2,           KC_F3,           KC_F4,           KC_F5,           /* */   KC_F6,          KC_F7,           KC_F8,         KC_F9,           KC_F10, 
      LSFT_T(KC_HOME), LCTL_T(KC_INS),  LALT_T(KC_PGUP), LGUI_T(KC_PGDN), KC_DEL,          /* */   KC_LEFT,        LGUI_T(KC_DOWN), LALT_T(KC_UP), LCTL_T(KC_RGHT), LSFT_T(KC_END), 
      KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           /* */   KC_NO,          KC_NO,           KC_NO,         KC_F11,          KC_F12, 
                                                         KC_NO,           KC_NO,           /* */   KC_NO,          KC_NO),
/*
* Layer MOU
* ,------------------------------------------.     ,--------------------------------------------.
* | Mute  | Whl le | Mo up | Whl rg| Whl up  |     |        |  Prev   |  Play |  Next  |       |
* |       |        |       |       |         |     |        |         |       |        |       |
* |------------------------------------------+     |-------------------------------------------+
* | Vol + |  Mo le | Mo dn | Mo rg | Whl dn  |     |        |  Btn 1  | Btn 3 | Btn 2  |       |
* |       |        |       |       |         |     |        |         |       |        |       |
* |------------------------------------------+     |-------------------------------------------+
* | Vol - |        |       |       |         |     |        |  Acc 0  | Acc 1 | Acc 2  | Reset |
* |       |        |       |       |         |     |        |         |       |        |       |
* |------------------------------------------+     |-------------------------------------------+
* |                        |       |         |     |        |         |                        |
* |                        |       |         |     |        |         |                        |
* \------------------------------------------/     \-------------------------------------------/
*/
	[MOU] = LAYOUT_split_3x5_2(
      KC_MUTE,         KC_WH_L,         KC_MS_U,         KC_WH_R,         KC_WH_U,         /* */   KC_NO,          KC_MRWD,         KC_MPLY,       KC_MFFD,         KC_NO, 
      KC_VOLU,         KC_MS_L,         KC_MS_D,         KC_MS_R,         KC_WH_D,         /* */   KC_NO,          KC_BTN1,         KC_BTN3,       KC_BTN2,         KC_NO, 
      KC_VOLD,         KC_NO,           KC_NO,           KC_NO,           KC_NO,           /* */   KC_NO,          KC_ACL0,         KC_ACL1,       KC_ACL2,         RESET,
                                                         KC_NO,           KC_TRNS,         /* */   KC_TRNS,        KC_NO)
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

void on_acut_dance(qk_tap_dance_state_t *state, void *user_data);
void acut_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void acut_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_acut_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_ACUT);
        tap_code16(DE_ACUT);
        tap_code16(DE_ACUT);
    }
    if(state->count > 3) {
        tap_code16(DE_ACUT);
    }
}

void acut_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(DE_ACUT); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(DE_ACUT); register_code16(DE_ACUT); break;
        case DOUBLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_ACUT); register_code16(DE_ACUT);
    }
}

void acut_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_quot_dance(qk_tap_dance_state_t *state, void *user_data);
void quot_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void quot_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_quot_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_QUOT);
        tap_code16(DE_QUOT);
        tap_code16(DE_QUOT);
    }
    if(state->count > 3) {
        tap_code16(DE_QUOT);
    }
}

void quot_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(DE_QUOT); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(DE_QUOT); register_code16(DE_QUOT); break;
        case DOUBLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_QUOT); register_code16(DE_QUOT);
    }
}

void quot_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
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
void on_dquo_dance(qk_tap_dance_state_t *state, void *user_data);
void dquo_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dquo_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dquo_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_DQUO);
        tap_code16(DE_DQUO);
        tap_code16(DE_DQUO);
    }
    if(state->count > 3) {
        tap_code16(DE_DQUO);
    }
}

void dquo_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(DE_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(DE_DQUO); register_code16(DE_DQUO); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_DQUO); register_code16(DE_DQUO);
    }
}

void dquo_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
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

void on_tab_dance(qk_tap_dance_state_t *state, void *user_data);
void tab_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void tab_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_tab_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void tab_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void tab_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[3].step = 0;
}
void on_coln_dance(qk_tap_dance_state_t *state, void *user_data);
void coln_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void coln_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_coln_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_MINUS);
        tap_code16(KC_KP_MINUS);
        tap_code16(KC_KP_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_MINUS);
    }
}

void coln_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_KP_MINUS); break;
        case SINGLE_HOLD: register_code16(DE_COLN); break;
        case DOUBLE_TAP: register_code16(KC_KP_MINUS); register_code16(KC_KP_MINUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_MINUS); register_code16(KC_KP_MINUS);
    }
}

void coln_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_MINUS); break;
        case SINGLE_HOLD: unregister_code16(DE_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_MINUS); break;
    }
    dance_state[7].step = 0;
}

void on_dot_dance(qk_tap_dance_state_t *state, void *user_data);
void dot_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dot_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dot_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dot_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_COMMA); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dot_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_COMMA); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[8].step = 0;
}

/************************************************************************
 * tap: ä
 * hold: Ä
 ***********************************************************************/
void on_adia_dance(qk_tap_dance_state_t *state, void *user_data);
void adia_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void adia_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_adia_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_ADIA);
        tap_code16(DE_ADIA);
        tap_code16(DE_ADIA);
    }
    if(state->count > 3) {
        tap_code16(DE_ADIA);
    }
}

void adia_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(DE_ADIA); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); register_code16(DE_ADIA); break;
        case DOUBLE_TAP: register_code16(DE_ADIA); register_code16(DE_ADIA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_ADIA); register_code16(DE_ADIA);
    }
}

void adia_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(DE_ADIA); break;
        case SINGLE_HOLD: unregister_code16(DE_ADIA); unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(DE_ADIA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_ADIA); break;
    }
    dance_state[8].step = 0;
}

/************************************************************************
 * tap: ö
 * hold: Ö
 ***********************************************************************/
void on_odia_dance(qk_tap_dance_state_t *state, void *user_data);
void odia_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void odia_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_odia_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_ODIA);
        tap_code16(DE_ODIA);
        tap_code16(DE_ODIA);
    }
    if(state->count > 3) {
        tap_code16(DE_ODIA);
    }
}

void odia_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(DE_ODIA); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); register_code16(DE_ODIA); break;
        case DOUBLE_TAP: register_code16(DE_ODIA); register_code16(DE_ODIA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_ODIA); register_code16(DE_ODIA);
    }
}

void odia_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(DE_ODIA); break;
        case SINGLE_HOLD: unregister_code16(DE_ODIA); unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(DE_ODIA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_ODIA); break;
    }
    dance_state[8].step = 0;
}

/************************************************************************
 * tap: ü
 * hold: Ü
 ***********************************************************************/
void on_udia_dance(qk_tap_dance_state_t *state, void *user_data);
void udia_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void udia_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_udia_dance(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(DE_UDIA);
        tap_code16(DE_UDIA);
        tap_code16(DE_UDIA);
    }
    if(state->count > 3) {
        tap_code16(DE_UDIA);
    }
}

void udia_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(DE_UDIA); break;
        case SINGLE_HOLD: register_code16(KC_LSFT); register_code16(DE_UDIA); break;
        case DOUBLE_TAP: register_code16(DE_UDIA); register_code16(DE_UDIA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(DE_UDIA); register_code16(DE_UDIA);
    }
}

void udia_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(DE_UDIA); break;
        case SINGLE_HOLD: unregister_code16(DE_UDIA); unregister_code16(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code16(DE_UDIA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(DE_UDIA); break;
    }
    dance_state[8].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [ACUT_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_acut_dance, acut_dance_finished, acut_dance_reset),
        [QUOT_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_quot_dance, quot_dance_finished, quot_dance_reset),
        [DQUO_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dquo_dance, dquo_dance_finished, dquo_dance_reset),
        [TAB_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_tab_dance, tab_dance_finished, tab_dance_reset),
        [COLN_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_coln_dance, coln_dance_finished, coln_dance_reset),
        [DOT_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dot_dance, dot_dance_finished, dot_dance_reset),
        [ADIA_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_adia_dance, adia_dance_finished, adia_dance_reset),
        [ODIA_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_odia_dance, odia_dance_finished, odia_dance_reset),
        [UDIA_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_udia_dance, udia_dance_finished, udia_dance_reset),
};

