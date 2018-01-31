/*
*  Name        : lab_2.cpp
*  Author      : FILL IN
*  Description : Using Arithmetic to finish the functions MakeChange() and
*  LaunchHumanCannonball()
*  Sources     :
*/

// Please note the header above. You need to include the name of the file, 
// author, a description of the program and any sources used
#include "Lab2.h"

void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels, int &pennies) {
    quarters = initial_value / 25;
    dimes = (initial_value % 25) / 10;
    nickels = ((initial_value % 25) % 10) / 5;
    pennies = ((initial_value % 25) % 10) % 5;
}



double LaunchHumanCannonball(double initial_velocity, double launch_angle) {
// (1) Convert launch_angle from degrees to radians
    double radian_angle = launch_angle * (kPI/180);

// (2) Compute final horizontal/x velocity
    double x_velocity = initial_velocity * cos(radian_angle);

// (3) Compute final vertical/y velocity
    double y_velocity = initial_velocity * sin(radian_angle) * -1;

// (4) Compute time of flight
    double flight_time = (y_velocity) * 2 / -9.8;

// (5) Compute horizontal/x distance traveled
    double x_distance = x_velocity * flight_time;

// (6) Return horizontal/x distance
    return x_distance;
}

