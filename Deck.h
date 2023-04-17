#ifndef DECK_H
#define DECK_H


#include <vector>
#include "Player.h"
#include "Card.h"
using namespace std;
class Card;
class Player;

class Deck{
    public:
    
    
    vector<string> all_suit;
    vector<string> all_rank;
    vector<Card> deck;
    // vector<string> trash_card;

    Deck();
    void swap(int, int);
    void shuffle();
    void secret_deal(Player &);
    void deal(Player & );
    void recycle_card(Player &) ;
    void reconstruct();
};

#endif

