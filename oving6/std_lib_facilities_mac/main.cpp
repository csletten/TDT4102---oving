//
//  main.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 20/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "fileintro.hpp"
#include "CourseCatalog.hpp"
#include "temps.hpp"

int main(){
    
    //inputText();
    //readline();
    // charStatistics();
    //CourseCatalog newCatalog;
    // newCatalog.addExampleCourse();
    //newCatalog.addCourse("TFE4101", "Krets- og digitalteknikk");
    ///cout << newCatalog;
    // newCatalog.removeCourse("TFE4101");
    //newCatalog.save("test.txt");
    // newCatalog.load("test.txt");
    //cout << newCatalog;
    ifstream temp_file{"temperatures.txt"};
    Temps t;
    temp_file >> t;
    cout << "max: " << t.max << ", "<< "min: " << t.min <<endl;
    
    
    
    return 0;
}
