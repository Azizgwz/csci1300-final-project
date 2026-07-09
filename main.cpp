#include <iostream>
#include "Player.h"
#include "Dice.h"
#include "SafeBet.h"
#include "RiskyBet.h"
using namespace std;

int main() {
    Player player("Player1", 100);
    Dice dice;

    int choice = -1;

    while (choice != 0) {
        cout << "\n--- Dice Betting Game ---" << endl;
        cout << "Money: " << player.getMoney() << endl;
        cout << "1. Place Safe Bet" << endl;
        cout << "2. Place Risky Bet" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Safe bet placeholder - not implemented yet" << endl;
        } else if (choice == 2) {
            cout << "Risky bet placeholder - not implemented yet" << endl;
        } else if (choice != 0) {
            cout << "Invalid choice." << endl;
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}