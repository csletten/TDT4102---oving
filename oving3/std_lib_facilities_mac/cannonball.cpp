//
//  cannonball.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 21/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "cannonball.hpp"
#include "std_lib_facilities.h"

constexpr double pi = 3.1415926;

double acclY(){
    return -9.81;
}

double velY(double initVelocityY, double time){
    return initVelocityY + acclY()*time;
}

double posY(double initPosition, double initVelocityY, double time){
    return initPosition + initVelocityY*time + ((acclY()*pow(time, 2)))/2;
}

double posX(double initPosition, double initVelocityX, double time){
    return initPosition + initVelocityX*time;
}

void printTime(double seconds){
    int hours = seconds / 3600;
    int minutes = (seconds - hours * 3600)/60;
    int remSeconds = seconds - hours*3600 - minutes*60;
    cout << hours << " timer,  " << minutes << " minutter og " << remSeconds << " sekunder." << endl;
}

double flightTime(double initVelocity){
    return (-2*initVelocity)/acclY();
}

void getUserInput(double& theta, double& absVelocity){
    cout << "Skriv inn vinkel i grader: ";
    cin >> theta;
    cout << endl;
    cout << "Skriv inn fart: ";
    cin >> absVelocity;
}

double degToRad(double deg){
    return (deg*pi)/180;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity){
    return absVelocity * sin(theta);
}

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY){
    velocityX = getVelocityX(theta, absVelocity);
    velocityY = getVelocityY(theta, absVelocity);
    cout << "velocityX: " << velocityX << endl << "velocityY: " << velocityY << endl;
}

double getDistanceTraveled(double velocityX, double velocityY){
    int time = flightTime(velocityY);
    return posX(0, velocityX, time);
}


double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return distanceToTarget-getDistanceTraveled(velocityX, velocityY);
}

