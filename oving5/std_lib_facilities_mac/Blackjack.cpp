//
//  Blackjack.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 14/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "Card.hpp"
#include "CardDeck.hpp"
#include "Blackjack.hpp"


void Blackjack::play(){
    bool bust = false;
    bool isBlackjack = false;
    int playerHand = 0;
    int dealerHand = 0;
    
    deck.shuffle();
    
    playerDrawCard(deck, playerHand);
    
    dealerDrawCard(deck, dealerHand);
    
    cout << "Dealer drew " << dealerHand << endl;
    
    playerDrawCard(deck, playerHand);
    
    dealerDrawCard(deck, dealerHand);
    
    // Dealeren fortsetter å trekke kort til han har en verdi over 17
    while (dealerHand < 17){
        dealerDrawCard(deck, dealerHand);
    }
    
    cout << "You currently have the value " << playerHand << endl;
    
    // Sjekker om spilleren har Blackjack
    if (playerHand == 21){
        isBlackjack = true;
    }
    
    // Fortsetter spillet så lenge spilleren ikke er er bust og han ønsker å fortsette
    while(!isBlackjack && continuePlaying()){
        playerDrawCard(deck, playerHand);
        if (playerHand > 21){
            bust = true;
            cout << "Bust! You lose..." << endl;
            break;
        }
        cout << "You currently have the value " << playerHand << endl;
    }
    
    // Evaluerer resultatet hvis spilleren ikke allerede har gått over 21
    if (!bust){
        if (isBlackjack && dealerHand != 21){
            cout << "You are the winner! And you got a Blackjack" << endl;
        } else if (playerHand > dealerHand || dealerHand >= 21){
            cout << "You are the winner!" << endl;
        } else if (playerHand == dealerHand){
            cout << "It's a draw." << endl;
        } else {
            cout << "You lost, try again next time." << endl;
        }
    }
    cout << "Player: " << playerHand << "\tDealer: " << dealerHand << endl;
}

// Øker verdien til hånda til spilleren når et kort er trukket
int Blackjack::getPlayerValue(Card card){
    Rank rank = card.rank();
    int value;
    switch (rank) {
        case Rank::jack:
        case Rank::queen:
        case Rank::king:
            value = 10;
            break;
        case Rank::ace:
            cout << "Do you want the ace to have the value 1 or 11 (1/11): ";
            cin >> value;
            while(value != 1 && value !=11){
                cout << "Oops! You can only pick the value 1 or 11 \nAdd the number again: ";
                cin >> value;
            }
            break;
        default:
            value = int(rank);
            break;
    }
    return value;
}

// Øker verdien til hånda til dealeren når et kort er trukket
int Blackjack::getDealerValue(Card card, int dealerHand){
    Rank rank = card.rank();
    int value;
    switch (rank) {
        case Rank::jack:
        case Rank::queen:
        case Rank::king:
            value = 10;
            break;
        case Rank::ace:
            value = dealerHand > 10 ? 1 : 11;
            break;
        default:
            value = int(rank);
            break;
    }
    return value;
}

// Spør brukeren om han ønsker å fortsette å spille
bool Blackjack::continuePlaying(){
    cout << "Do you want a new card? ";
    char c;
    cin >> c;
    return (tolower(c) == 'y' || tolower(c) == 'j');
}

// Trekker nytt kort til spilleren og øker verdien til hånden
void Blackjack::playerDrawCard(CardDeck deck, int& playerHand){
    Card card = deck.drawCard();
    playerHand += getPlayerValue(card);
    cout << "You drew " << card.toString() << endl;
}

// Trekker nytt kort til dealeren og øker verdien til hånden
void Blackjack::dealerDrawCard(CardDeck deck, int& dealerHand){
    Card card = deck.drawCard();
    dealerHand += getDealerValue(card, dealerHand);
}
