#include QMK_KEYBOARD_H
#include <jenspets.h>

#ifdef RGBLIGHT_ENABLE
static rgblight_config_t rgb_default;
#endif

void keyboard_post_init_user(void){
#ifdef RGBLIGHT_ENABLE
    rgb_default.raw = eeconfig_read_rgblight();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    if (rgblight_is_enabled()){
	uint8_t offset;
	uint8_t rgbbase = 0;
	switch (get_highest_layer(state)){
	case _RAISE:
	    offset = 32;
	    break;
	case _LOWER:
	    offset = -32;
	    break;
	case _ADJUST:
	    /* No offset for adjust layer, as the hue is difficult to adjust with an offset applied */
	    offset = 0;
	    break;
#ifdef USE_PLOVER
	case _PLOVER:
	    offset = 128;
	    rgbbase = 1;
	    break;
#endif
	case _NAV:
	    offset = 64;
	    break;
	case _NUM:
	    offset = -64;
	    break;
	default:
	    rgbbase = 1;
	    offset = 0;
	}
	if (rgbbase == 0){
	    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	} else {
	    rgb_default.raw = eeconfig_read_rgblight();
	    rgblight_mode_noeeprom(rgb_default.mode);
	}
	rgblight_sethsv_noeeprom((rgb_default.hue + offset) % 255, rgb_default.sat, rgb_default.val);
    }
#endif
    
    //state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);    
    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
#ifdef RGBLIGHT_ENABLE
    case RGB_HUD:
    case RGB_HUI:
    case RGB_SAD:
    case RGB_SAI:
    case RGB_VAD:
    case RGB_VAI:
	rgb_default.raw = eeconfig_read_rgblight();
	break;
#endif 
    default:
	break;
    }
}
