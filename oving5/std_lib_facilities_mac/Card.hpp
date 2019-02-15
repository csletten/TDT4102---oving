//
//  Card.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 06/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include "std_lib_facilities.h"

enum class Suit{clubs=1, diamonds, hearts, spades};

enum class Rank{two=2,three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string intToString2(int number);

string suitToString(Suit suit);

string rankToString(Rank rank);

struct CardStruct{
    Suit s;
    Rank r;
};

string toString(CardStruct card);

string toStringShort(CardStruct card);

class Card{
public:
    Card() = default;
    Card(Suit suit, Rank rank):s{suit}, r{rank}{valid = true;};
    
    Suit suit(){return s;}
    Rank rank(){return r;}
    
    bool isValid();
    
    string toString();
    
    string toStringShort();
    
    // Vi bruker en class istedenfor en struct for å kunne bruke private medlemmer.
    // Invarianten til klassen er at den må ha en farge og en verdi.
private:
    Suit s;
    Rank r;
    bool valid;
};

#endif /* Card_hpp */
