#ifndef RISKYBET_H
#define RISKYBET_H

#include "Bet.h"

class RiskyBet : public Bet {
public:
    RiskyBet(int amount);
    int payout(bool won);
    double winChance();
};

#endif