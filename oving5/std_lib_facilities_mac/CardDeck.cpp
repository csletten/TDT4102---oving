//
//  CardDeck.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "CardDeck.hpp"
#include "std_lib_facilities.h"
#include "Card.hpp"

void CardDeck::swap(int index1, int index2){
    Card placeholder = cards[index1];
    cards[index1] = cards[index2];
    cards[index2] = placeholder;
}
