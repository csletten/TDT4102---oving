#include "std_lib_facilities.h"
#include "fileintro.hpp"
#include "CourseCatalog.hpp"
#include <map>

int main(){
    
    //inputText();
    //readline();
    // charStatistics();
    CourseCatalog newCatalog;
    // newCatalog.addExampleCourse();
    //newCatalog.addCourse("TFE4101", "Krets- og digitalteknikk");
    ///cout << newCatalog;
    // newCatalog.removeCourse("TFE4101");
    //newCatalog.save("test.txt");
    newCatalog.load("test.txt");
    cout << newCatalog;
    
    return 0;
}
