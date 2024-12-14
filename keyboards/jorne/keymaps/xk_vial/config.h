// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define VIAL_KEYBOARD_UID {0x80, 0x41, 0x59, 0xF5, 0x4B, 0xF3, 0x50, 0x97}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

// choose IS_LEFT or IS_RIGHT for compilation and flash firmware
#define IS_LEFT 1
// #define IS_RIGHT 1

#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define USB_SUSPEND_WAKEUP_DELAY 200
#define NO_USB_STARTUP_CHECK

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64
