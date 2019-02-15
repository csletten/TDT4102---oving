#include "std_lib_facilities.h"
#include "Card.hpp"
#include "CardDeck.hpp"
#include "Blackjack.hpp"

int main(){
    
    //CardStruct spadesThree;
    //spadesThree.r = Rank::ace;
    //spadesThree.s = Suit::spades;
    
    //cout << toStringShort(spadesThree) << endl;
    
    //Card myCard {Suit(1), Rank(2)};
    //cout << myCard.toStringShort() << endl;
    
    //CardDeck ourDeck{};
    //ourDeck.shuffle();
    //Card c = ourDeck.drawCard();
    //cout << c.toString() << endl;
    Blackjack game1;
    game1.play();
    return 0;
    
}
