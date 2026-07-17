#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string n, int startMoney, int startEnergy) {
    name = n;
    money = startMoney;
    energy = startEnergy;
    day = 1;
    currentLocation = "Casino";
    jojaInfluence = 0;
    bundleProgress = 0;
}

string Player::getName() { return name; }
int Player::getMoney() { return money; }
int Player::getEnergy() { return energy; }
int Player::getDay() { return day; }
string Player::getCurrentLocation() { return currentLocation; }
int Player::getJojaInfluence() { return jojaInfluence; }
int Player::getBundleProgress() { return bundleProgress; }

void Player::addMoney(int amount) { money += amount; }

bool Player::spendMoney(int amount) {
    if (money < amount) {
        return false;
    }
    money -= amount;
    return true;
}

void Player::addEnergy(int amount) {
    energy += amount;
    if (energy > 10) energy = 10;
}

bool Player::spendEnergy(int amount) {
    if (energy < amount) {
        return false;
    }
    energy -= amount;
    return true;
}

void Player::nextDay() {
    day++;
    energy = 10;
}

void Player::moveTo(string location) {
    currentLocation = location;
}

void Player::addItem(Item item) {
    inventory.push_back(item);
}

bool Player::hasItem(string itemName) {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i].getName() == itemName) {
            return true;
        }
    }
    return false;
}

void Player::removeItem(string itemName) {
    for (int i = 0; i < (int)inventory.size(); i++) {
        if (inventory[i].getName() == itemName) {
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
}

void Player::displayInventory() {
    if (inventory.empty()) {
        cout << "Your inventory is empty." << endl;
        return;
    }
    for (int i = 0; i < (int)inventory.size(); i++) {
        inventory[i].displayItem();
    }
}

void Player::increaseJojaInfluence() { jojaInfluence++; }
void Player::increaseBundleProgress() { bundleProgress++; }