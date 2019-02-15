//
//  CardDeck.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef CardDeck_hpp
#define CardDeck_hpp

#include <stdio.h>
#include "std_lib_facilities.h"
#include "Card.hpp"

class CardDeck{
public:
    // Constructor
    CardDeck();
    
    void print();
    void printShort();
    void shuffle();
    const Card& drawCard();
    
private:
    vector<Card> cards;
    int currentCardIndex;
    
    // Klassen er private ettersom at det er "dealeren" som stokker kortet
    void swap(int index1, int index2);
};

#endif /* CardDeck_hpp */
