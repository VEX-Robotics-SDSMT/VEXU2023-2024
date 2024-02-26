#include "../include/botFunctions.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

void driveLoop(Mines::MinesMotorGroup leftMotorGroup, Mines::MinesMotorGroup rightMotorGroup, double leftVelocity, double rightVelocity)
{
    leftMotorGroup.move(leftVelocity);
    rightMotorGroup.move(rightVelocity);
}

void catLaunch(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, double velocity)
{    
    cataMotors.move(velocity);
    pros::delay(150);
    cataMotors.brake();
}

void catLoop(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, bool cataTarget)
{
    cataMotors.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    if(limitSwitch.get_value() != cataTarget)
        cataMotors.moveVelocity(-127);
    else
        cataMotors.brake();
}


void catPrime(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, double velocity)
{
    cataMotors.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    while(limitSwitch.get_value() == false)
    {
        cataMotors.move(velocity);
        pros::delay(10);
    }
    cataMotors.brake();


}


