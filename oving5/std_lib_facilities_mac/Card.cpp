//
//  Card.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 06/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "Card.hpp"
#include "CardDeck.hpp"
#include "Blackjack.hpp"

map<Rank, string> rankMap ={
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"}
};

string suitToString(Suit suit){
    string result = "";
    switch(suit){
        case Suit::clubs:
            result = "Clubs";
            break;
        case Suit::diamonds:
            result = "Diamonds";
            break;
        case Suit::hearts:
            result = "Hearts";
            break;
        case Suit::spades:
            result = "Spades";
            break;
    }
    return result;
}

string rankToString(Rank rank){
    return rankMap[rank];
}

//  Mer lesbar kode og en begrenset verdimengde (For eksempel kan kort kun anta en verdi mellom 2-14)

string toString(CardStruct card){
    string suit = suitToString(card.s);
    string rank = rankToString(card.r);
    return rank + " of " + suit;
}

string toStringShort(CardStruct card){
    string suit = suitToString(card.s);
    return suit.substr(0, 1) + to_string(int(card.r));
}

bool Card::isValid(){
    if(!valid){
        return false;
    } else{
        return true;
    }
}

string Card::toString(){
    if (isValid()){
        return rankToString(r) + " of " + suitToString(s);
    } else{
        return "Ugyldig kort.";
    }
}

string Card::toStringShort(){
    if (isValid()){
        return suitToString(s).substr(0, 1) + to_string(int(r));
    } else{
        return "Ugyldig kort.";
    }
}



 
