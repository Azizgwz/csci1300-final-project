#ifndef BET_H
#define BET_H

class Bet {
protected:
    int amount;

public:
    Bet(int amount);
    virtual int payout(bool won);
    virtual double winChance();
    int getAmount();
};

#endif