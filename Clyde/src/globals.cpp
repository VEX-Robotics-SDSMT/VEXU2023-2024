#include "../include/globals.h"
#include "pros/adi.hpp"

pros::Controller MasterController (pros::E_CONTROLLER_MASTER);

pros::Imu intertialSensor(INERTIAL_SENSOR);
pros::Vision vision(VISION_SENSOR);
pros::ADIEncoder driveEncoder(ENCODER_TOP, ENCODER_BOTTOM, false);
pros::GPS gps(VEX_GPS);

pros::Motor leftFront(L_FRONT, pros::E_MOTOR_GEARSET_18, true);
pros::Motor leftRear(L_REAR, pros::E_MOTOR_GEARSET_18, true);
pros::Motor rightFront(R_FRONT, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rightRear(R_REAR, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rightFMid(R_FRONTM, pros::E_MOTOR_GEARSET_18, false);
pros::Motor leftFMid(L_FRONTM, pros::E_MOTOR_GEARSET_18, true);
pros::Motor rightRMid(R_REARM, pros::E_MOTOR_GEARSET_18, false);
pros::Motor leftRMid(L_REARM, pros::E_MOTOR_GEARSET_18, true);

pros::Motor cataRight(CATA_R, pros::E_MOTOR_GEARSET_18, true);
pros::Motor cataLeft(CATA_L, pros::E_MOTOR_GEARSET_18, false);

std::vector<pros::Motor> leftDriveVector = {leftFront, leftRear, leftFMid, leftRMid};
std::vector<pros::Motor> rightDriveVector = {rightFront, rightRear, rightFMid, rightRMid};
std::vector<pros::Motor> catapultVector = {cataRight, cataLeft};
Mines::MinesMotorGroup leftDriveMotors(leftDriveVector);
Mines::MinesMotorGroup rightDriveMotors(rightDriveVector);
Mines::MinesMotorGroup cataMotors(catapultVector);

pros::ADIDigitalOut wings(WING);

double axisPercentBlue = 600.0 / 127;
double axisPercentGreen = 200.0 / 127;
double axisPercentRed = 100.0 / 127;
int blueGearbox = 600;
int greenGearbox = 200;
int redGearbox = 100;

uint8_t RED_GOAL_SIG_ID = 1;
uint8_t BLUE_GOAL_SIG_ID = 2;

int requiredColorLoops = 3;
const double ROLLER_TIMEOUT = 3000;

bool skills = true;