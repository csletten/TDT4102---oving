//
//  Blackjack.hpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef Blackjack_hpp
#define Blackjack_hpp

#include <stdio.h>



class Blackjack{
public:
    Blackjack() = default;
    void play();
private:
    CardDeck deck;
    int getPlayerValue(Card card);
    int getDealerValue(Card card, int dealerHand);
    bool continuePlaying();
    void playerDrawCard(CardDeck deck, int& playerHand);
    void dealerDrawCard(CardDeck deck, int& dealerHand);
    
};

#endif /* Blackjack_hpp */
