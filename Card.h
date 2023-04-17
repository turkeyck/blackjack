#ifndef CARD_H
#define CARD_H


#include <vector>
#include <string>
#include "Player.h"
using namespace std;


class Card{
    // public:
    // vector<string> suit;
    // vector<string> rank;
    private:
    string card;
    

    public:
    string suit;
    string rank;
    Card(string suit, string rank);
    // std::ostream is the type for object std::cout
    friend std::ostream& operator<< (std::ostream& out, const Card& );




    // void shuffle();
    // void secret_deal(Player &);
    // void deal(Player & );
    // void recycle_card(Player &) ;
    // void reconstruct();
};

#endif