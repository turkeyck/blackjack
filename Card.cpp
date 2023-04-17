#include <iostream>
#include <stdlib.h>
#include <vector>
// #include <bits/stdc++.h>
#include "Player.h"
#include "Card.h"
using namespace std;


    // create 52 crads
    Card::Card(string s, string r)
    {
        rank = r;
        suit = s;
        card = suit + rank;
    }


    // std::ostream is the type for object std::cout
    std::ostream& operator<< (std::ostream& out, const Card& card){
        out << card.suit << card.rank ; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
    }