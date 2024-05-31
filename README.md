# RobotC Box Finding and Handling Robot
Vex Robot Uvic Group 4

This project is a RobotC-based program for a robot that navigates an environment to find and interact with a box using various sensors and motors. The robot uses touch sensors, an ultrasonic sensor, and an infrared sensor to detect walls and the box, and includes a mechanical arm to drop a ball onto the box once it is found, and moved to it.

## Project Structure

The project is organized into the following files:

- `main.c`: Contains the main task and high-level logic.
- `robot_functions.h`: Header file that declares all the functions used in the project.
- `robot_functions.c`: Contains the implementation of all the functions declared in `robot_functions.h`.

## Hardware Configuration

The robot hardware includes:

- Sensors:
  - `box`: Infrared sensor for detecting the box.
  - `Button`: Touch sensor to start the robot.
  - `wall`: Ultrasonic sensor for detecting walls.
  - `red`: LED indicator.
  - `RightWall`: Right touch sensor for detecting walls.
  - `LeftWall`: Left touch sensor for detecting walls.
  
- Motors:
  - `LeftDrive`: Left drive motor.
  - `RightDrive`: Right drive motor.
  - `ArmDrive`: Arm motor for interacting with the box.

## Functionality

The robot performs the following tasks:

1. **Initialization**: Waits for the start button to be pressed.
2. **Box Finding**: Navigates the environment to locate the box using infrared sensors.
3. **Wall Avoidance**: Uses touch and ultrasonic sensors to avoid obstacles.
5. **Box Handling**: Uses a mechanical arm to interact with the box once it is found and moved to.
6. **Indicator**: Turns on an LED to indicate successful box interaction.

