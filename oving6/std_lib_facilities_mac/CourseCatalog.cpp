//
//  CourseCatalog.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 19/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "fileintro.hpp"
#include "CourseCatalog.hpp"
#include "temps.hpp"

// Legger til et kurs
void CourseCatalog::addCourse(string fagkode, string fagnavn){
    catalog[fagkode] = fagnavn;
}

// Fjernet et kurs
void CourseCatalog::removeCourse(string fagkode){
    catalog.erase(fagkode);
}

// Returner et kurs når fagkoden er spesifisert
string CourseCatalog::getCourse(string fagkode){
    return catalog[fagkode];
}

// Legger til eksempelkurs
void CourseCatalog::addExampleCourse(){
    catalog["TDT4110"] = "Informasjonsteknologi grunnkurs";
    catalog["TDT4102"] = "Prosedyre- og objektorientert programmering";
    catalog["TDT4102"] = "C++";
    catalog["TMA4100"] = "Matematikk 1";
}

// Gjør det å mulig å skrive ut katalogen direkte
ostream& operator<<(ostream& os, const CourseCatalog& cc){
    for (auto elem : cc.catalog){
        os << "(" << elem.first << ", " << elem.second << ")" << endl;
    }
    return os;
}


// Lagrer fag til fil
void CourseCatalog::save(string filename){
    ofstream ost {filename};
    if (!ost) error("Can't open output file", filename);
    for (auto elem : catalog){
        ost << elem.first << "," << elem.second << endl;
    }
}

// Laster inn fag fra fil
void CourseCatalog::load(string filename){
    string line;
    string delimiter = ",";
    ifstream ist {filename};
    if (!ist) error("Can't open load file", filename);
    while (getline(ist, line)){
        string fagkode = line.substr(0, line.find(delimiter));
        string fagnavn = line.substr(line.find(delimiter)+1, line.length());
        catalog[fagkode]=fagnavn;
    }
}
