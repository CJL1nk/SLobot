This is nothing more than a little for fun experimental project I'm doing making a robot that can do various stuff

Currently, parts needed

- Raspberry Pi Pico 2w
- Female-female dupont wires
- 1 female - 3 female dupont wires
- MPU-6050 IMU
- SSD1306 yellow/blue display

```      
MPU 6050:
   | VCC -> Pico 3v3
   | GND -> Pico GND
   | SCL -> Pico GP5
   | SDA -> Pico GP4
   
SSD1306:
   | GND -> Pico GND
   | VCC -> Pico 3v3
   | SCL -> Pico GP3
   | SDA -> Pico GP2
```