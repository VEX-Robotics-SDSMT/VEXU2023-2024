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
	//********************MINES2 15in SKILLS********************************
	if(skills) {
		
	}
	//************MINES2 15in AUTO******************************************
	else {
		rightDriveMotors.move(80);
		leftDriveMotors.move(80);
		pros::delay(375);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(500);
		rightDriveMotors.move(-80);
		leftDriveMotors.move(-80);
		pros::delay(357);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1500);
		rightDriveMotors.move(80); //turn left 90 deg
		leftDriveMotors.move(-80);
		pros::delay(160);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1000);
		rightDriveMotors.move(-80); //hit wall
		leftDriveMotors.move(-80);
		pros::delay(300);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(100);
		rightDriveMotors.move(80);
		leftDriveMotors.move(80);
		pros::delay(340);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1500);

		rightDriveMotors.move(-80); //turn right 90 deg
		leftDriveMotors.move(80);
		pros::delay(160);
		rightDriveMotors.brake(); 
		leftDriveMotors.brake();
		pros::delay(1200);
		rightDriveMotors.move(127); //first ball
		leftDriveMotors.move(127);
		pros::delay(700);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1200);
		rightDriveMotors.move(-80); //backs up
		leftDriveMotors.move(-80);
		pros::delay(300);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(600);

		rightDriveMotors.move(80); //turn left 90 deg
		leftDriveMotors.move(-80);
		pros::delay(165);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1000);
		rightDriveMotors.move(80); //drive to next ball
		leftDriveMotors.move(80);
		pros::delay(200);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1500);

		rightDriveMotors.move(-80); //turn right 90 deg
		leftDriveMotors.move(80);
		pros::delay(165);
		rightDriveMotors.brake(); //second ball
		leftDriveMotors.brake();
		pros::delay(1200);
		rightDriveMotors.move(127);
		leftDriveMotors.move(127);
		pros::delay(700);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(1200);
		rightDriveMotors.move(-80); //backs up
		leftDriveMotors.move(-80);
		pros::delay(300);
		rightDriveMotors.brake();
		leftDriveMotors.brake();
		pros::delay(600);

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
		double leftAxisY = MasterController.get_analog(axisLeftY);
		double rightAxisX = MasterController.get_analog(axisRightX);
		double leftVelocity = ((leftAxisY + rightAxisX));
		double rightVelocity = ((leftAxisY - rightAxisX));

		// 1 stick arcade
		//double leftAxisY = MasterController.get_analog(axisLeftY);
		//double leftAxisX = MasterController.get_analog(axisLeftX);
		//double rightAxisX = MasterController.get_analog(axisRightX);
		//double aimVelocityLeft = (rightAxisX) * 0.06;
		//double aimVelocityRight = -rightAxisX * 0.06;
		//double leftVelocity = ((leftAxisY + leftAxisX + aimVelocityLeft));
		//double rightVelocity = ((leftAxisY - leftAxisX + aimVelocityRight));

		// Tank
		// double leftAxisY = MasterController.get_analog(axisLeftY);
	    // double rightAxisY = MasterController.get_analog(axisRightY);
		// double leftVelocity = ((leftAxisY) * axisPercentBlue);
		// double rightVelocity = ((rightAxisY) * axisPercentBlue);

		driveLoop(leftDriveMotors, rightDriveMotors, leftVelocity, rightVelocity);

	}
}
