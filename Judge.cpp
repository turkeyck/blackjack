// #ifndef JUDGE_H
// #define JUDGE_H

# include "Player.h"

bool judge(Player & p) {
    // return true if p.score > 21
    int sc = p.compute_score();    
    return sc > 21;

}

void judge(Player & p, Player & q) {
    /* 
    p is default to player, q is default to dealer(Computer).
    Thus, when p=q, q wins and p loses.
    */ 
    int scp = p.compute_score();
    int scq = q.compute_score();

    if (scp > scq){
        p.list_cards_in_hand();
        q.list_cards_in_hand();
        p.grab_money(q);
        cout << p.name << " win, " << q.name << " lose." << endl;
        cout << p.name << " has won $" << p.bet << ", $" << p.money << " left." << endl;
        cout << q.name << " has lost $" << q.bet << ", $" << q.money << " left." << endl;
    }

    else if (scp < scq){
        p.list_cards_in_hand();
        q.list_cards_in_hand();
        q.grab_money(p);
        cout << q.name << " win, " << p.name << " lose." << endl;
        cout << q.name << " has won $" << q.bet << ", $" << q.money << " left." << endl;
        cout << p.name << " has lost $" << p.bet << ", $" << p.money << " left." << endl;
    }

    else if (scp == scq){
        p.list_cards_in_hand();
        q.list_cards_in_hand();
        q.grab_money(p);
        cout << "You have the same scores with Computer." << endl;
        cout << p.name << " still lost $" << p.bet << ", $" << p.money << " left." << endl;
        cout << q.name << " has won $" << q.bet << ", $" << q.money << " left." << endl;
    }

}