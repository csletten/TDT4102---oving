//
//  CourseCatalog.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef CourseCatalog_hpp
#define CourseCatalog_hpp

#include <stdio.h>
#include "std_lib_facilities.h"


class CourseCatalog{
public:
    friend ostream& operator<<(ostream&, const CourseCatalog&);
    void addCourse(string fagkode, string fagnavn);
    void removeCourse(string fagkode);
    string getCourse(string fagkode);
    void addExampleCourse();
    void load(string filename);
    void save(string filename);
private:
    map<string, string> catalog;
};
#endif /* CourseCatalog_hpp */
