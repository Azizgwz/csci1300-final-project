#include "RiskyBet.h"

RiskyBet::RiskyBet(int a) : Bet(a) {
}

int RiskyBet::payout(bool won) {
    if (won) {
        return getAmount() * 2; // big payout
    }
    return -getAmount();
}

double RiskyBet::winChance() {
    return 0.3; // lower odds
}