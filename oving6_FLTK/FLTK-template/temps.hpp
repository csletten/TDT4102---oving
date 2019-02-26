//
//  temps.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 20/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef temps_hpp
#define temps_hpp

#include <stdio.h>

struct Temps{
    Temps();
    double max;
    double min;

};

istream& operator>>(istream&,  Temps&);

vector<Temps> createVector();


#endif /* temps_hpp */
