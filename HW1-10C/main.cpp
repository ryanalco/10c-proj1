#include "cards.hpp"
#include <iostream>
using namespace std;

int main() {
    
    
    Player me(100);
    
    while (me.get_money() > 0) {
        string response;
        double bet;
        cout << "You have $" << me.get_money() << ". Enter Bet: \n";
        cin >> bet;
        
        Hand player;
        Hand dealer;
        
        
        Card pcard;
        player.add_card(pcard);
        
        while (response != "n") {
            cout << "Your cards: \n" << player.show_hand() << endl;
            cout << "Your total is " << player.get_total() << "Do you want another card (y/n)?";
            cin >> response;
            if (response == "y") {
                Card pcard2;
                player.add_card(pcard2);
                cout << "New Card: " << pcard.get_spanish_suit() << endl;
            }
    
        //if (response == "n") {
        while (dealer.get_total() <= 5.5) {
            Card dcard;
            dealer.add_card(dcard);
            cout << "Dealer's cards: " << dealer.show_hand() << endl;
            cout << "The dealer's total is: " << dealer.get_total() << endl;
        }
        
    return 0;
}
