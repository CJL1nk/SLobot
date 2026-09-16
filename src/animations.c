//
// Created by CJ on 9/16/26.
//

#include "animations.h"

frame* normal_frames[] = {
    &eye_1
};
const animation normal = {normal_frames, 1, 100};

frame* worried_frames[] = {
    &worried_1, &worried_2, &worried_2,
    &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4, &worried_3, &worried_4,
};

const animation worried = {worried_frames, 17, 100};