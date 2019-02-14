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
    CardDeck();
    /*
    CardDeck(){
        for (int i = static_cast<Rank>(Two); i != static_cast<Rank>(ace); i++){
            for (int j: Suit){
                
            }
        }
        currentCardIndex = 0;
        
    }
    */
    
    // Klassen er public ettersom at det er nødvendig for brukeren å kunne stokke kortstokken
    void swap(int index1, int index2);
            
private:
    vector<Card> cards;
    int currentCardIndex;
    
};

#endif /* CardDeck_hpp */
