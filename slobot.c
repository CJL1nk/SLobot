#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "external/pico-ssd1306/ssd1306.h"

#include "animations.h"
#include "types.h"

ssd1306_t disp;

#define SLEEPTIME 25

void update_state(State* state);
int setup(void);
void play_animation(const animation* ani, int offset);
void write_word(const char* word, uint32_t time);

uint64_t total_cycles = 0;

int main() {

    setup();
    State prev_state = NORMAL;
    State state = NORMAL;

    while (true) {

        switch (state) {

            case NORMAL:
                play_animation(&normal, 0);
                break;
            case WORRIED:
                if (prev_state == WORRIED) { play_animation(&worried, 3); }
                else { play_animation(&worried, 0); }

                write_word("!HELP! *v*", 1000);
                play_animation(&worried, 3);
                break;

            default:
                printf("Didi hitli\n");
        }

        prev_state = state;
        update_state(&state);
        total_cycles++;
    }

    return 0;
}

void update_state(State* state) {
    if (total_cycles > 10) {
        *state = WORRIED;
    }
}

int setup() {

    sleep_ms(50); // Wait for hardware, probably safer to wait longer

    // I/0
    stdio_init_all();

    // GPIO
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);

    // Display
    disp.external_vcc=false;
    ssd1306_init(&disp, FRAME_WIDTH, FRAME_HEIGHT, 0x3C, i2c1);
    ssd1306_clear(&disp);

    write_word("Hello :D", 1000);

    return 0;
}

void play_animation(const animation* ani, const int offset) {
    //printf("Animation!!\n");
    for (int i = offset; i < ani->num_frames; i++) {
        ssd1306_clear(&disp);
        ssd1306_bmp_show_image(&disp, ani->frames[i]->frame, IMAGE_SIZE);
        ssd1306_show(&disp);
        sleep_ms(ani->frame_time);
    }
}

void write_word(const char* word, uint32_t time) {
    ssd1306_clear(&disp);
    ssd1306_draw_string(&disp, 8, 24, 2, word);
    ssd1306_show(&disp);
    sleep_ms(time);
}