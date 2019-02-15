//
//  CardDeck.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "Card.hpp"
#include "CardDeck.hpp"
#include "Blackjack.hpp"

CardDeck::CardDeck(){
    for (int i = int(Rank::two); i <= int(Rank::ace); i++){
        for (int j = int(Suit::clubs); j <= int(Suit::spades); j++){
            Card card {Suit(j), Rank(i)};
            cards.push_back(card);
            
        }
    }
    currentCardIndex = 0;
}

void CardDeck::swap(int index1, int index2){
    Card placeholder = cards[index1];
    cards[index1] = cards[index2];
    cards[index2] = placeholder;
}

void CardDeck::print(){
    for (Card c: cards){
        cout << c.toString() << endl;
    }
}

void CardDeck::printShort(){
    for (Card c: cards){
        cout << c.toStringShort() << endl;
    }
}

void CardDeck::shuffle(){
    srand(time(nullptr));
    for (int i = 0; i < 100; i++){
        int rand1 = rand()%52;
        int rand2 = rand()%52;
        swap(rand1, rand2);
    }
}

const Card& CardDeck::drawCard(){
    return cards[currentCardIndex++];
}
