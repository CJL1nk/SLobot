#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "pico/stdlib.h"

#include "modules/display.h"
#include "modules/imu.h"
#include "./types.h"

#define SLEEPTIME 25

void update_state(State* state);
int setup(void);

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
                break;

            default:
                printf("Didi hitli\n");
        }

        prev_state = state;
        update_state(&state);
    }

    return 0;
}

void update_state(State* state) {

    const float roll = get_roll();

    printf("Roll: %f\n", roll);

    if (fabsf(roll) > 140.f) {
        *state = WORRIED;
    } else {
        *state = NORMAL;
    }
}

int setup() {

    sleep_ms(50); // Wait for hardware, probably safer to wait longer

    // I/0
    stdio_init_all();

    // SSD1306
    init_display();

    // MPU-6050
    init_imu();

    write_word("Hello :D", 1000);

    return 0;
}