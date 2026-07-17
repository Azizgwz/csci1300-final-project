#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Item.h"
using namespace std;

class Character {
private:
    string name;
    string location;
    string dialogue;
    bool questCompleted;

public:
    Character(string n, string loc, string dia);
    string getName();
    string getLocation();
    bool isQuestCompleted();
    void completeQuest();
    void talk();
    Item giveReward();
};

#endif