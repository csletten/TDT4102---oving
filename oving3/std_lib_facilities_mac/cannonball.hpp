//
//  cannonball.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 21/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef cannonball_hpp
#define cannonball_hpp

#include <stdio.h>
#include "std_lib_facilities.h"

#endif /* cannonball_hpp */

double acclY();

double velY(double initVelocityY, double time);

double posY(double initPosition, double initVelocityY, double time);

double posX(double initPosition, double initVelocityX, double time);

void printTime(double seconds);

double flightTime(double initVelocity);

void getUserInput(double& theta, double& absVelocity);

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);
