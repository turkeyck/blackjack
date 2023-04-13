#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Player.h"
using namespace std;


class Card{
    public:
    vector<string> suit;
    vector<string> rank;
    vector<string> card;
    // vector<string> trash_card;

    Card();
    void shuffle();
    void deal(Player & );
    void recycle_card(Player &) ;
};

#endif

