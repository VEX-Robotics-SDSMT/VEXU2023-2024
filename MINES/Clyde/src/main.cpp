#include "main.h"
#include "DiffDrive.h"
#include "botFunctions.h"
#include "globals.h"
#include "pros/misc.h"
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
	EncoderWheelSensorInterface encoderInterface(driveEncoder);
	DiffDrive drive(leftDriveMotors, rightDriveMotors, &encoderInterface, intertialSensor);
	drive.setDrivePIDVals(0.85, 0, 0);//0.75
	drive.setDrivePIDTol(50);
	drive.setTurnPIDVals(3.4, 0, 0);//3.5
	drive.setTurnPIDTol(1.25);
	drive.setMaxDriveSpeed(1); 
	drive.setMaxTurnSpeed(1);

	drive.setMaxDriveAccel(0.12);
	if(!skills && !auto2)
	{
		//**************SHOOT 10***********************
		pros::delay(15000); //change for pinky
		catPrime(cataMotors, limitSwitch, -100);
		pros::delay(500);
	   	catLaunch(cataMotors, limitSwitch, -127);
		pros::delay(600);
	    for(int i = 0; i < 9; i++)
	    {
	   		catPrime(cataMotors, limitSwitch, -100);
	   		pros::delay(335);
	   		catLaunch(cataMotors, limitSwitch, -127);
	  		pros::delay(600);
		}

		//*************POP TRIBALL*********************
		drive.driveTiles(150);
		//pros::delay(1000);
		drive.turnDegreesAbsolute(260);
		//pros::delay(1000);
		wingL.set_value(1);
		drive.setMaxDriveSpeed(0.72);
		//pros::delay(1000);
		drive.driveTiles(550, 2000);
		drive.setMaxDriveSpeed(1);
		//pros::delay(500);
		wingL.set_value(0);
		

		//**************PUSH UNDER*********************
		drive.turnDegreesAbsolute(295);
		drive.driveTiles(425, 1000);
		
		drive.driveTiles(-600);

		//**************GO TOUCH BAR******************
		drive.turnDegreesAbsolute(240);
		drive.driveTiles(-1175);
		drive.turnDegreesAbsolute(210);
		drive.driveTiles(-1350);
		drive.killPIDs();
	}
	else if(auto2)
	{
		// **************POP FROM CORNER STRAT**********
		//***************POP ALLIANCE BALL**************
		//wingL.set_value(1);
		//drive.driveTiles(500, 1000);
		//wingL.set_value(0);
		//pros::delay(500);
		////***************RAM ALLIANCE BALL**************
		//drive.turnDegreesAbsolute(30);
		//drive.driveTiles(500, 700);
		//drive.driveTiles(-500);
		////*TURN AROUND TO START POPPING FROM OTHER SIDE*
		//drive.turnDegreesAbsolute(170);
		//wingR.set_value(1);
		//drive.driveTiles(600);
		//drive.setMaxDriveAccel(0.4);
		//for(int i = 0; i < 5; i++)	//set to 10 later
		//{
		//	pros::delay(200);
		//	drive.driveTiles(-500);
		//	drive.driveTiles(500);
		//}
		////wingR.set_value(0);
		//drive.setMaxDriveAccel(0.15);
		////*******PUSH FORWARD TOWARD GOAL***************
		//wingR.set_value(0);
		//drive.turnDegreesAbsolute(140);
		//drive.driveTiles(1000, 800);
		////wingR.set_value(1);
		//drive.turnDegreesAbsolute(130);
		//drive.driveTiles(2000);
		////********REPOSITION****************************
		//wingR.set_value(0);
		//drive.turnDegreesAbsolute(100);
		//drive.setMaxDriveSpeed(0.4);
		//drive.driveTiles(600);
		//wingL.set_value(1);
		//drive.turnDegreesAbsolute(80);

		// **********Wait for Pinky**********
		pros::delay(6000);
		// **********Drive forward off of start and open wing**********
		drive.driveTiles(400);
		wingR.set_value(1);
		//pros::delay(3000);
		drive.driveTiles(250);
		//pros::delay(3000);
		drive.setMaxDriveAccel(1);
		drive.setMaxDriveSpeed(1);
		// **********Pop 10 triballs**********
		for(int i = 0; i < 9; i++)
		{
			//pros::delay(200);
			drive.driveTiles(300);
			drive.driveTiles(-300);
		}
		drive.driveTiles(350);
		//wingR.set_value(0);		
		//drive.setMaxDriveAccel(.5);
		//drive.setMaxDriveSpeed(.5);
		//drive.driveTiles(350, 2000);
		//drive.turnDegreesAbsolute(315);
		////pros::delay(3000);
		//drive.driveTiles(500, 2000);
		//drive.driveTiles(-500);
		//drive.turnDegreesAbsolute(0);
		//drive.driveTiles(-600);
		//wingR.set_value(1);
		//pros::delay(200);
		//for(int i = 0; i < 4; i++)
		//{
		//	//pros::delay(200);
		//	drive.driveTiles(300);
		//	drive.driveTiles(-300);
		//}
		//// **********Bowl triballs accross field**********
		//drive.driveTiles(350);
		wingR.set_value(0);		
		drive.setMaxDriveAccel(.5);
		drive.setMaxDriveSpeed(.5);
		drive.driveTiles(300, 2000);
		drive.turnDegreesAbsolute(315);
		//pros::delay(3000);
		drive.driveTiles(3400, 4000);
		//pros::delay(3000);
		drive.turnDegreesAbsolute(270);
		//pros::delay(3000);
		drive.driveTiles(900);
		//pros::delay(3000);
		drive.turnDegreesAbsolute(225);
		//pros::delay(3000);
		drive.driveTiles(400);
		drive.setMaxDriveAccel(1);
		drive.setMaxDriveSpeed(1);
		// **********Push triballs under goal**********
		for(int i = 0; i < 2; i++)
		{
			drive.driveTiles(300, 1000);
			drive.driveTiles(-300, 1000);
			//pros::delay(3000);
		}
		// **********Go touch for winpoint**********
		drive.turnDegreesAbsolute(270);
		//pros::delay(3000);
		drive.driveTiles(-1200);
		//pros::delay(3000);
		drive.turnDegreesAbsolute(315);
		//pros::delay(3000);
		drive.driveTiles(-1500);
	}
	else
	{
		// *******************PHASE 1*******************

		catPrime(cataMotors, limitSwitch, -100);
		pros::delay(500);
		catLaunch(cataMotors, limitSwitch, -127);
		pros::delay(600);
		for(int i = 0; i < 21; i++)
		{
			catPrime(cataMotors, limitSwitch, -100);
			pros::delay(335);
			catLaunch(cataMotors, limitSwitch, -127);
			pros::delay(600);
		}
		drive.driveTiles(500);
		drive.turnDegreesAbsolute(110);
		drive.driveTiles(450);
		drive.turnDegreesAbsolute(27);
		drive.driveTiles(3100);
		drive.turnDegreesAbsolute(292);
		// *******************PHASE 2*******************
		drive.driveTiles(800);
		drive.turnDegreesAbsolute(235);
		drive.driveTiles(400);
		wingL.set_value(1);
		wingR.set_value(1);
		// SWING TURN
		drive.setActive(false);
		leftDriveMotors.moveVelocity(330);
		rightDriveMotors.moveVelocity(28);
		pros::delay(750);
		leftDriveMotors.brake();
		rightDriveMotors.brake();
		drive.setActive(true);

		
		drive.driveTiles(200);


		drive.setMaxDriveAccel(1);

		//wingR.set_value(0);
		//pros::delay(3000);
		drive.driveTiles(1500, 1500);
		wingR.set_value(0);
		wingL.set_value(0);
		drive.driveTiles(-1500);
		wingR.set_value(1);
		wingL.set_value(1);

		// drive.setActive(false);
		// leftDriveMotors.moveVelocity(325);
		// rightDriveMotors.moveVelocity(5);
		// pros::delay(750);
		// leftDriveMotors.brake();
		// rightDriveMotors.brake();
		// drive.setActive(true);

		
		drive.killPIDs();
	}
	drive.killPIDs();
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
	int cataTarget = 0;
	tracking.set_value(1);
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
		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2))
		{
			if(cataTarget == 0)
			{
				cataTarget = 1;
			}				
			else
			{
				cataTarget = 0;
			}				
		}
		else if (MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
			cataMotors.moveVelocity(127);
			cataTarget = 0;
		}
		else
		{
			catLoop(cataMotors, limitSwitch, cataTarget);
		}


		//*******************WINGS**********************
		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			wingL.set_value(1);
			wingR.set_value(1);
		}		
		else if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
			wingL.set_value(1);
		else if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
			wingR.set_value(1);	
		else
		{
			wingL.set_value(0);
			wingR.set_value(0);
		}

		if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_X))
		{
			hang.set_value(1);
		}
		else
		{
			hang.set_value(0);
		}

		if(MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
		{
			catPrime(cataMotors, limitSwitch, -100);
		   	pros::delay(500);
		   	catLaunch(cataMotors, limitSwitch, -127);
		  	pros::delay(600);
		   for(int i = 0; i < 21; i++)
		   {
		   	catPrime(cataMotors, limitSwitch, -100);
		   	pros::delay(335);
		   	catLaunch(cataMotors, limitSwitch, -127);
		  	pros::delay(600);
			if(MasterController.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
				break;
		   }
		}
		
		
	}
}
