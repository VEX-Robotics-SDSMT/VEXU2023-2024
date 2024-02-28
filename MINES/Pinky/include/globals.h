#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "api.h"
#include "MinesMotorGroup.h"

#define INERTIAL_SENSOR 9 //not in yet
#define VEX_GPS 13
#define ENCODERR_TOP 8
#define ENCODERR_BOT 7
#define ENCODERL_TOP 6
#define ENCODERL_BOT 5

#define BACKRIGHT 21
#define MIDRIGHT 10
#define FRONTRIGHT 3
#define BACKLEFT 1
#define MIDLEFT 5
#define FRONTLEFT 7
#define INTAKE 11
#define WALLS 1

#define CATAPULT_MOTOR_GEARSET redGearbox
#define DRIVE_MOTOR_GEARSET blueGearbox

extern pros::Controller MasterController;

extern pros::Imu intertialSensor;
extern pros::GPS gps;
extern pros::ADIEncoder driveEncoderL;
extern pros::ADIEncoder driveEncoderR;


extern pros::Motor left1;
extern pros::Motor left2;
extern pros::Motor left3;
extern pros::Motor right1;
extern pros::Motor right2;
extern pros::Motor right3;
extern pros::Motor intake;

extern pros::ADIDigitalOut wall;
extern pros::ADIDigitalIn limitSwitch;

extern std::vector<pros::Motor> leftDriveVector;
extern std::vector<pros::Motor> rightDriveVector;
extern Mines::MinesMotorGroup leftDriveMotors;
extern Mines::MinesMotorGroup rightDriveMotors;

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