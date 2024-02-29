#include "../include/globals.h"
#include "pros/adi.hpp"

pros::Controller MasterController (pros::E_CONTROLLER_MASTER);

pros::Imu intertialSensor(INERTIAL_SENSOR);
pros::Vision vision(VISION_SENSOR);
pros::GPS gps(VEX_GPS);

pros::Motor RightFront(RightF, pros::E_MOTOR_GEARSET_18, false);
pros::Motor RightRear(RightR, pros::E_MOTOR_GEARSET_18, false);
pros::Motor LeftFront(LeftF, pros::E_MOTOR_GEARSET_18, true);
pros::Motor LeftRear(LeftR, pros::E_MOTOR_GEARSET_18, true);
pros::Motor cataRight(RCat, pros::E_MOTOR_GEARSET_36, false);
pros::Motor cataLeft(LCat, pros::E_MOTOR_GEARSET_36, true);


std::vector<pros::Motor> leftDriveVector = {LeftFront, LeftRear};
std::vector<pros::Motor> rightDriveVector = {RightFront, RightRear};
std::vector<pros::Motor> catapultVector = {cataRight, cataLeft};
Mines::MinesMotorGroup leftDriveMotors(leftDriveVector);
Mines::MinesMotorGroup rightDriveMotors(rightDriveVector);
Mines::MinesMotorGroup cataMotors(catapultVector);

pros::ADIDigitalOut wings(WING);
pros::ADIDigitalIn limitSwitch(LIMIT_SWITCH);


double axisPercentBlue = 600.0 / 127;
double axisPercentGreen = 200.0 / 127;
double axisPercentRed = 100.0 / 127;
int blueGearbox = 600;
int greenGearbox = 200;
int redGearbox = 100;

bool skills = true;