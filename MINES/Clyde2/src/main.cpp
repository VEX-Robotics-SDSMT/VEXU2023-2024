#include "main.h"
#include "DiffDrive.h"
#include "botFunctions.h"
#include "globals.h"
#include "pros/rtos.h"

//globals

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

using namespace Mines;

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() 
{
	intertialSensor.reset();
	//pros::vision_signature_s_t RED_GOAL_SIG = vision.signature_from_utility(1, 4391, 7505, 5948, -1303, -147, -725, 1.6, 0);
	//vision.set_signature(RED_GOAL_SIG_ID, &RED_GOAL_SIG);
	//pros::vision_signature_s_t BLUE_GOAL_SIG = vision.signature_from_utility(2, -3073, -1323, -2198, 4405, 9923, 7164, 1.5, 0);
	//vision.set_signature(BLUE_GOAL_SIG_ID, &BLUE_GOAL_SIG);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() 
{
	//Skills?
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() 
{
	// while(true)
	// 	pros::screen::print(pros::text_format_e_t::E_TEXT_SMALL, 1, std::to_string(driveEncoder.get_value()).c_str());
	EncoderWheelSensorInterface encoderInterface(driveEncoder);
	DiffDrive drive(leftDriveMotors, rightDriveMotors, &encoderInterface, intertialSensor);
	drive.setDrivePIDVals(0.75, 0, 0);//0.2
	drive.setDrivePIDTol(50);
	drive.setTurnPIDVals(2, 0, 0);//1.2
	drive.setTurnPIDTol(1);
	drive.setMaxDriveSpeed(1); 
	drive.setMaxTurnSpeed(1);

	drive.setMaxDriveAccel(0.12);




	drive.setMaxDriveAccel(0.12);
	if(!skills)
	{

	drive.driveTiles(1750);
	drive.turnDegreesAbsolute(90);
	//drive.setMaxDriveAccel(1);
	drive.setActive(false); //PID turn off
	leftDriveMotors.moveVelocity(12700);
	rightDriveMotors.moveVelocity(12700);
	pros::delay(650); //how long bot moves no PID && prev { 620, 600, 700}
	leftDriveMotors.brake();
	rightDriveMotors.brake();
	drive.setActive(true); //PID turn on
	//drive.driveTiles(1400, 2000);
	//drive.setMaxDriveAccel(0.12);
	drive.driveTiles(-70); //previous { -80, -100 }
	drive.turnDegreesAbsolute(45);
	drive.driveTiles(-2200);
	for(int i = 0; i < 12; i++)
	{
		catPrime(cataMotors, limitSwitch, -100);
		pros::delay(500);
		catLaunch(cataMotors, limitSwitch, -127);
	}

	drive.driveTiles(900);
	drive.turnDegreesAbsolute(90);
	drive.driveTiles(750);
	drive.turnDegreesAbsolute(100);

	drive.killPIDs();
	}
	else
	{
		// *******************PHASE 1*******************
		// for(int i = 0; i < 23; i++)
		// {
		// 	catPrime(cataMotors, limitSwitch, -100);
		// 	pros::delay(750);
		// 	catLaunch(cataMotors, limitSwitch, -127);
		// }
		drive.driveTiles(500);
		drive.turnDegreesAbsolute(250);
		drive.driveTiles(750, 750);
		drive.driveTiles(-150);
		drive.turnDegreesAbsolute(337);
		pros::delay(3000);
		drive.driveTiles(3100);
		pros::delay(3000);
		drive.turnDegreesAbsolute(68);
		pros::delay(3000);


		// *******************PHASE 2*******************
		wingL.set_value(1);
		drive.driveTiles(900);
		pros::delay(3000);
		wingL.set_value(0);
		drive.driveTiles(-125);
		pros::delay(3000);
		drive.turnDegreesAbsolute(125);
		pros::delay(3000);
		drive.driveTiles(500);
		pros::delay(3000);
		wingL.set_value(1);
		wingR.set_value(1);
		pros::delay(30000);

		// SWING TURN
		drive.setActive(false);
		leftDriveMotors.moveVelocity(28);
		rightDriveMotors.moveVelocity(310);
		pros::delay(750);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		drive.setActive(true);

		pros::delay(500);
	 	drive.driveTiles(400);

		
	 	drive.killPIDs();
	 }
	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol()
{	
	while(true)
	{	
		// ********************DRIVE********************
		// 2 stick arcade
		//double leftAxisY = MasterController.get_analog(axisLeftY);
		//double rightAxisX = MasterController.get_analog(axisRightX);
		//double leftVelocity = ((leftAxisY + rightAxisX));
		//double rightVelocity = ((leftAxisY - rightAxisX));

		// 1 stick arcade
		double leftAxisY = MasterController.get_analog(axisLeftY);
		double leftAxisX = MasterController.get_analog(axisLeftX);
		double rightAxisX = MasterController.get_analog(axisRightX);
		double aimVelocityLeft = (rightAxisX) * 0.06;
		double aimVelocityRight = -rightAxisX * 0.06;
		double leftVelocity = ((leftAxisY + leftAxisX + aimVelocityLeft));
		double rightVelocity = ((leftAxisY - leftAxisX + aimVelocityRight));

		// Tank
		// double leftAxisY = MasterController.get_analog(axisLeftY);
	    // double rightAxisY = MasterController.get_analog(axisRightY);
		// double leftVelocity = ((leftAxisY) * axisPercentBlue);
		// double rightVelocity = ((-rightAxisY) * axisPercentBlue);

		// If the driver is holding B, drive at 30% speed to aim easier, otherwise drive using the values found anbove
		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_B))
		{
			driveLoop(leftDriveMotors, rightDriveMotors, .3*leftVelocity, .3*rightVelocity);
		}
		else
		{
			driveLoop(leftDriveMotors, rightDriveMotors, leftVelocity, rightVelocity);
		}
		//*********************************************

		//*******************CATAPULT******************
		//Sam will install limit switch to bring down a bit, stop to load, and then fire
		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			if(limitSwitch.get_value() == true)
				catLaunch(cataMotors, limitSwitch, -127);
			else
				catPrime(cataMotors, limitSwitch, -80);
		}
		else if (MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			cataMotors.moveVelocity(127);
		}
		else
		{
			cataMotors.brake();
		}

		//*******************WINGS**********************
		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			wingL.set_value(1);
			wingR.set_value(1);
		}		
		else if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))
			wingL.set_value(1);
		else if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
			wingR.set_value(1);	
		else
		{
			wingL.set_value(0);
			wingR.set_value(0);
		}
		
		
	}
}
