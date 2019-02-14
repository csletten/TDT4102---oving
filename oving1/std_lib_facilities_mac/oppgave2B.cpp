//
//  oppgave2B.cpp
//  oving1
//
//  Created by Christian Sletten on 08/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

// old_hello.cpp
#include "std_lib_facilities.h"

int maxOfTwo(int a, int b){
    if(a > b){
        cout << "A is greater than B \n";
        return a;
    }
    else{
        cout << "B is greater than or equal to A \n";
        return b;
        
    }
}
int main(){
    cout << "Oppgave a)\n";
    cout << maxOfTwo(5, 6) << "\n";


}

