//
// Created by CJ on 9/13/26.
//

#ifndef SLOBOT_FRAMES_H
#define SLOBOT_FRAMES_H

#define FRAME_WIDTH 128
#define FRAME_HEIGHT 64
#define HEADER_SIZE 146
#define IMAGE_SIZE (((FRAME_WIDTH * FRAME_HEIGHT) / 8) + HEADER_SIZE)

#include <stdint.h>


typedef struct {
    uint8_t frame[IMAGE_SIZE];
} frame;

extern frame eye_1;
extern frame worried_1;
extern frame worried_2;
extern frame worried_3;
extern frame worried_4;

#endif //SLOBOT_FRAMES_H