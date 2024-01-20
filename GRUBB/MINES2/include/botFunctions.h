#ifndef BOTFUNCTIONS_H
#define BOTFUNCTIONS_H

#include "globals.h"
#include "MinesMotorGroup.h"
#include "pros/motors.h"

void driveLoop(Mines::MinesMotorGroup leftMotorGroup, Mines::MinesMotorGroup rightMotorGroup, double leftVelocity, double rightVelocity);
void intakeLoopHold(Mines::MinesMotorGroup intakeMotors, int pct, bool runButton, bool revButton);
void flywheelLoopToggle(Mines::MinesMotorGroup flywheels, int pct);
void compressLoopToggle(pros::ADIDigitalOut compress);
void toggleFlywheels();
void toggleCompress();
void catLaunch(Mines::MinesMotorGroup cataMotors, double velocity);

#endif