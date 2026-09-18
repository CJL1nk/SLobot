//
// Created by CJ on 9/16/26.
//
// Currently uses the MPU-6050 IMU

#include "imu.h"

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#include <math.h>

void init_imu() {
    i2c_init(i2c0, 400000);

    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);

    const uint8_t data[2] = {PWR_MGMT_1, 0x00};
    i2c_write_blocking(i2c0, MPU_ADDR, data, 2, false);
}

float get_roll() {
    const uint8_t reg = ACCEL_XOUT_H;
    uint8_t data[6];

    i2c_write_blocking(i2c0, MPU_ADDR, &reg, 1, true);
    i2c_read_blocking(i2c0, MPU_ADDR, data, 6, false);

    const int16_t y = ((int16_t)data[2] << 8) | data[3];
    const int16_t z = ((int16_t)data[4] << 8) | data[5];

    return atan2f(y,z) * 180.0f / 3.141592f; // typing out pi here cuz I don't want double conversion
}
float get_gs() {
    const uint8_t reg = ACCEL_XOUT_H;
    uint8_t data[6];

    i2c_write_blocking(i2c0, MPU_ADDR, &reg, 1, true);
    i2c_read_blocking(i2c0, MPU_ADDR, data, 6, false);

    const int16_t x = ((int16_t)data[0] << 8) | data[1];
    const int16_t y = ((int16_t)data[2] << 8) | data[3];
    const int16_t z = ((int16_t)data[4] << 8) | data[5];

    const float accel_sensitivity = 16384.0f;

    const float x_g = (float)x / accel_sensitivity;
    const float y_g = (float)y / accel_sensitivity;
    const float z_g = (float)z / accel_sensitivity;

    // Calculate total magnitude of acceleration
    return sqrtf((x_g * x_g) + (y_g * y_g) + (z_g * z_g));
}