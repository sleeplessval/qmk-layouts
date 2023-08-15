/*
 *	    ______            Valerie's __   Super      __ __ Amazing
 *	   / ____/________ _____  ____/ /___  _  __   / //_/__  __  ______ ___  ____ _____
 *	  / __/ / ___/ __ `/ __ \/ __  / __ \| |/_/  / ,< / _ \/ / / / __ `__ \/ __ `/ __ \
 *	 / /___/ /  / /_/ / /_/ / /_/ / /_/ />  <   / /| /  __/ /_/ / / / / / / /_/ / /_/ /
 *	/_____/_/   \__, /\____/\__,_/\____/_/|_|  /_/ |_\___/\__, /_/ /_/ /_/\__,_/ .___/
 *	           /____/                                    /____/               /_/
 */
#include QMK_KEYBOARD_H
#define LCG(kc) (QK_LCTL | QK_LGUI | (kc))

typedef enum {
	BASE,
	ALT,
	FN,
	NUM
} layers;

#define TAPPING_TERM 200
typedef enum {
	TD_CAPS,
	TD_QUIT
} tap_dance;
tap_dance_action_t tap_dance_actions[] = {
	[TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
	[TD_QUIT] = ACTION_TAP_DANCE_DOUBLE(LSG(KC_ESC), LSG(KC_Q))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	//	Base Layer
	[BASE] = LAYOUT_ergodox_pretty(
		KC_ESC,		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,					KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_DEL,		KC_BSPC,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_BSPC,				KC_LBRC,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSLS,
		MO(1),		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,											KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
		KC_LCTL,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_SPC,					KC_RBRC,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_ENT,
		TD(TD_CAPS),KC_NO,		KC_NO,		KC_LGUI,	KC_LALT,																KC_RALT,	LSG(KC_S),	KC_RCTL,	KC_APP,		OSL(2),

																	KC_INS,		KC_BRK,					KC_HOME,	KC_END,
																				LAG(KC_SPC),			KC_PGUP,
														KC_SPC,		KC_LSFT,	KC_LGUI,				KC_PGDN,	KC_BSPC,	KC_ENT
	),
	//	Alt Layer
	[ALT] = LAYOUT_ergodox_pretty(
		KC_TRNS,	KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,				KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_UP,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_DEL,					KC_LCBR,	KC_TRNS,	KC_LBRC,	KC_RBRC,	KC_LPRN,	KC_RPRN,	KC_PIPE,
		KC_TRNS,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_TRNS,	KC_TRNS,										KC_TRNS,	KC_TRNS,	KC_MINS,	KC_EQL,		KC_COLN,	KC_DQUO,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_RCBR,	KC_TRNS,	KC_TRNS,	KC_LT,		KC_GT,		KC_QUES,	KC_NO,
		KC_LSFT,	KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,																KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,

																	KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_TRNS,
																				KC_F7,					KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_TRNS,	KC_TRNS
	),
	//	Fn Layer
	[FN] = LAYOUT_ergodox_pretty(
		TD(TD_QUIT),G(KC_GRV),	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,					KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_TRNS,
		RGB_TOG,	LCG(KC_LEFT),G(KC_UP),	LCG(KC_RGHT),KC_NO,		KC_NO,		KC_NO,					KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_F12,
		RGB_MOD,	G(KC_LEFT),	G(KC_DOWN),	G(KC_RGHT),	LSG(KC_SPC),KC_NO,											KC_TRNS,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_RSFT,
		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,					KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
		KC_LSFT,	KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,																KC_TRNS,	KC_NO,		KC_TRNS,	KC_NO,		KC_NO,

																	KC_NO,		KC_NO,					KC_MPRV,	KC_MNXT,
																				KC_NO,					KC_SCRL,
														KC_MPLY,	KC_TRNS,	KC_TRNS,				KC_NO,		KC_TRNS,	KC_TRNS
	),
	[NUM] = LAYOUT_ergodox_pretty(
		KC_ESC,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,					KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_PPLS,	KC_NO,		KC_BSPC,
		KC_TAB,		KC_7,		KC_8,		KC_9,		KC_NO,		KC_NO,		KC_BSPC,				KC_BSPC,	KC_7,		KC_8,		KC_9,		KC_PMNS,	KC_NO,		KC_NO,
		KC_LSFT,	KC_4,		KC_5,		KC_6,		KC_NO,		KC_NO,											KC_4,		KC_5,		KC_6,		KC_PAST,	KC_NO,		KC_QUOT,
		KC_LCTL,	KC_1,		KC_2,		KC_3,		KC_NO,		KC_NO,		KC_PENT,				KC_PENT,	KC_1,		KC_2,		KC_3,		KC_PSLS,	KC_SLSH,	KC_ENT,
		KC_NO,		TG(BASE),	KC_0,		KC_DOT,		KC_LALT,																KC_0,		KC_DOT,		KC_NO,		KC_NO,		KC_NO,

																	KC_NO,		KC_NO,					KC_NO,		KC_NO,
																				KC_NO,					KC_PGUP,
														KC_SPC,		KC_LSFT,	KC_LGUI,				KC_PGDN,	KC_BSPC,	KC_ENT
	)
};

void keyboard_post_init_user(void) {
	rgblight_disable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();

	uint8_t layer = get_highest_layer(state);
	switch(layer) {
		case ALT:
			ergodox_right_led_1_on();
			break;
		case FN:
			ergodox_right_led_2_on();
			break;
		case NUM:
			ergodox_right_led_3_on();
			break;
	}
	
	return state;
}

