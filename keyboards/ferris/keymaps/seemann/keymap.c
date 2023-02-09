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

enum sweep_layers { BASE, SYM, NUM, MOU, NAV };

enum tap_dance_codes {
    ACUT_D,
    QUOT_D,
    DQUO_D,
    COLN_D,
    DOT_D,
    PLUS_D,
    ESC_D,
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
     * | Shift |  Ctrl  |  Alt  |  Gui  |  _NAV_  |     |  _NAV_  |   Gui   |  Alt  |  Ctrl  | Shift |
     * |------------------------------------------+     |--------------------------------------------+
     * |   z   |    x   |   c   |   d   |    v    |     |    k    |    h    |  ,    |    .   |   /   |
     * |       |        |       |       |         |     |         |         |       |        |       |
     * \------------------------------------------+     |--------------------------------------------/
     *                          | Space |   Esc   |     |   Tab   |  Space  |
     *                          | _SYM_ |         |     |         |  _NUM_  |
     *                          \-----------------/     \-------------------/
     */
    [BASE] = LAYOUT_split_3x5_2(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,        /* */ KC_J,        KC_L,         KC_U,         DE_Y,         KC_BSPC,
        LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), LT(NAV, KC_G), /* */ LT(NAV, KC_M), RGUI_T(KC_N), LALT_T(KC_E), RCTL_T(KC_I), RSFT_T(KC_O),
        DE_Z,         KC_X,         KC_C,         KC_D,         KC_V,        /* */ KC_K,        KC_H,         KC_COMM,      KC_DOT,       DE_SLSH,
                                                 LT(SYM, KC_SPC), TD(ESC_D), /* */ KC_LSFT, LT(NUM, KC_SPC)
    ),
    /*
     * Layer SYM
     * ,------------------------------------------.     ,--------------------------------------------.
     * |   !   |    @   |   #   |   $   |    %    |     |    ^    |    &    |   *   |    ;   |   :   |
     * |       |        |       |       |         |     |         |         |       |        |       |
     * |------------------------------------------+     |--------------------------------------------+
     * |   ä   |    ö   |   ß   |   ü   |    €    |     |    +    |    `    |   '   |    "   | Enter |
     * | Shift |  Ctrl  |  Alt  |  Gui  |         |     |  Home   |  PgDn   | PgUp  |   End  |       |
     * |------------------------------------------+     |--------------------------------------------+
     * |       |    ~   |   \   |   |   |         |     |    -    |    _    |   <   |    >   |   ?   |
     * |       |        |       |       |         |     |         |         |       |        |       |
     * \------------------------------------------+     |--------------------------------------------/
     *                          |       |   Esc   |     |   Tab   |         |
     *                          |       |         |     |         |  _MOU_  |
     *                          \-----------------/     \-------------------/
     */
    [SYM] = LAYOUT_split_3x5_2(
        DE_EXLM,         DE_AT,           DE_HASH,       DE_DLR,          DE_PERC, /* */ DE_CIRC,    DE_AMPR,    DE_ASTR,    DE_SCLN,    DE_COLN,
        LSFT_T(DE_ADIA), LCTL_T(DE_ODIA), LALT_T(DE_SS), LGUI_T(DE_UDIA), DE_EURO, /* */ TD(PLUS_D), TD(ACUT_D), TD(QUOT_D), TD(DQUO_D), KC_ENT,
        XXXXXXX,         DE_TILD,         DE_BSLS,       DE_PIPE,         XXXXXXX, /* */ DE_MINS,    DE_UNDS,    DE_LABK,    DE_RABK,    DE_QUES,
                                                                  XXXXXXX, KC_ESC, /* */ KC_LSFT, MO(MOU)
    ),
    /*
     * Layer NUM
     * ,------------------------------------------.     ,--------------------------------------------.
     * |       |        |   {   |   }   |         |     |    -    |    7    |   8   |    9   |   *   |
     * |       |        |       |       |         |     |         |         |       |        |   :   |
     * |------------------------------------------+     |--------------------------------------------+
     * |  Tab  |    ;   |   (   |   )   |    =    |     |    +    |    4    |   5   |    6   | Enter |
     * |       |        |       |       |         |     |         |         |       |        |       |
     * |------------------------------------------+     |--------------------------------------------+
     * |       |        |   [   |   ]   |         |     |    0    |    1    |   2   |    3   |   .   |
     * |       |        |       |       |         |     |         |         |       |        |   ,   |
     * \------------------------------------------+     |--------------------------------------------/
     *                          |       |   Esc   |     |   Tab   |         |
     *                          | _MOU_ |         |     |         |         |
     *                          \-----------------/     \-------------------/
     */
    [NUM] = LAYOUT_split_3x5_2(
        XXXXXXX, XXXXXXX, DE_LCBR, DE_RCBR, XXXXXXX, /* */ KC_KP_MINUS, KC_7, KC_8, KC_9, TD(COLN_D),
        KC_TAB,  DE_SCLN, DE_LPRN, DE_RPRN, DE_EQL,  /* */ DE_PLUS,     KC_4, KC_5, KC_6, KC_ENT,
        XXXXXXX, XXXXXXX, DE_LBRC, DE_RBRC, XXXXXXX, /* */ KC_0,        KC_1, KC_2, KC_3, TD(DOT_D),
                                      MO(MOU), KC_ESC, /* */ KC_TAB, XXXXXXX
    ),
    /*
     * Layer NAV
     * ,------------------------------------------.     ,--------------------------------------------.
     * |   F1  |   F2   |   F3  |   F4  |         |     |  Home  |         |       |   Ins  |  Del  |
     * |       |        |       |       |         |     |        |         |       |        |       |
     * |------------------------------------------+     |-------------------------------------------+
     * |   F5  |   F6   |   F7  |   F8  |         |     |  Left  |   Down  |   Up  |  Right |  End  |
     * | Shift |  Ctrl  |  Alt  |  Gui  |         |     |        |   Gui   |  Alt  |  Ctrl  | Shift |
     * |------------------------------------------+     |-------------------------------------------+
     * |   F9  |  F10   |  F11  |  F12  |         |     |  End   |   PgDn  |  PgUp |        |       |
     * |       |        |       |       |         |     |        |         |       |        |       |
     * \------------------------------------------+     |-------------------------------------------/
     *                          |       |   Esc   |     |  Tab   |         |
     *                          |       |         |     |        |         |
     *                          \-----------------/     \------------------/
     */
    [NAV] = LAYOUT_split_3x5_2(
        KC_F1,         KC_F2,         KC_F3,         KC_F4,         XXXXXXX, /* */ KC_HOME, XXXXXXX,         XXXXXXX,       KC_INS,          KC_DEL,
        LSFT_T(KC_F5), LCTL_T(KC_F6), LALT_T(KC_F7), LGUI_T(KC_F8), XXXXXXX, /* */ KC_LEFT, RGUI_T(KC_DOWN), LALT_T(KC_UP), RCTL_T(KC_RGHT), RSFT_T(KC_END),
        KC_F9,         KC_F10,        KC_F11,        KC_F12,        XXXXXXX, /* */ KC_END,  KC_PGDN,         KC_PGUP,       XXXXXXX,         XXXXXXX,
                                                            XXXXXXX, KC_ESC, /* */ KC_TAB, XXXXXXX
    ),
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
     * \------------------------------------------+     |-------------------------------------------/
     *                          |       |         |     |        |         |
     *                          |       |         |     |        |         |
     *                          \-----------------/     \------------------/
     */
    [MOU] = LAYOUT_split_3x5_2(
        KC_MUTE, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, /* */ XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX,
        KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, /* */ XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX,
        KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /* */ XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, RESET,
                                   XXXXXXX, _______, /* */ _______, XXXXXXX
    )
};

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[9];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_acut_dance(qk_tap_dance_state_t *state, void *user_data);
void acut_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void acut_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_acut_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(DE_ACUT);
        tap_code16(DE_ACUT);
        tap_code16(DE_ACUT);
    }
    if (state->count > 3) {
        tap_code16(DE_ACUT);
    }
}

void acut_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(DE_ACUT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_PGDN);
            break;
        case DOUBLE_TAP:
            register_code16(DE_ACUT);
            register_code16(DE_ACUT);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_DOWN);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(DE_ACUT);
            register_code16(DE_ACUT);
    }
}

void acut_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(DE_ACUT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_PGDN);
            break;
        case DOUBLE_TAP:
            unregister_code16(DE_ACUT);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_DOWN);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(DE_ACUT);
            break;
    }
    dance_state[0].step = 0;
}
void on_quot_dance(qk_tap_dance_state_t *state, void *user_data);
void quot_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void quot_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_quot_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(DE_QUOT);
        tap_code16(DE_QUOT);
        tap_code16(DE_QUOT);
    }
    if (state->count > 3) {
        tap_code16(DE_QUOT);
    }
}

void quot_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(DE_QUOT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_PGUP);
            break;
        case DOUBLE_TAP:
            register_code16(DE_QUOT);
            register_code16(DE_QUOT);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_UP);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(DE_QUOT);
            register_code16(DE_QUOT);
    }
}

void quot_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(DE_QUOT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_PGUP);
            break;
        case DOUBLE_TAP:
            unregister_code16(DE_QUOT);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_UP);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(DE_QUOT);
            break;
    }
    dance_state[1].step = 0;
}
void on_dquo_dance(qk_tap_dance_state_t *state, void *user_data);
void dquo_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dquo_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dquo_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(DE_DQUO);
        tap_code16(DE_DQUO);
        tap_code16(DE_DQUO);
    }
    if (state->count > 3) {
        tap_code16(DE_DQUO);
    }
}

void dquo_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(DE_DQUO);
            break;
        case SINGLE_HOLD:
            register_code16(KC_END);
            break;
        case DOUBLE_TAP:
            register_code16(DE_DQUO);
            register_code16(DE_DQUO);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(DE_DQUO);
            register_code16(DE_DQUO);
    }
}

void dquo_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(DE_DQUO);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_END);
            break;
        case DOUBLE_TAP:
            unregister_code16(DE_DQUO);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(DE_DQUO);
            break;
    }
    dance_state[2].step = 0;
}

void on_coln_dance(qk_tap_dance_state_t *state, void *user_data);
void coln_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void coln_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_coln_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(DE_ASTR);
        tap_code16(DE_ASTR);
        tap_code16(DE_ASTR);
    }
    if (state->count > 3) {
        tap_code16(DE_ASTR);
    }
}

void coln_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            register_code16(DE_ASTR);
            break;
        case SINGLE_HOLD:
            register_code16(DE_COLN);
            break;
        case DOUBLE_TAP:
            register_code16(DE_ASTR);
            register_code16(DE_ASTR);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(DE_ASTR);
            register_code16(DE_ASTR);
    }
}

void coln_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            unregister_code16(DE_ASTR);
            break;
        case SINGLE_HOLD:
            unregister_code16(DE_COLN);
            break;
        case DOUBLE_TAP:
            unregister_code16(DE_ASTR);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(DE_ASTR);
            break;
    }
    dance_state[7].step = 0;
}

void on_dot_dance(qk_tap_dance_state_t *state, void *user_data);
void dot_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dot_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dot_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if (state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dot_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            register_code16(KC_COMMA);
            break;
        case DOUBLE_TAP:
            register_code16(KC_DOT);
            register_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DOT);
            register_code16(KC_DOT);
    }
}

void dot_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_COMMA);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DOT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DOT);
            break;
    }
    dance_state[8].step = 0;
}

void on_plus_dance(qk_tap_dance_state_t *state, void *user_data);
void plus_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void plus_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_plus_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(DE_PLUS);
        tap_code16(DE_PLUS);
        tap_code16(DE_PLUS);
    }
    if (state->count > 3) {
        tap_code16(DE_PLUS);
    }
}

void plus_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(DE_PLUS);
            break;
        case SINGLE_HOLD:
            register_code16(KC_HOME);
            break;
        case DOUBLE_TAP:
            register_code16(DE_PLUS);
            register_code16(DE_PLUS);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(DE_PLUS);
            register_code16(DE_PLUS);
    }
}

void plus_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(DE_PLUS);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_HOME);
            break;
        case DOUBLE_TAP:
            unregister_code16(DE_PLUS);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(DE_PLUS);
            break;
    }
    dance_state[8].step = 0;
}

void on_esc_dance(qk_tap_dance_state_t *state, void *user_data);
void esc_dance_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_esc_dance(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ESC);
        tap_code16(KC_ESC);
        tap_code16(KC_ESC);
    }
    if (state->count > 3) {
        tap_code16(KC_ESC);
    }
}

void esc_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_ESC);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSFT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LCTL);
            register_code16(KC_LGUI);
            register_code16(KC_LEFT);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_ESC);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ESC);
            register_code16(KC_ESC);
    }
}

void esc_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ESC);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LSFT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LEFT);
            unregister_code16(KC_LGUI);
            unregister_code16(KC_LCTL);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_ESC);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ESC);
            break;
    }
    dance_state[8].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [ACUT_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_acut_dance, acut_dance_finished, acut_dance_reset),
    [QUOT_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_quot_dance, quot_dance_finished, quot_dance_reset),
    [DQUO_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dquo_dance, dquo_dance_finished, dquo_dance_reset),
    [COLN_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_coln_dance, coln_dance_finished, coln_dance_reset),
    [DOT_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_dot_dance, dot_dance_finished, dot_dance_reset),
    [PLUS_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_plus_dance, plus_dance_finished, plus_dance_reset),
    [ESC_D] = ACTION_TAP_DANCE_FN_ADVANCED(on_esc_dance, esc_dance_finished, esc_dance_reset),
};
