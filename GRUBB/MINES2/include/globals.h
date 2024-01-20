#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "api.h"
#include "MinesMotorGroup.h"

#define INERTIAL_SENSOR 20
#define VISION_SENSOR 3
#define VEX_GPS 13

#define RightF 12 //motor ports
#define RightR 11
#define LeftF 19
#define LeftR 20
#define LCat 17 //catapult motors
#define RCat 16
#define WING 1

//06 corresponds to blue
//18 corresponds to green
//36 corresponds to red
#define CATAPULT_MOTOR_GEARSET redGearbox
#define DRIVE_MOTOR_GEARSET greenGearbox

extern pros::Controller MasterController;

extern pros::Imu intertialSensor;
extern pros::GPS gps;

extern pros::Motor RightFront;
extern pros::Motor RightRear;
extern pros::Motor LeftFront;
extern pros::Motor LeftRear;
extern pros::Motor catR;
extern pros::Motor catL;

extern pros::ADIDigitalOut wings;

extern std::vector<pros::Motor> leftDriveVector;
extern std::vector<pros::Motor> rightDriveVector;
extern std::vector<pros::Motor> catapultVector;
extern Mines::MinesMotorGroup leftDriveMotors;
extern Mines::MinesMotorGroup rightDriveMotors;
extern Mines::MinesMotorGroup cataMotors;

extern double axisPercentBlue;
extern double axisPercentGreen;
extern double axisPercentRed;
extern int blueGearbox;
extern int greenGearbox;
extern int redGearbox;

extern bool skills;

#define buttonUp pros::E_CONTROLLER_DIGITAL_UP
#define buttonDown pros::E_CONTROLLER_DIGITAL_DOWN
#define buttonLeft pros::E_CONTROLLER_DIGITAL_LEFT
#define buttonRight pros::E_CONTROLLER_DIGITAL_RIGHT
#define buttonX pros::E_CONTROLLER_DIGITAL_X
#define buttonY pros::E_CONTROLLER_DIGITAL_Y
#define buttonA pros::E_CONTROLLER_DIGITAL_A
#define buttonB pros::E_CONTROLLER_DIGITAL_B
#define buttonL1 pros::E_CONTROLLER_DIGITAL_L1
#define buttonL2 pros::E_CONTROLLER_DIGITAL_L2
#define buttonR1 pros::E_CONTROLLER_DIGITAL_R1
#define buttonR2 pros::E_CONTROLLER_DIGITAL_R2
#define axisLeftY pros::E_CONTROLLER_ANALOG_LEFT_Y
#define axisLeftX pros::E_CONTROLLER_ANALOG_LEFT_X
#define axisRightY pros::E_CONTROLLER_ANALOG_RIGHT_Y
#define axisRightX pros::E_CONTROLLER_ANALOG_RIGHT_X

#endif