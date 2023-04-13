#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Player.h"
using namespace std;


// class Player{
//     public:
    // string name;
    // vector<string> cards_in_hand;
    // int score;
    // int money;
    // int bet;

    Player::Player(string s, int m=100)
    {
        name = s;
        money = m;
        score = 1;
        bet = 0;
        cards_in_hand = {};
    }

    void Player::list_cards_in_hand(){
        int card_size = (int) cards_in_hand.size();
        cout <<name <<" has cards ";
        for (int i = 0; i < card_size; i++){
            cout << cards_in_hand[i] << " ";
        }
        cout << "\n";
    }

    void Player::list_cards_of_computer(){
        int card_size = cards_in_hand.size();
        cout <<name <<" has cards ";
        for (int i = 1; i < card_size; i++){
            cout <<cards_in_hand[i] << " ";
        }
        cout << "\n";
    }

    void Player::grab_money(Player & p){
        p.money -= bet;
        money += bet;
    }

    int Player::compute_score(){
        int num_A = 0;
        int sc = 0;
        for (string i : cards_in_hand) {
            // cout << sc << "!!!!!!  0"<<"\n";
            // cout << " i[i.size()-1] is " << i[i.size()-1] << endl;
            if ( (i[i.size()-1] == 'J') || (i[i.size()-1] == 'Q') || (i[i.size()-1] == 'K') || (i[i.size()-1] == '0')) {
                sc += 10;
                // cout << sc << "!!!!!!1"<<"\n";
            }
            else if (i[i.size()-1] == 'A'){
                sc += 11;
                num_A += 1;
                // cout << sc << "!!!!!! 2"<<"\n";
            }
            else{
                int num = (int) (i[i.size()-1]-'0');
                // num -= 48;
                // int num = stoi(i[i.size()-1]);
                sc += num;
                
                // cout << sc <<" "<< num<< " !!!!!!  3"<<"\n";
            }
        }

        while (sc > 21 && num_A > 0) {
            sc -= 10;
            num_A -= 1;
        }
        score = sc;
        cout << name << " has " << score << " points." << endl;

        return score;
    }

// };
// #endif