//
// Created by CJ on 9/16/26.
//

#include "display.h"
#include "hardware/i2c.h"

ssd1306_t disp;

void init_display() {
    i2c_init(i2c1, 400000);

    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);

    disp.external_vcc=false;
    ssd1306_init(&disp, FRAME_WIDTH, FRAME_HEIGHT, 0x3C, i2c1);
    ssd1306_clear(&disp);
}

void play_animation(const animation* ani, const int offset) {
    for (int i = offset; i < ani->num_frames; i++) {
        ssd1306_clear(&disp);
        ssd1306_bmp_show_image(&disp, ani->frames[i]->frame, IMAGE_SIZE);
        ssd1306_show(&disp);
        sleep_ms(ani->frame_time);
    }
}

void write_word(const char* word, const uint32_t time) {
    ssd1306_clear(&disp);
    ssd1306_draw_string(&disp, 8, 24, 2, word);
    ssd1306_show(&disp);
    sleep_ms(time);
}