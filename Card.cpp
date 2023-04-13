// #ifndef CARD_H
// #define CARD_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include "Player.h"
#include "Card.h"
using namespace std;


    // create 52 crads
    Card::Card()
    {
        // int total = 52;
        vector<string> suit = {"club", "diamond", "spade", "heart"};
        vector<string> rank = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        // vector<string> card ;
        // vector<string> trash_card;
        for (string i: suit){
            for (string j:rank){
                card.push_back(i+j);
            }
        }
    }
    void Card::shuffle() {
        vector<string> sh_card;
        srand(time(NULL));
        for (int i=0; i<52; i++){
            int idx = rand() % (52-i) + 1;
            // cout << idx << endl;
            sh_card.push_back(card[idx]);
        }
        card = sh_card;
        // random_shuffle( card.begin(), card.end() );
    }


    void Card::deal(Player & p) {
        cout << p.name << " gets a new card: " << card[0] << endl;
        p.cards_in_hand.push_back(card[0]);
        // cout << "cards_in_hand= "  << endl;
        // for (auto it = p.cards_in_hand.begin(); it != p.cards_in_hand.end(); ++it) {
        //     cout <<*it <<" ";
        // }
        // cout << p.cards_in_hand.size() << endl;
        card.erase(card.begin());
    }

    void Card::recycle_card(Player & p) {
        p.cards_in_hand.clear();
    }

