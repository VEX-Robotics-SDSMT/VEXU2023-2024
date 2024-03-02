#include "../include/globals.h"
#include "pros/adi.hpp"

pros::Controller MasterController (pros::E_CONTROLLER_MASTER);

pros::Imu intertialSensor(INERTIAL_SENSOR);
pros::ADIEncoder driveEncoderR(ENCODERR_TOP, ENCODERR_BOT, true);
pros::ADIEncoder driveEncoderL(ENCODERL_TOP, ENCODERL_BOT, true);

pros::GPS gps(VEX_GPS);

pros::Motor left1(FRONTLEFT, pros::E_MOTOR_GEARSET_18, true);
pros::Motor left2(MIDLEFT, pros::E_MOTOR_GEARSET_18, false); //
pros::Motor left3(BACKLEFT, pros::E_MOTOR_GEARSET_18, true);
pros::Motor right1(FRONTRIGHT, pros::E_MOTOR_GEARSET_18, false);
pros::Motor right2(MIDRIGHT, pros::E_MOTOR_GEARSET_18, true);
pros::Motor right3(BACKRIGHT, pros::E_MOTOR_GEARSET_18, false);
pros::Motor intake(INTAKE, pros::E_MOTOR_GEARSET_36, true);
pros::Motor ratchetF(RATCHET_FRONT, pros::E_MOTOR_GEARSET_36, false);
pros::Motor ratchetB(RATCHET_BACK, pros::E_MOTOR_GEARSET_36, false);



std::vector<pros::Motor> leftDriveVector = {left1, left2, left3};
std::vector<pros::Motor> rightDriveVector = {right1, right2, right3};
Mines::MinesMotorGroup leftDriveMotors(leftDriveVector);
Mines::MinesMotorGroup rightDriveMotors(rightDriveVector);

pros::ADIDigitalOut wall(WALLS);
pros::ADIDigitalOut ratchet(RATCHET);


double axisPercentBlue = 600.0 / 127;
double axisPercentGreen = 200.0 / 127;
double axisPercentRed = 100.0 / 127;
int blueGearbox = 600;
int greenGearbox = 200;
int redGearbox = 100;

bool skills = false;