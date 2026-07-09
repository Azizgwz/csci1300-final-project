#ifndef SAFEBET_H
#define SAFEBET_H

#include "Bet.h"

class SafeBet : public Bet {
public:
    SafeBet(int amount);
    int payout(bool won);
    double winChance();
};

#endif