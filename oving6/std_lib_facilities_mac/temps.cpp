//
//  temps.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 20/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "fileintro.hpp"
#include "CourseCatalog.hpp"
#include "temps.hpp"


Temps::Temps(){max = 0; min = 0;};

// Gjør det å mulig å skrive ut temperaturen direkte
istream& operator>>(istream& is, Temps& t){
    Temps tt;
    if(is >> t.max >> t.min) {return is;}
    else {t=tt; return is;}
}

vector<Temps> createVector(){
    vector<Temps> temps;
    ifstream temp_file{"temperatures.txt"};
    Temps t;
    temp_file >> t;
    temps.push_back(t);
    return temps;
}
