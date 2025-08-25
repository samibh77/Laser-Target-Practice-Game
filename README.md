🎯 Target Laser Game

A fun and interactive Arduino-based laser target game designed to test accuracy, speed, and reflexes.
This project was developed during my experience as a Robotics Instructor, with the goal of combining electronics, programming, and gaming into a hands-on learning activity.

📌 Project Overview

The game consists of 3 moving targets (disks) mounted on servo motors.
Each disk is equipped with a photoresistor sensor to detect laser hits.
The game logic:

Disks move randomly up and down.

A laser pointer is used by the player to aim at the targets.

When the laser hits a target, the photoresistor detects the light → score increases.

A 16x2 LCD display shows the current score.

LED indicators signal the active targets.

This project blends embedded systems, sensors, and real-time control with a fun gamified experience.

🛠️ Hardware Requirements

Arduino Uno (or compatible board)

3x Servo motors

3x Photoresistor (LDR) sensors

3x LEDs + resistors

16x2 LCD screen (I2C recommended)

Laser pointer

Breadboard + jumper wires

Power supply

💻 Software & Libraries

Arduino IDE

Libraries:

Servo.h (for servo control)

LiquidCrystal_I2C.h (for LCD display)
