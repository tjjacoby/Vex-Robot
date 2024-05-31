#include "robot_functions.h"

task main() {
    while (true) {
        if (SensorValue(Button) == 1) {
            int hold = 78;
            int test = findBox(hold, 50, 50);
            while (test == 0) {
                hold -= 10;
                test = findBox(hold, 50, 50);
            }
            wait1Msec(500);
            indicateSuccess();

            if (SensorValue(wall) > 10) {
                moveForward(40, 2500);
            }

            stopMotors();
            wait1Msec(500);
            turnRight(40, 750);

            hold = 85;
            test = findBox(hold, 45, 45);
            while (test == 0) {
                hold -= 10;
                test = findBox(hold, 45, 45);
            }
            wait1Msec(500);
            indicateSuccess();

            clearTimer(T3);

            while (true) {
                if (SensorValue(wall) < 5) {
                    stopMotors();
                    wait1Msec(1000);
                    lowerArm();
                    wait1Msec(500);
                    indicateSuccess();
                    moveBackward(35, 1000);
                    turnRight(60, 2000);
                    moveForward(50, 2000);
                    stopMotors();
                    break;
                } else {
                    moveForward(36, 0);
                }
            }
        }
    }
}
