#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;


class Player{
    public:
    string name;
    vector<string> cards_in_hand;
    int score;
    int money;
    int bet;

    Player(string, int);

    void list_cards_in_hand();

    void list_cards_of_computer();

    void grab_money(Player &);

    int compute_score();


};
#endif