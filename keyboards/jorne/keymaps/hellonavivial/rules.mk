# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
VIA_ENABLE      = yes
VIAL_ENABLE         = yes
# Bootloader selection
BOOTLOADER = rp2040


SPLIT_KEYBOARD = yes
QMK_SETTINGS   = no

COMMAND_ENABLE   = yes # Commands for debug and configuration
UNICODE_ENABLE   =yes# Unicode
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes





OLED_ENABLE = yes
OLED_DRIVER = ssd1306

ENCODER_ENABLE = no
#EXTRAKEY_ENABLE = yes # enable for left, disable for right?

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
LTO_ENABLE = yes
SPACE_CADET_ENABLE = yes
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE  = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./burst.c \
        ./navi_logo.c \
        ./gui_state.c \
        ./fast_random.c \
        ./layer_frame.c \
        ./ring.c \
        ./boot.c \
        ./draw_helper.c \

