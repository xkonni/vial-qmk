// Copyright 2021 Nicolas Druoton (druotoni)
// Copyright 2012 Jun Wako <wakojun@gmail.com>
// Copyright 2015 Jack Humbert
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


//#define EE_HANDS
//#define SPLIT_USB_DETECT
//#define WAIT_FOR_USB

#define VIAL_KEYBOARD_UID {0x80, 0x41, 0x59, 0xF5, 0x4B, 0xF3, 0x50, 0x97}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}


//#define MASTER_LEFT
#define OLED_DRIVER_ENABLE

// tapping toggle for my layers
#define TAPPING_TOGGLE 2

// choose IS_LEFT or IS_RIGHT for compilation and flash firmware
//#define IS_LEFT 1
#define IS_RIGHT 1

//logo glitch
#define WITH_GLITCH
// boot sequence
#define WITH_BOOT

// custom transport for displaying on both side
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A

// custom font
#ifdef OLED_FONT_H
#    undef OLED_FONT_H
#endif
#define OLED_FONT_H "navi_font.c"
#undef OLED_FONT_END
#define OLED_FONT_END 125

// more space
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define NO_ACTION_ONESHOT
//#define DISABLE_LEADER




// ???
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// small layer state
//#define LAYER_STATE_8BIT

// no debug or trace
//#ifndef NO_DEBUG
//#    define NO_DEBUG
//#endif
//#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
//#    define NO_PRINT
//#endif








#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT

#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif



/*

#if defined(KEYBOARD_sofle_rev1)
#	 define OLED_TITLE_PRIMARY ""
#	 define OLED_TITLE_SECONDARY ""
// Add RGB underglow and top facing lighting
#    define RGB_DI_PIN D3
#    define RGBLED_NUM 44
#    define RGBLED_SPLIT \
        { 22, 22 }
#	 define SPLIT_WPM_ENABLE
#    define SPLIT_OLED_ENABLE
#    ifdef RGB_MATRIX_ENABLE
#        define DRIVER_LED_TOTAL RGBLED_NUM
#        define RGB_MATRIX_SPLIT RGBLED_SPLIT
#        define SPLIT_TRANSPORT_MIRROR
#    else
//#        define RGBLIGHT_ANIMATIONS
#        define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#        define RGBLIGHT_LIMIT_VAL 120
#        define RGBLIGHT_HUE_STEP  10
#        define RGBLIGHT_SAT_STEP  17
#        define RGBLIGHT_VAL_STEP  17
#    endif
#endif

*/

//#define SPLIT_USB_TIMEOUT 5000
//#define USB_VBUS_PI GP24
//#define NO_USB_STARTUP_CHECK

//#define SPLIT_USB_DETECT
