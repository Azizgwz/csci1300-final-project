#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    string name;
    int money;

public:
    Player(string name, int startingMoney);
    void addMoney(int amount);
    void subtractMoney(int amount);
    int getMoney();
    string getName();
};

#endif