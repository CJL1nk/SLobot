//
// Created by CJ on 6/25/26.
//

#ifndef SLOBOT_ANIMATIONS_H
#define SLOBOT_ANIMATIONS_H

#include "frames.h"

#include <stdint.h>

typedef struct {
    frame** frames;
    uint32_t num_frames;
    uint32_t frame_time; // in ms
} animation;

extern frame* normal_frames[];
extern const animation normal;

extern frame* worried_frames[];
extern const animation worried;


#endif //SLOBOT_ANIMATIONS_H