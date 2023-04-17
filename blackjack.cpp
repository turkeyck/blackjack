# include <iostream>
# include <stdlib.h>
# include <vector>
# include <string>
# include <cmath>
# include "Card.h"
# include "Deck.h"
# include "Player.h"
# include "Judge.h"
using namespace std;


int main(){
    string name1;
    cout << "Please enter your name:" << endl;
    cin >> name1 ;
    Player player1(name1,100);
    Player player2("Computer",100);
    Deck poker;
    poker.shuffle();


    cout << "Hello " << name1 << endl;
    cout << "Welcome to BlackJack! You have $100 by default." << endl
        << "At the beginning of each game, you can decide how much you want to bet." << endl
        << "At the end of the game, the bet will be given to the winner." << endl
        << "If your money is less than $10, you won't be able to play anymore." << endl;
    
    while (true){

        if (player1.money < 10) {
            cout << "You have run out of money. You only have $" << player1.money << ", $10 required.";
            break;
        }

        
        // Decide the bet
        while (true) {
            int bet;
            cout << "Enter your bets:" <<endl;
            cin >> bet;
            if (cin.fail()) {
                cout << "You should enter an integer number. Please try again!" <<endl;
                cin.clear();
                cin.ignore(2048, '\n');
                continue;
            }
            else if (bet >= 10 && bet <= player1.money) {
                player1.bet = bet;
                player2.bet = bet;
                break;
            }
            
            cout << "Bets be between $10 and $" << player1.money << "." << " Please try again!" << endl;
                
            
        }


        // Deal 2 cards to each player
        if (poker.deck.size() < 20){
            poker.recycle_card(player1);
            poker.recycle_card(player2);
            
            poker.reconstruct();
            poker.shuffle();

            }
        
        poker.deal(player1);
        poker.secret_deal(player2);
        poker.deal(player1);
        poker.deal(player2);


        player1.list_cards_in_hand();
        player2.list_cards_of_computer();

        

        // Decide whether players want extra cards and judge who wins.
        while (true) {
            char hit_or_stand;
            cout << "Stand or Hit me?" << endl;
            cout <<"Press 1 for stand, 2 for hit me." << endl;
            cin >> hit_or_stand;

            if (hit_or_stand == '1'){
                while (player2.compute_score() <= 16) {
                    poker.deal(player2);
                    player2.compute_score();
                }

                
                if (judge(player2)) {
                    player1.grab_money(player2);
                    player2.list_cards_in_hand();
                    cout << "Computer's score exceeds 21, Computer loses." <<endl;
                    cout << "Computer has lost $" << player2.bet << " , $" << player2.money << " left." << endl;
                    cout << "You have won $" << player1.bet << " , $" << player1.money << " left." << endl;
                    poker.recycle_card(player1);
                    poker.recycle_card(player2);
                    
                }
                else {
                    if (player2.compute_score() == 21) {
                    player2.grab_money(player2);
                    player2.grab_money(player2);
                }
                    judge(player1, player2);
                    poker.recycle_card(player1);
                    poker.recycle_card(player2);
                }
  
                break;

            }
            else if (hit_or_stand == '2'){
                poker.deal(player1);
                player1.list_cards_in_hand();
                player2.list_cards_of_computer();
                if (judge(player1)) {
                    player2.grab_money(player1);
                    cout << "Your score exceeds 21, you lose!!!" << endl;
                    cout << player1.name << " has lost $" << player1.bet << " ,$" << player1.money << " left." << endl;
                    cout << "Computer has won $" << player2.bet << " ,$" << player2.money << " left." << endl;
                    
                    poker.recycle_card(player1);
                    poker.recycle_card(player2);
                    break;
                }
                else continue;
            }
            // cout<<player1.cards_in_hand.size()<<" !!!!!!!!!!! 4\n";
        }
        
        // Decide whether want to play again
        char play_again;
        while (true) {
            cout << "Do you want to play again? (y/n)" << endl;
            
            cin >> play_again;
            if (cin.fail()) {
                cout << "Try again. Please enter y or n.";
                continue;
            }

            else if (play_again == 'y') {
                break;
            }
            else if (play_again == 'n') {
                break;
            }
        }

        if (play_again == 'y') {
            continue;
        }
        else if (play_again == 'n') {
            break;
        }
    }
    return 0;
}