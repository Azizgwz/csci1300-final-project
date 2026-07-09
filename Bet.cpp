#include "Bet.h"

Bet::Bet(int a) {
    amount = a;
}

int Bet::payout(bool won) {
    // base class placeholder, overridden by derived classes
    return 0;
}

double Bet::winChance() {
    // base class placeholder, overridden by derived classes
    return 0.0;
}

int Bet::getAmount() {
    return amount;
}