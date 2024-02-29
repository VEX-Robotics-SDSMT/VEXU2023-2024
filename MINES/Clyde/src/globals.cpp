#include "../include/globals.h"
#include "pros/adi.hpp"

pros::Controller MasterController (pros::E_CONTROLLER_MASTER);

pros::Imu intertialSensor(INERTIAL_SENSOR);
pros::ADIEncoder driveEncoder(ENCODER_TOP, ENCODER_BOT, false);
pros::Vision vision(VISION_SENSOR);
pros::GPS gps(VEX_GPS);

pros::Motor left1(L1, pros::E_MOTOR_GEARSET_06, true);
pros::Motor left2(L2, pros::E_MOTOR_GEARSET_06, true);
pros::Motor left4(L4, pros::E_MOTOR_GEARSET_06, true);
pros::Motor right1(R1, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right2(R2, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right4(R4, pros::E_MOTOR_GEARSET_06, false);
pros::Motor cataRight(RCat, pros::E_MOTOR_GEARSET_18, true);
pros::Motor cataLeft(LCat, pros::E_MOTOR_GEARSET_18, false);


std::vector<pros::Motor> leftDriveVector = {left1, left2, left4};
std::vector<pros::Motor> rightDriveVector = {right1, right2, right4};
std::vector<pros::Motor> catapultVector = {cataRight, cataLeft};
Mines::MinesMotorGroup leftDriveMotors(leftDriveVector);
Mines::MinesMotorGroup rightDriveMotors(rightDriveVector);
Mines::MinesMotorGroup cataMotors(catapultVector);

pros::ADIDigitalOut wingL(WINGL);
pros::ADIDigitalOut tracking(TRACKINGWHEEL);
pros::ADIDigitalOut wingR(WINGR);
pros::ADIDigitalOut hang(HANG);
pros::ADIDigitalIn limitSwitch(LIMIT_SWITCH);


double axisPercentBlue = 600.0 / 127;
double axisPercentGreen = 200.0 / 127;
double axisPercentRed = 100.0 / 127;
int blueGearbox = 600;
int greenGearbox = 200;
int redGearbox = 100;

bool skills = false;