//
//  utilities.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 28/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>

#endif /* utilities_hpp */


int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& v0, int& increment, int& iterations, int& result);

void swapNumbers(int& num1, int& num2);

int randomWithLimits(int lowerLimit, int upperLimit);

void randomizeVector(vector<int>& v, int n);

void sortVector(vector<int>& v);

double medianOfVector(vector<int> v);

string randomizeString(int amountChars, char lowerLimit, char upperLimit);

string readInputToString(int n, char lowerLimit, char upperLimit);

int countChar(string countStr, char c);
