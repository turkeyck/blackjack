#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <random>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
using namespace std;


    // create 52 crads
    Deck::Deck()
    {
        // int total = 52;
        vector<string> all_suit = {"club", "diamond", "spade", "heart"};
        vector<string> all_rank = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        // vector<string> card ;
        // vector<string> trash_card;
        for (string i: all_suit){
            for (string j:all_rank){
                deck.push_back(Card(i, j));
            }
        }
    }


    void Deck::swap(int i, int j) {
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    void Deck::shuffle() {
        vector<Card> sh_card;
        srand(time(NULL));
        // default_random_engine rng(static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count()));
        for (int i=0; i<52; i++){
            
            int idx = rand() % (52-i) + 1;
            swap(i, idx);
            // cout << idx << endl;
            // sh_card.push_back(deck[idx]);
        }
        // deck = sh_card;
        // shuffle( deck.begin(), deck.end(), rng );
    }

    void Deck::secret_deal(Player &p) {
        cout << p.name << " gets a new card: " << "*****" << endl;
        p.cards_in_hand.push_back(deck[0]);
        deck.erase(deck.begin());
    }


    void Deck::deal(Player &p) {
        cout << p.name << " gets a new card: " << deck[0] << endl;
        p.cards_in_hand.push_back(deck[0]);
        deck.erase(deck.begin());
    }

    void Deck::recycle_card(Player & p) {
        p.cards_in_hand.clear();
    }

    void Deck::reconstruct() {
        deck.clear();
        vector<string> suit = {"club", "diamond", "spade", "heart"};
        vector<string> rank = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        for (string i: suit){
            for (string j:rank){
                deck.push_back(Card(i, j));
            }
        }

    }