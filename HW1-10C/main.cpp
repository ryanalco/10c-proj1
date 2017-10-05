#include "cards.hpp"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
    
    srand((int)time(0));
    
    Player me(100);
    
    while (me.get_money() > 0) {
        string response;
        double bet;
        cout << "You have $" << me.get_money() << ". Enter Bet: ";
        cin >> bet;
    
        
        Hand player;
        Hand dealer;
        
        Card pcard;
        player.add_card(pcard);
        
        while ((response != "n") && (player.get_total() <= 7.5)) {
            cout << "Your cards: \n" << player.show_hand() << endl;
            cout << "Your total is " << player.get_total() << ". Do you want another card (y/n)? ";
            cin >> response;
            if (response == "y") {
                Card pcard2;
                player.add_card(pcard2);
                cout << "New Card: " << pcard.get_spanish_suit() << endl;
            }
        }
    
        while (dealer.get_total() <= 5.5) {
            Card dcard;
            dealer.add_card(dcard);
            cout << "Dealer's cards: " << dealer.show_hand() << endl;
            cout << "The dealer's total is: " << dealer.get_total() << endl;
        }
            
        if ((dealer.get_total() > 7.5) || (player.get_total() > dealer.get_total())) {
            cout << "You win " << bet << endl;
            me.increase_money(bet);
        }
        else if ((dealer.get_total() > player.get_total()) || (player.get_total() > 7.5)) {
            cout << "Too bad. You lose " << bet << "." << endl;
            me.decrease_money(bet);
        }
    }
    
    return 0;
}
        
        
        
        
        
        
