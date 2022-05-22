/*
 *	    ____     Valerie's          _         __ __
 *	   / __ \________  ____  ____  (_)____   / //_/__  __  ______ ___  ____ _____
 *	  / /_/ / ___/ _ \/ __ \/ __ \/ / ___/  / ,< / _ \/ / / / __ `__ \/ __ `/ __ \
 *	 / ____/ /  /  __/ /_/ / / / / / /__   / /| /  __/ /_/ / / / / / / /_/ / /_/ /
 *	/_/   /_/   \___/\____/_/ /_/_/\___/  /_/ |_\___/\__, /_/ /_/ /_/\__,_/ .___/
 *	                                                /____/               /_/
 */
#include QMK_KEYBOARD_H
#define LCG(kc) ( QK_LCTL | QK_LGUI | (kc) )

typedef enum {
	BASE,
	ALT,
	FN
} layers;

#define TAPPING_TERM 200
typedef enum {
	TD_QUIT
} tap_dance;
qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_QUIT] = ACTION_TAP_DANCE_DOUBLE(G(KC_ESC), LSG(KC_Q))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ortho_5x12(
		KC_ESC,		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSLS,
		MO(1),		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
		KC_LCTL,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_ENT,
		KC_NO,		TG(1),		KC_LALT,	KC_LGUI,	KC_SPC,		KC_LSFT,	KC_BSPC,	KC_ENT,		KC_RALT,	KC_RCTL,	KC_APP,		OSL(2)
	),
	[ALT] = LAYOUT_ortho_5x12(
		KC_ESC,		KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,
		KC_TRNS,	KC_TRNS,	KC_UP,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_LPRN,	KC_RPRN,	KC_LBRC,	KC_RBRC,	KC_PIPE,
		KC_TRNS,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_MINS,	KC_EQL,		KC_COLN,	KC_DQUO,
		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_LT,		KC_GT,		KC_TRNS,	KC_DEL,
		TG(0),		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_DEL,		KC_ENT,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_NO
	),
	[FN] = LAYOUT_ortho_5x12(
		TD(TD_QUIT),LGUI(KC_ESC),	KC_F1,			KC_F2,			KC_F3,		KC_F4,	KC_F5,	KC_F6,	KC_F7,		KC_F8,	KC_F9,		KC_F10,
		RGB_TOG,	LCG(KC_LEFT),	LGUI(KC_UP),	LCG(KC_RGHT),	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_NO,		KC_F11,
		KC_NO,		LGUI(KC_LEFT),	LGUI(KC_DOWN),	LGUI(KC_RGHT),	KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,	KC_NO,		KC_F12,
		KC_NO,		KC_NO,			KC_NO,			KC_NO,			KC_NO,		KC_NO,	KC_NO,	KC_NO,	KC_HOME,	KC_END,	KC_NO,		KC_NO,
		KC_PGDN,	KC_PGUP,		KC_NO,			KC_NO,			KC_MPLY,	KC_NO,	KC_NO,	KC_NO,	KC_NO,		KC_NO,	LSG(KC_S),	KC_NO
	)
};

#define RGBLIGHT_SLEEP
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL

#ifdef AUDIO_ENABLE
	#define STARTUP_SONG SONG(PREONIC_SOUND)
	#define BOOT_SONG HD_NOTE(_F5), HD_NOTE(_G5), HD_NOTE(_C6)

	#define TONE_FN HD_NOTE(_G5)

	float boot_song[][2] = SONG(BOOT_SONG);
	float tone_fn[][2] = SONG(TONE_FN);
#endif

void keyboard_post_init_user(void) {
	#ifdef BOOT_SONG
		PLAY_SONG(boot_song);
	#endif
	rgblight_disable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
	uint8_t layer = get_highest_layer(state);
	switch(layer) {
		case FN:
			#ifdef TONE_FN
				PLAY_SONG(tone_fn);
			#endif
			break;
	}
	
	return state;
}
