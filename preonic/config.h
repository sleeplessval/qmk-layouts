#pragma once

#ifdef AUDIO_ENABLE
	#define AUDIO_INIT_DELAY
	#define NO_MUSIC_MODE

	#define BOOT_SONG Q__NOTE(_F5), Q__NOTE(_G5), Q__NOTE(_C6)
	#define STARTUP_SONG SONG(BOOT_SONG)

	#define TONE_BASE	S__NOTE(_C5)
	#define TONE_ALT	S__NOTE(_F5)
	#define TONE_FN		S__NOTE(_G5)
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define MIDI_BASIC

#ifdef RGBLIGHT_ENABLE
	#define RGBLIGHT_SLEEP

	#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif

