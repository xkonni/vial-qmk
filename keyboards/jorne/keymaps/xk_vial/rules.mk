# SRC += ./lib/logo.c
SRC += ./lib/layer_status/layer_status.c
SRC += ./lib/bongocat/bongocat.c

VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes		# compile optimization, reduce size

# Can't have RGBLIGHT and RGB_MATRIX at the same time.
RGBLIGHT_ENABLE     = no
RGB_MATRIX_ENABLE   = yes
RGB_MATRIX_DRIVER   = ws2812
VIALRGB_ENABLE 		= yes

OLED_ENABLE         = yes
OLED_DRIVER 		= ssd1306
COMBO_ENABLE        = no
MOUSEKEY_ENABLE 	= no      	# Mouse keys
EXTRAKEY_ENABLE 	= yes     	# Audio control and System control
SPACE_CADET_ENABLE  = yes	    # ( on tap L_SFT, ) on tap R_SFT

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE 	= no    	# Breathing sleep LED during USB suspend
QMK_SETTINGS        = no

WPM_ENABLE 			= yes
