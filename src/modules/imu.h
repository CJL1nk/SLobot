//
// Created by CJ on 9/16/26.
//

#ifndef SLOBOT_IMU_H
#define SLOBOT_IMU_H

#define MPU_ADDR       0x68

#define PWR_MGMT_1     0x6B

#define ACCEL_XOUT_H   0x3B
#define ACCEL_XOUT_L   0x3C
#define ACCEL_YOUT_H   0x3D
#define ACCEL_YOUT_L   0x3E
#define ACCEL_ZOUT_H   0x3F
#define ACCEL_ZOUT_L   0x40

void init_imu();

float get_roll();
float get_gs();

#endif //SLOBOT_IMU_H