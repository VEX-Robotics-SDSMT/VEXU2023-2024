#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "api.h"
#include "MinesMotorGroup.h"

#define INERTIAL_SENSOR 7
#define VEX_GPS 13
#define VISION_SENSOR 3
#define ENCODER_TOP 11
#define ENCODER_BOTTOM 12

#define L_FRONT 20
#define L_FRONTM 19
#define L_REARM 18
#define L_REAR 17
#define R_FRONT 11
#define R_FRONTM 13
#define R_REARM 14
#define R_REAR 16

#define CATA_R 9
#define CATA_L 10
#define WING 1

#define INTAKE_MOTOR_GEARSET redGearbox
#define FLYWHEELS_MOTOR_GEARSET blueGearbox
#define ROLLER_MOTOR_GEARSET greenGearbox

extern pros::Controller MasterController;

extern pros::Imu intertialSensor;
extern pros::Vision vision;
extern pros::ADIEncoder driveEncoder;
extern pros::GPS gps;

extern pros::Motor leftFront;
extern pros::Motor leftRear;
extern pros::Motor rightFront;
extern pros::Motor rightRear;

extern pros::ADIDigitalOut wings;

extern std::vector<pros::Motor> leftDriveVector;
extern std::vector<pros::Motor> rightDriveVector;
extern Mines::MinesMotorGroup leftDriveMotors;
extern Mines::MinesMotorGroup rightDriveMotors;
extern Mines::MinesMotorGroup cataMotors;


enum Color { red, blue, purple };
extern pros::Motor string;

extern double axisPercentBlue;
extern double axisPercentGreen;
extern double axisPercentRed;
extern int blueGearbox;
extern int greenGearbox;
extern int redGearbox;

extern bool skills;

extern uint8_t RED_GOAL_SIG_ID;
extern uint8_t BLUE_GOAL_SIG_ID;

extern int requiredColorLoops;
extern const double ROLLER_TIMEOUT;

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