#include "Player.h"

Player::Player(string n, int startingMoney) {
    name = n;
    money = startingMoney;
}

void Player::addMoney(int amount) {
    money += amount;
}

void Player::subtractMoney(int amount) {
    money -= amount;
}

int Player::getMoney() {
    return money;
}

string Player::getName() {
    return name;
}