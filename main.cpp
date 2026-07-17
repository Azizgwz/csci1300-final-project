#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Character.h"
#include "SafeBet.h"
#include "RiskyBet.h"
#include "Dice.h"
using namespace std;

// display dashboard
void displayDashboard(Player player) {
    cout << "\n==================================================" << endl;
    cout << "           THE FINAL BET" << endl;
    cout << "==================================================" << endl;
    cout << "Day: " << player.getDay() << " / 7";
    cout << "  Energy: " << player.getEnergy() << " / 10";
    cout << "  Money: $" << player.getMoney() << endl;
    cout << "Joja Influence: " << player.getJojaInfluence() << endl;
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << "Bundle Progress: " << player.getBundleProgress() << " / 3 items donated" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Map:" << endl;
    cout << "  [Casino] -- [Market] -- [Community Center]" << endl;
    cout << "                |" << endl;
    cout << "             [Souq]" << endl;
    cout << "  * You are at: " << player.getCurrentLocation() << endl;
    cout << "--------------------------------------------------" << endl;
}

// casino betting
void visitCasino(Player &player, Dice &dice) {
    cout << "\nWelcome to the Casino!" << endl;
    cout << "Dealer says: \"Place your bets! Try your luck!\"" << endl;

    if (!player.spendEnergy(2)) {
        cout << "Not enough energy to bet!" << endl;
        return;
    }

    int choice;
    cout << "1. Safe Bet (60% win, +half bet)" << endl;
    cout << "2. Risky Bet (30% win, +double bet)" << endl;
    cout << "0. Leave" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 0) return;

    int betAmount;
    cout << "Enter bet amount (1-" << player.getMoney() << "): ";
    cin >> betAmount;

    if (betAmount < 1 || betAmount > player.getMoney()) {
        cout << "Invalid bet amount." << endl;
        return;
    }

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
        player.addMoney(result);
    }
}

// market
void visitMarket(Player &player, vector<Character> &characters) {
    cout << "\nWelcome to the Market!" << endl;

    for (int i = 0; i < (int)characters.size(); i++) {
        if (characters[i].getLocation() == "Market") {
            characters[i].talk();
            if (!characters[i].isQuestCompleted()) {
                cout << "1. Help " << characters[i].getName() << " (costs 2 energy, get bundle item)" << endl;
                cout << "2. Leave" << endl;
                int choice;
                cout << "Choice: ";
                cin >> choice;
                if (choice == 1) {
                    if (player.spendEnergy(2)) {
                        Item reward = characters[i].giveReward();
                        player.addItem(reward);
                        characters[i].completeQuest();
                        cout << "You helped " << characters[i].getName() << " and received: " << reward.getName() << "!" << endl;
                    } else {
                        cout << "Not enough energy!" << endl;
                    }
                }
            } else {
                cout << characters[i].getName() << " has nothing more for you." << endl;
            }
        }
    }
}

// community center
void visitCommunityCenter(Player &player) {
    cout << "\nWelcome to the Community Center!" << endl;
    cout << "Ali says: \"Donate bundle items to restore the Community Center!\"" << endl;
    cout << "Bundle Progress: " << player.getBundleProgress() << " / 3" << endl;

    cout << "Your inventory:" << endl;
    player.displayInventory();

    string bundleItems[] = {"Coin", "Card", "Chip"};
    for (int i = 0; i < 3; i++) {
        if (player.hasItem(bundleItems[i])) {
            cout << "Donate " << bundleItems[i] << "? (1=Yes, 2=No): ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                player.removeItem(bundleItems[i]);
                player.increaseBundleProgress();
                cout << "Donated " << bundleItems[i] << "! Bundle Progress: " << player.getBundleProgress() << " / 3" << endl;
            }
        }
    }
}

// souq
void visitSouq(Player &player) {
    cout << "\nWelcome to Souq!" << endl;
    cout << "Rayan says: \"Why struggle? Let us make it easy... for a price.\"" << endl;
    cout << "1. Buy Coin (bundle item) - $75 (Joja Influence +1)" << endl;
    cout << "2. Buy Energy Drink - $30, +3 energy (Joja Influence +1)" << endl;
    cout << "3. Leave" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        if (player.spendMoney(75)) {
            player.addItem(Item("Coin", "Bundle Item", 50, true));
            player.increaseJojaInfluence();
            cout << "Bought Coin! Joja Influence increased." << endl;
        } else {
            cout << "Not enough money!" << endl;
        }
    } else if (choice == 2) {
        if (player.spendMoney(30)) {
            player.addEnergy(3);
            player.increaseJojaInfluence();
            cout << "Bought Energy Drink! +3 energy. Joja Influence increased." << endl;
        } else {
            cout << "Not enough money!" << endl;
        }
    }
}

// move player
void movePlayer(Player &player) {
    cout << "\nWhere would you like to go?" << endl;
    cout << "1. Casino" << endl;
    cout << "2. Market" << endl;
    cout << "3. Community Center" << endl;
    cout << "4. Souq" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) player.moveTo("Casino");
    else if (choice == 2) player.moveTo("Market");
    else if (choice == 3) player.moveTo("Community Center");
    else if (choice == 4) player.moveTo("Souq");
    else cout << "Invalid choice." << endl;
}

int main() {
    srand(time(0));

    // read config
    int startMoney = 100;
    int startEnergy = 10;
    ifstream configFile("config.txt");
    if (configFile.is_open()) {
        configFile >> startMoney;
        configFile >> startEnergy;
        configFile.close();
    }

    // setup
    cout << "Welcome to The Final Bet!" << endl;
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    Player player(playerName, startMoney, startEnergy);
    Dice dice;

    // characters
    vector<Character> characters;
    characters.push_back(Character("Yousef", "Market", "Help me stock the shelves and I'll give you something useful for the bundle!"));
    characters.push_back(Character("Ahmed", "Market", "I found something at the docks. Help me out and it's yours!"));
    characters.push_back(Character("Ali", "Community Center", "The Community Center needs 3 items to be restored. Please help!"));
    characters.push_back(Character("Rayan", "Souq", "Souq is here to help... for the right price."));

    // game loop
    int choice = -1;
    while (player.getDay() <= 7 && player.getMoney() > 0 && player.getBundleProgress() < 3) {
        displayDashboard(player);

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Go to current location" << endl;
        cout << "2. Move to another location" << endl;
        cout << "3. View inventory" << endl;
        cout << "4. End day" << endl;
        cout << "0. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "You quit the game." << endl;
            return 0;
        } else if (choice == 1) {
            string loc = player.getCurrentLocation();
            if (loc == "Casino") {
                visitCasino(player, dice);
            } else if (loc == "Market") {
                visitMarket(player, characters);
            } else if (loc == "Community Center") {
                visitCommunityCenter(player);
            } else if (loc == "Souq") {
                visitSouq(player);
            }
        } else if (choice == 2) {
            movePlayer(player);
        } else if (choice == 3) {
            cout << "\nInventory:" << endl;
            player.displayInventory();
        } else if (choice == 4) {
            player.nextDay();
            cout << "Day ended. New day: " << player.getDay() << endl;
        }

        if (player.getMoney() <= 0) {
            cout << "\nYou ran out of money! Game over." << endl;
            return 0;
        }
    }

    // ending
    cout << "\n==================================================" << endl;
    cout << "GAME OVER" << endl;
    cout << "==================================================" << endl;

    if (player.getBundleProgress() >= 3) {
        if (player.getJojaInfluence() == 0) {
            cout << "COMMUNITY HERO ENDING!" << endl;
            cout << "You restored the Community Center without shortcuts!" << endl;
        } else if (player.getJojaInfluence() <= 2) {
            cout << "QUIET RESTORATION ENDING!" << endl;
            cout << "The Community Center is restored, but Souq had some influence." << endl;
        } else {
            cout << "SOUQ ENDING!" << endl;
            cout << "The bundle is complete, but Souq now has power in the valley." << endl;
        }
    } else {
        cout << "SEASON OVER ENDING!" << endl;
        cout << "You ran out of time. The Community Center remains incomplete." << endl;
    }

    cout << "Final money: $" << player.getMoney() << endl;
    cout << "Bundle Progress: " << player.getBundleProgress() << " / 3" << endl;
    cout << "Joja Influence: " << player.getJojaInfluence() << endl;

    return 0;
}