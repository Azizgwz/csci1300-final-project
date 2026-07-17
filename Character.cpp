#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(string n, string loc, string dia) {
    name = n;
    location = loc;
    dialogue = dia;
    questCompleted = false;
}

string Character::getName() { return name; }
string Character::getLocation() { return location; }
bool Character::isQuestCompleted() { return questCompleted; }
void Character::completeQuest() { questCompleted = true; }

void Character::talk() {
    cout << name << " says: \"" << dialogue << "\"" << endl;
}

Item Character::giveReward() {
    if (name == "Yousef") {
        return Item("Coin", "Bundle Item", 50, true);
    } else if (name == "Ahmed") {
        return Item("Card", "Bundle Item", 75, true);
    } else if (name == "Ali") {
        return Item("Chip", "Bundle Item", 100, true);
    }
    return Item("Trophy", "Bundle Item", 150, true);
}