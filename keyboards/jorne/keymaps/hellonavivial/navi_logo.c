// Copyright 2021 Nicolas Druoton (druotoni)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "gui_state.h"
#include "navi_logo.h"
#include "fast_random.h"
#include "draw_helper.h"

//#define LOGO_SIZE 128
#define LOGO_SIZE 0

// glitch stuff
#define GLITCH_FRAME_NUMBER 11

uint8_t  current_glitch_index = 0;
int      current_glitch_time  = 150;
uint32_t glitch_timer         = 0;

static void render_logo_clean(void) {
    // your logo here
    static const char PROGMEM raw_logo[] = {
        0,0,0,0,0,0,128,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,96,64,64,64,128,128,0,0,0,0,0,0,0,240,12,3,192,48,48,240,240,240,240,224,0,0,0,0,0,224,48,48,240,240,240,224,192,3,12,240,0,0,0,0,0,1,230,152,1,97,241,33,197,69,129,129,128,140,143,140,128,128,129,133,197,193,241,225,65,24,230,1,0,0,0,0,0,0,0,3,4,8,8,25,19,18,36,39,36,36,39,36,36,39,36,21,18,25,9,8,4,3,0,0,0,0
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

void render_glitch_bar(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t iProb) {
    // random horizontal scanlines
    for (uint8_t i = 0; i < height; i++) {
        bool bGenerateGlitch = (fastrand() % 100) < iProb;

        if (bGenerateGlitch) {
            drawline_hr(x, y + i, width, true);
        }
    }
}

void render_misc_glitch(uint8_t algo) {
    char c = 0;
    switch (algo) {
        case 7:
            // invert
            for (uint8_t i = 0; i < LOGO_SIZE; i++) {
                c = get_oled_char(i);
                oled_write_raw_byte(~(c), i);
            }
            break;

        case 8:
            //  wobble
            for (uint8_t i = 0; i < LOGO_SIZE; i++) {
                if (i < LOGO_SIZE - 1) {
                    copy_pixel(i + 1, -1, 85);

                    copy_pixel(LOGO_SIZE - 1 - 1 - i, 1, 170);
                }
            }
            break;
    }
}

static void render_logo_glitch(void) {
#ifdef WITH_GLITCH
    // get a random glitch index
    uint8_t glitch_prob = get_glitch_probability();
    get_glitch_index(&glitch_timer, &current_glitch_time, &current_glitch_index, 0, 150, glitch_prob, GLITCH_FRAME_NUMBER);

    // no glitch
    if (current_glitch_index <= 3) {
        render_logo_clean();
        return;
    }

    // glitch time !
    switch (current_glitch_index) {
        case 4:
            move_block(1, 11, 24, 3, 5);
            move_block(2, 19, 14, 3, 4);
            move_block(9, 22, 7, 4, 4);
            return;

        case 5:
            move_block(6, 25, 20, 7, 4);
            move_block(0, 8, 32, 8, 7);
            return;
        case 6:
            move_block(3, 7, 27, 4, -3);
            move_block(13, 23, 19, 4, -4);
            return;

        case 7:
        case 8:
            render_misc_glitch(current_glitch_index);
            return;

        case 9:
            render_glitch_bar(0, 0, 32, 32, 25);
            return;

        case 10:
            draw_static(0, 0, 32, 32, true, 0);
            return;
    }
#endif
}

void render_logo(gui_state_t t) {
    if (t == _IDLE) {
        // on idle : glitch time !
        render_logo_glitch();
        return;
    }

    // standart logo
    render_logo_clean();
}
