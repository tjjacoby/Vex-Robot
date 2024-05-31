#ifndef ROBOT_FUNCTIONS_H
#define ROBOT_FUNCTIONS_H

void stopMotors();
void moveForward(int speed, int duration);
void moveBackward(int speed, int duration);
void turnRight(int speed, int duration);
void turnLeft(int speed, int duration);
void handleBumpers();
void handleFrontWall();
int findBox(int hold, int speedL, int speedR);
void lowerArm();
void indicateSuccess();

#endif
