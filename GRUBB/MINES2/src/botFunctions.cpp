#include "../include/botFunctions.h"

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

void catLoop(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, bool cataTarget, bool &switchToggeled)
{
    cataMotors.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

    if(limitSwitch.get_value() != cataTarget) //when primed on second press reaches slipgear.
    {
        cataMotors.moveVelocity(-50);
        switchToggeled = true;
    }
    else
    {
        if( switchToggeled == true )
            pros::delay(4);
        cataMotors.brake();
        switchToggeled = false;
    }
}


void catPrime(Mines::MinesMotorGroup cataMotors, pros::ADIDigitalIn limitSwitch, double velocity)
{
    cataMotors.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    while(limitSwitch.get_value() == false)
    {
        cataMotors.move(velocity);
        pros::delay(5);
    }
    cataMotors.brake();

}

