//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 23/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "utilities.hpp"
#include "std_lib_facilities.h"


int generateRand(){
    return rand();
}

int randomWithLimits(int lowerLimit, int upperLimit){
    return lowerLimit + (rand()%(upperLimit-lowerLimit));
}

void playTargetPractice(){
    double vinkel;
    double startfart;
    getUserInput(vinkel, startfart);
    double velX = getVelocityX(vinkel, startfart);
    double velY = getVelocityY(vinkel, startfart);
    for (int i = 0; i < 10; i++){
        int blinkavstand = randomWithLimits(100, 1000);
        double avvik = targetPractice(blinkavstand, velX, velY);
        cout << "Du var " << abs(avvik) << " meter unna blinken." << endl;
        if (avvik > 0){
            cout << "Skuddet var for kort" << endl;
        } else{
            cout << "Skuddet var for langt" << endl;
        }
        double flytid = flightTime(startfart);
        cout << "FlightTime: " <<flytid << endl;
        cout << "Skuddet brukte ";
        printTime(flytid);
        cout << "på å treffe målet." << endl;
        
        if (abs(avvik) < 5){
            cout << "Gratulerer, du har vunnet!" << endl;
            break;
        }
        cout << "Du har tapt!" << endl;
    }
   
    
    
    
    
}
