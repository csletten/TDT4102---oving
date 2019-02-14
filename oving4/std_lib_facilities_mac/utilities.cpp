//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 28/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"

#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
    startValue += increment;
}
    return startValue;
    
}

void incrementByValueNumTimesRef(int& v0, int& increment, int& iterations, int& result) {
    for (int i = 0; i < iterations; i++) {
        result += increment;
    }
    
}

void swapNumbers(int& num1, int& num2){
    int a = num1;
    num1 = num2;
    num2 = a;
}

// Det er gunstig å bruke to variabler ettersom det er to variabler som skal returneres.

int randomWithLimits(int lowerLimit, int upperLimit){
    return lowerLimit + (rand()%(upperLimit-lowerLimit));
}

void randomizeVector(vector<int>& v, int n){
    for (int i = 0; i < n; i++){
        v.push_back(randomWithLimits(0, 100));
    }
}

void sortVector(vector<int>& v){
    int i = 1;
    while ( i < v.size()){
        int j = i;
        while(j > 0 && v[j-1]>v[j]){
            swapNumbers(v[j], v[j-1]);
            j--;
        }
        i++;
    }
}

double medianOfVector(vector<int> v){
    int mid = static_cast<int>(v.size()/2);
    if (v.size() % 2 != 0){
        return v[mid];
    }else{
        return (v[mid]+v[mid-1])/2;
    }
    
}

string randomizeString(int amountChars, char lowerLimit, char upperLimit){
    string newstr;
    for (int i = 0; i < amountChars; i++){
        newstr += char(randomWithLimits(int(lowerLimit), int(upperLimit)+1));
    }
    return newstr;
}

string readInputToString(int n, char lowerLimit, char upperLimit){
    string inputStr;
    cout << "Skriv inn bokstaver som er innenfor grensene: ";
    cin >> inputStr;
    for (int i : inputStr){
        if (isalpha(i) == false || i < lowerLimit || i > upperLimit){
            cout << "Skriv kun inn bokstaver som er innefor grensene" << endl;
            return "";
        }
    }
    return inputStr;
}

int countChar(string countStr, char c){
    int amount = 0;
    for (int i : countStr){
        if (tolower(int(i)) == tolower(int(c))){
            amount++;
        }
    }
    return amount;
}
