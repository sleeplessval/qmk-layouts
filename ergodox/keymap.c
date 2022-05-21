
#include QMK_KEYBOARD_H

typedef enum {
	BASE,
	ALT,
	FN,
	NUM
} layers;

#define TAPPING_TERM 200
typedef enum {
	TD_CAPS
} tap_dance;
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	//	Base Layer
	[BASE] = LAYOUT_ergodox_pretty(
		KC_ESC,		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,					KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_DEL,		KC_BSPC,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_BSPC,				KC_LBRC,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSLS,
		MO(1),		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,											KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
		KC_LCTL,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_SPC,					KC_LBRC,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_ENT,
		TD(TD_CAPS),TG(NUM),	KC_NO,		KC_LGUI,	KC_LALT,																KC_RALT,	LSG(KC_S),	KC_RCTL,	KC_APP,		OSL(2),

																	KC_INS,		KC_BRK,					KC_HOME,	KC_END,
																				LAG(KC_SPC),			KC_PGUP,
														KC_SPC,		KC_LSFT,	KC_LGUI,				KC_PGDN,	KC_BSPC,	KC_ENT
	),
	//	Alt Layer
	[ALT] = LAYOUT_ergodox_pretty(
		KC_TRNS,	KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,				KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_UP,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_DEL,					KC_LCBR,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_LBRC,	KC_RBRC,	KC_PIPE,
		KC_TRNS,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_TRNS,	KC_TRNS,										KC_TRNS,	KC_TRNS,	KC_MINS,	KC_EQL,		KC_COLN,	KC_DQUO,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_RCBR,	KC_TRNS,	KC_TRNS,	KC_LT,		KC_GT,		KC_TRNS,	KC_NO,
		KC_LSFT,	KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,																KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO,

																	KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_TRNS,
																				KC_F7,					KC_TRNS,
														KC_TRNS,	KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_TRNS,	KC_TRNS
	)//,
	//	Fn Layer
//	[FN] = LAYOUT_ergodox_pretty(
//		LSG()
//	)
};

#define RGBLIGHT_SLEEP
#define RGBLIGHT_MODE_RAINBOW_SWIRL
#define RBGLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL

void keyboard_post_init_user(void) {
	rgblight_disable_noeeprom();
}

