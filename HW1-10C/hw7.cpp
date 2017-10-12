#include "cards.hpp"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


//here is some new code that is commented out so it will not change anything

int main() {
    
    //initialize the random number generator
    srand((int)time(0));
    
    Player me(100);
    
    //the game continues until player is out of money
    while (me.get_money() > 0) {
        string response;
        double bet;
        cout << "You have $" << me.get_money() << ". Enter Bet: ";
        cin >> bet;
        
        //if the player bets more money than they have to bet, they are asked to try again
        if (bet > me.get_money()) {
            cout << "You do not have that much money to bet. Enter bet again: ";
            cin >> bet;
        }
    
        //create the hands for player and dealer. No cards given yet
        Hand player;
        Hand dealer;
        
        //give first card to players hand
        Card pcard;
        player.add_card(pcard);
        
        //continue giving player cards until their response is no or their total is too high
        while ((response != "n") && (player.get_total() <= 7.5)) {
            cout << "Your cards: \n" << player.show_hand() << endl;
            cout << "Your total is " << player.get_total() << ". Do you want another card (y/n)? ";
            cin >> response;
            if (response == "y") {
                Card pcard2;
                player.add_card(pcard2);
                cout << "New Card: " << player.show_last() << endl;
            }
        }
        
        //give dealer his first card
        Card dcard;
        dealer.add_card(dcard);
        cout << "Dealer's cards: \n" << dealer.show_hand() << endl;
        cout << "The dealer's total is: " << dealer.get_total() << endl;
    
        //continue giving dealer cards while their total is less than 5.5
        while (dealer.get_total() <= 5.5) {
            Card dcard2;
            dealer.add_card(dcard2);
            cout << "New Card: " << dealer.show_last() << endl;
            cout << "Dealer's cards: \n" << dealer.show_hand() << endl;
            cout << "The dealer's total is: " << dealer.get_total() << endl;
        }
        
        //Determine if player gains or loses bet based on each possible test case
        
        if (((player.get_total() > 7.5) && (dealer.get_total() > 7.5)) || (player.get_total() == dealer.get_total())){
            cout << "Nobody wins! " << endl;
        }
        else if (player.get_total() > 7.5) {
            cout << "Too bad. You lose " << bet << "." << endl;
            me.decrease_money(bet);
        }
        else if (dealer.get_total() > 7.5) {
            cout << "You win " << bet << endl;
            me.increase_money(bet);
        }
        else if (player.get_total() > dealer.get_total()) {
            cout << "You win " << bet << endl;
            me.increase_money(bet);
        }
        else if (dealer.get_total() > player.get_total()) {
            cout << "Too bad. You lose " << bet << "." << endl;
            me.decrease_money(bet);
        }
        else {
            cout << "error";
        }
    }
    
    // game ends when player is out of money
    cout << "You have $0. GAME OVER!\nCome back when you have more money.\n\nBye! \n";
    
    return 0;
}
        
        
        
        
        
        
