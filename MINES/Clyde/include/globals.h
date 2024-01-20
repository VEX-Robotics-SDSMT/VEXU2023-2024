#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "api.h"
#include "MinesMotorGroup.h"

#define INERTIAL_SENSOR 20
#define VISION_SENSOR 3
#define VEX_GPS 13

#define L1 20
#define L2 19
#define L3 18
#define L4 17
#define R1 11
#define R2 13
#define R3 14
#define R4 16
#define LCat 10
#define RCat 9
#define WING 1
#define LIMIT_SWITCH 2 //port for limitSwitch once added

#define CATAPULT_MOTOR_GEARSET redGearbox
#define DRIVE_MOTOR_GEARSET blueGearbox

extern pros::Controller MasterController;

extern pros::Imu intertialSensor;
extern pros::GPS gps;

extern pros::Motor left1;
extern pros::Motor left2;
extern pros::Motor left3;
extern pros::Motor left4;
extern pros::Motor right1;
extern pros::Motor right2;
extern pros::Motor right3;
extern pros::Motor right4;

extern pros::ADIDigitalOut wings;
extern pros::ADIDigitalOut limitSwitch;

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