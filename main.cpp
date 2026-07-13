#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"
#include "Dice.h"
#include "SafeBet.h"
#include "RiskyBet.h"
using namespace std;

int main() {
    srand(time(0));

    // read config from file
    int startingMoney = 100;
    int targetMoney = 500;
    int maxTurns = 20;

    ifstream configFile("config.txt");
    if (configFile.is_open()) {
        configFile >> startingMoney;
        configFile >> targetMoney;
        configFile >> maxTurns;
        configFile.close();
    } else {
        cout << "Could not open config.txt, using default settings." << endl;
    }

    // setup
    string playerName;
    cout << "Welcome to the Dice Betting Game!" << endl;
    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName, startingMoney);
    Dice dice;

    cout << "\nGoal: reach $" << targetMoney << " in " << maxTurns << " turns." << endl;
    cout << "Starting money: $" << startingMoney << endl;

    int turnsLeft = maxTurns;
    int choice = -1;

    // game loop
    while (turnsLeft > 0 && player.getMoney() > 0 && player.getMoney() < targetMoney) {
        cout << "\n--- Turn " << (maxTurns - turnsLeft + 1) << " of " << maxTurns << " ---" << endl;
        cout << "Money: $" << player.getMoney() << endl;
        cout << "Turns left: " << turnsLeft << endl;
        cout << "\n1. Safe Bet (60% win chance, win = +half your bet, lose = -your bet)" << endl;
        cout << "2. Risky Bet (30% win chance, win = +double your bet, lose = -your bet)" << endl;
        cout << "0. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "You quit the game." << endl;
            return 0;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice, try again." << endl;
            continue;
        }

        // get bet amount
        int betAmount;
        cout << "Enter bet amount (1 - " << player.getMoney() << "): ";
        cin >> betAmount;

        if (betAmount < 1 || betAmount > player.getMoney()) {
            cout << "Invalid bet amount, skipping turn." << endl;
            turnsLeft--;
            continue;
        }

        // roll dice and determine win
        int roll = dice.roll();
        cout << "You rolled: " << roll << endl;

        bool won;
        int result;

        if (choice == 1) {
            SafeBet bet(betAmount);
            won = ((double)rand() / RAND_MAX) < bet.winChance();
            result = bet.payout(won);
        } else {
            RiskyBet bet(betAmount);
            won = ((double)rand() / RAND_MAX) < bet.winChance();
            result = bet.payout(won);
        }

        if (won) {
            cout << "You won! +" << result << endl;
            player.addMoney(result);
        } else {
            cout << "You lost! " << result << endl;
            player.addMoney(result); // result is negative
        }

        cout << "Money now: $" << player.getMoney() << endl;
        turnsLeft--;
    }

    // win/lose condition
    cout << "\n--- Game Over ---" << endl;
    if (player.getMoney() >= targetMoney) {
        cout << "You won! You reached $" << targetMoney << "!" << endl;
    } else if (player.getMoney() <= 0) {
        cout << "You lost! You ran out of money." << endl;
    } else {
        cout << "You ran out of turns. Final money: $" << player.getMoney() << endl;
        if (player.getMoney() >= targetMoney) {
            cout << "You won!" << endl;
        } else {
            cout << "You didn't reach the goal. Better luck next time!" << endl;
        }
    }

    return 0;
}