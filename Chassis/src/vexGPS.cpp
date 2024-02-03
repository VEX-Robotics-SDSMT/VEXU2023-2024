#include "vexGPS.h"

//write excess functions here for driving with GPS

/*
gpsdrive
distance - the distance in meters that you want to drive
xdir is +1 if going in positive x direction, -1 otherwise
ydir is +1 if going in positive y direction, -1 otherwise
speed is the speed to run the motors, negative if traveling backwards

*/ 
void gpsdrive(double distance, int xdir, int ydir, double speed, Mines::MinesMotorGroup left, Mines::MinesMotorGroup right, pros::GPS gps)
{
    MasterController.print(0, 0, "%s", "enter gps drive");
    pros::delay(200);
    MasterController.clear_line(0);
    pros::c::gps_status_s_t stat = gps.get_status();
	double currx = stat.x;
	double curry = stat.y;
    double angle = gps.get_heading(); //get degrees
    double trigAngle = angle;
    while (trigAngle > 90)
        trigAngle -= 90;
    double addx = distance * cos(trigAngle); //distance to add to currx and y
    double addy = distance * sin(trigAngle);

    double newx = currx + xdir*(addx); //newx,y are coordinates to travel to
    double newy = curry + ydir*(addy);
    bool go = true;

    //for now will test with an error tolerance of 100mm
    while(!((newx - 0.1) < currx < (newx + 0.1)) && !((newy - 0.1) < curry < (newy + 0.1)) && go)
    {
        right.move(speed), left.move(speed);
        stat = gps.get_status();
        currx = stat.x, curry = stat.y;
        if(((newx - 0.1) < currx < (newx + 0.1)) && ((newy - 0.1) < curry < (newy + 0.1)))
        {
            go = false;
            right.brake();
            left.brake();
        }
    }

    return;
} 

void gpsturn(double tgt, double speed, Mines::MinesMotorGroup left, Mines::MinesMotorGroup right, pros::GPS gps)
{
    double tol = 10.0; //tolerance on turning
    double angle = gps.get_heading();
    double pct;
    int cw = 0, ccw = 0; //cw controls angle tolerance based on direction turning
    pct = 1.0;
    bool go = true, big = false;

    //should find an algorithm to determine clock vs counter
    if(tgt > angle)// || ((270 < angle < 360) && (0 < tgt < 90)))
        speed = -speed, cw = 1; //CW
    else if(tgt < angle)
        speed = speed, ccw = 1; //CCW
    if(abs(tgt - angle) > 100)
        big = true;
    //higher speed requires higher tolerance to hit tgt than lower speeds
    //counter-clockwise
    while(((tgt - (cw * tol)) < angle < (tgt + (ccw * tol))) && go)
    {
        angle = gps.get_heading();
        
        if((abs(tgt-angle)) < 40)
            pct = 0.5, tol = 3;
        else if(((abs(tgt-angle)) < 60) && big)
            pct = 0.75;
        right.move(speed * pct), left.move(-speed * pct);
        angle = gps.get_heading();
        //MasterController.clear_line(0);
        //MasterController.print(0, 0, "%f", angle);
        if(((tgt) < angle) && (angle < (tgt + tol)))
            right.brake(), left.brake(), go = false;
    }
    right.brake(), left.brake();
    // angle = gps.get_heading();
    // if((tgt - 3 < angle < tgt + 3))
    //     recursion = false;
    // if(recursion)
    // {
    //     MasterController.clear_line(0);
    //     MasterController.print(0, 10, "%s", "Recursion");
    //     gpsturn(tgt, ospeed, left, right, gps);
    // }
        
    return;
}

void gpsturncall(double tgt, double speed, int times, Mines::MinesMotorGroup left, Mines::MinesMotorGroup right, pros::GPS gps)
{
    for(int i = 0; i < times; i++)
    {
        gpsturn(tgt, speed, left, right, gps);
        pros::delay(200);
    }
}