#include "robot_functions.h"
#pragma config(Sensor, in1,    box,            sensorReflection)
#pragma config(Sensor, dgtl1,  Button,         sensorTouch)
#pragma config(Sensor, dgtl4,  wall,           sensorSONAR_inch)
#pragma config(Sensor, dgtl6,  red,            sensorLEDtoVCC)
#pragma config(Motor,  port10, LeftDrive,      tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port1,  RightDrive,     tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,  ArmDrive,       tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl2,  RightWall,      sensorTouch)
#pragma config(Sensor, dgtl3,  LeftWall,       sensorTouch)

void stopMotors() {
    motor[RightDrive] = 0;
    motor[LeftDrive] = 0;
}

void moveForward(int speed, int duration) {
    motor[RightDrive] = speed;
    motor[LeftDrive] = speed;
    wait1Msec(duration);
    stopMotors();
}

void moveBackward(int speed, int duration) {
    motor[RightDrive] = -speed;
    motor[LeftDrive] = -speed;
    wait1Msec(duration);
    stopMotors();
}

void turnRight(int speed, int duration) {
    motor[RightDrive] = -speed;
    motor[LeftDrive] = speed;
    wait1Msec(duration);
    stopMotors();
}

void turnLeft(int speed, int duration) {
    motor[RightDrive] = speed;
    motor[LeftDrive] = -speed;
    wait1Msec(duration);
    stopMotors();
}

void handleBumpers() {
    if (SensorValue(RightWall) == 1) {
        stopMotors();
        wait1Msec(500);
        turnRight(50, 1000);
        moveForward(50, 500);
    } else if (SensorValue(LeftWall) == 1) {
        stopMotors();
        wait1Msec(500);
        turnLeft(50, 1000);
        moveForward(50, 500);
    }
}

void handleFrontWall() {
    if (SensorValue(wall) < 5) {
        stopMotors();
        wait1Msec(500);
        moveBackward(50, 1000);
        turnRight(50, 500);
    }
}

int findBox(int hold, int speedL, int speedR) {
    clearTimer(T1);
    clearTimer(T2);

    int BigDif = 0;
    int dif = 0;
    int current;
    int last = SensorValue(box);

    while (BigDif < hold) {
        handleBumpers();
        handleFrontWall();

        motor[RightDrive] = speedR;
        motor[LeftDrive] = -speedL;

        if (time1[T1] >= 60) {
            current = SensorValue(box);
            dif = current - last;
            if (dif > BigDif) {
                BigDif = dif;
            }
            last = current;
            clearTimer(T1);
        }

        if (time1[T2] >= 2000) {
            return 0;
        }
    }

    stopMotors();
    wait1Msec(1000);

    return 1;
}

void lowerArm() {
    wait1Msec(1000);
    motor[ArmDrive] = 20;
    wait1Msec(1500);
    motor[ArmDrive] = -20;
    wait1Msec(2500);
    motor[ArmDrive] = 0;
    wait1Msec(2000);
}

void indicateSuccess() {
    SensorValue(red) = 1;
    wait1Msec(1000);
    SensorValue(red) = 0;
}
