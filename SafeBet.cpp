#include "SafeBet.h"

SafeBet::SafeBet(int a) : Bet(a) {
}

int SafeBet::payout(bool won) {
    if (won) {
        return getAmount() / 2; // small payout
    }
    return -getAmount();
}

double SafeBet::winChance() {
    return 0.6; // higher odds
}