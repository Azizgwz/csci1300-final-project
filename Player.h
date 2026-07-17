#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Player {
private:
    string name;
    int money;
    int energy;
    int day;
    string currentLocation;
    vector<Item> inventory;
    int jojaInfluence;
    int bundleProgress;

public:
    Player(string n, int startMoney, int startEnergy);
    string getName();
    int getMoney();
    int getEnergy();
    int getDay();
    string getCurrentLocation();
    int getJojaInfluence();
    int getBundleProgress();
    void addMoney(int amount);
    bool spendMoney(int amount);
    void addEnergy(int amount);
    bool spendEnergy(int amount);
    void nextDay();
    void moveTo(string location);
    void addItem(Item item);
    bool hasItem(string itemName);
    void removeItem(string itemName);
    void displayInventory();
    void increaseJojaInfluence();
    void increaseBundleProgress();
};

#endif