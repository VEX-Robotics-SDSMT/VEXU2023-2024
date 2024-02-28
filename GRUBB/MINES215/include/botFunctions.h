#ifndef BOTFUNCTIONS_H
#define BOTFUNCTIONS_H

#include "globals.h"
#include "MinesMotorGroup.h"
#include "pros/motors.h"

void driveLoop(Mines::MinesMotorGroup leftMotorGroup, Mines::MinesMotorGroup rightMotorGroup, double leftVelocity, double rightVelocity);
void catLaunch(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, double velocity);
void catPrime(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, double velocity);
void catLoop(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, bool cataTarget);

#endif