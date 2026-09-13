//
// Created by CJ on 6/25/26.
//

#ifndef SLOBOT_ANIMATIONS_H
#define SLOBOT_ANIMATIONS_H

#define FRAME_WIDTH 128
#define FRAME_HEIGHT 64
#define HEADER_SIZE 146

#define IMAGE_SIZE (((FRAME_WIDTH * FRAME_HEIGHT) / 8) + HEADER_SIZE)

#include "frames.h"

#include <stdint.h>

typedef struct {
    frame** frames;
    uint32_t num_frames;
    uint32_t frame_time; // in ms
} animation;

frame* normal_frames[] = {
    &eye_1
};
const animation normal = {normal_frames, 1, 100};

frame* worried_frames[] = {
    &worried_1, &worried_2, &worried_2,
    &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4,
};

const animation worried = {worried_frames, 17, 100};


#endif //SLOBOT_ANIMATIONS_H