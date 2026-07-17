## Theme
A dice betting game set in a valley town. You are a gambler trying to 
restore the Community Center by collecting and donating 3 bundle items 
before 7 days run out. Bet at the Casino to earn money, help characters 
at the Market to get items, and avoid relying too much on Souq shortcuts.

## Goal
Donate 3 bundle items to the Community Center before day 7 ends.

## How to compile and run
g++ main.cpp Player.cpp Item.cpp Character.cpp Dice.cpp Bet.cpp SafeBet.cpp RiskyBet.cpp -o game
./game

## How to play
- Visit Casino to bet and earn money
- Visit Market to help Yousef and Ahmed for bundle items
- Visit Community Center to donate items
- Visit Souq for shortcuts (raises Joja Influence)
- End day to restore energy

## Classes
- Player: stores name, money, energy, inventory, bundle progress
- Item: stores item name, type, value, whether it is a bundle item
- Character: stores name, location, dialogue, quest status
- Bet: base class for betting types
- SafeBet: inherits from Bet, 60% win chance, small payout
- RiskyBet: inherits from Bet, 30% win chance, big payout
- Dice: handles dice rolling

## Extra credit
None
