#include "std_lib_facilities.h"
#include "cannonball.hpp"
#include "utilities.hpp"

//void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main(){
    /*
    double velocityX = 7.49;
    double velocityY = 10;
    getVelocityVector(0.8, 3, velocityX, velocityY);
    cout << getDistanceTraveled(velocityX, velocityY) << endl;
    cout << targetPractice(20, 7.5, 10) << endl;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 10; i++){
        cout << randomWithLimits(25, 63) << endl;
    }
    */
    playTargetPractice();
    return 0;
}
/*
void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    int absDelta = abs(compareOperand - toOperand);
    if (absDelta < maxError){
        cout << name << ": has an accepted deviation. " << endl;
    } else{
        cout << name << ": does not have an accepted deviation. " << endl;
    }
}

*/
