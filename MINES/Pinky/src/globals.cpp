#include "../include/globals.h"
#include "pros/adi.hpp"

pros::Controller MasterController (pros::E_CONTROLLER_MASTER);

pros::Imu intertialSensor(INERTIAL_SENSOR);
pros::ADIEncoder driveEncoder(ENCODER_TOP, ENCODER_BOT, false);
pros::GPS gps(VEX_GPS);

pros::Motor left1(FRONTLEFT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor left2(MIDLEFT, pros::E_MOTOR_GEARSET_06, true); //
pros::Motor left3(BACKLEFT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right1(FRONTRIGHT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right2(MIDRIGHT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor right3(BACKRIGHT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor intake(INTAKE, pros::E_MOTOR_GEARSET_18, true);


std::vector<pros::Motor> leftDriveVector = {left1, left2, left3};
std::vector<pros::Motor> rightDriveVector = {right1, right2, right3};
Mines::MinesMotorGroup leftDriveMotors(leftDriveVector);
Mines::MinesMotorGroup rightDriveMotors(rightDriveVector);

pros::ADIDigitalOut wall(WALLS);


double axisPercentBlue = 600.0 / 127;
double axisPercentGreen = 200.0 / 127;
double axisPercentRed = 100.0 / 127;
int blueGearbox = 600;
int greenGearbox = 200;
int redGearbox = 100;

bool skills = false;