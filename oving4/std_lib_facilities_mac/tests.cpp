//
//  tests.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 28/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"

#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}
void testCallByValueRef() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = v0;
    incrementByValueNumTimesRef(v0, increment, iterations, result);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testVectorSorting(){
    vector<int> percentages;
    randomizeVector(percentages, 20);
    swapNumbers(percentages[0], percentages[1]);
    cout << "Median before sort: " << medianOfVector(percentages) << endl;
    sortVector(percentages);
    for (int r : percentages){
        cout << "Verdi: " << r << endl;
    }
    cout << "Median after sort: " << medianOfVector(percentages) << endl;
}

void testString(){
    string grades = randomizeString(8, 'A', 'F');
    cout << "Karakterer: " << grades << endl;
    vector<int> gradeCount = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < gradeCount.size(); i++){
        gradeCount[i] = countChar(grades, 'A'+i);
        cout << gradeCount[i] << endl;;
    }
    double average = (gradeCount[0]*5+gradeCount[1]*4+gradeCount[2]*3+gradeCount[3]*2+gradeCount[4])/double(gradeCount.size());
    cout << fixed << setprecision(2)<< "Gjennomsnittskarakteren var: " << average << endl;
    
}

