#include "cards.hpp"
#include <iostream>
using namespace std;

int main() {
    
    
    Player me(100);
    
    while (me.get_money() > 0) {
        double bet;
        cout << "You have $" << me.get_money() << ". Enter Bet: /n";
        cin >> bet;
        
        Hand player;
        Hand dealer;
        
        Card playercard;
        player.add_card(playercard);
        
        cout << "Your cards: /n" << player.show_hand();
        
        
    }
    return 0;
}
