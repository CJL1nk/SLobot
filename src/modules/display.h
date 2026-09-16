//
// Created by CJ on 9/16/26.
//

#ifndef SLOBOT_DISPLAY_H
#define SLOBOT_DISPLAY_H

#include "../../external/pico-ssd1306/ssd1306.h"
#include "../animations.h"

extern ssd1306_t disp;

void init_display();
void play_animation(const animation* ani, int offset);
void write_word(const char* word, uint32_t time);

#endif //SLOBOT_DISPLAY_H