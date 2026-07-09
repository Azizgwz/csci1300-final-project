#include "Dice.h"
#include <cstdlib>

Dice::Dice() {
}

int Dice::roll() {
    return (rand() % 6) + 1; // 1-6
}