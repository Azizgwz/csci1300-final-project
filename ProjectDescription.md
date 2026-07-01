# CSCI 1300 Final Project — Project Description

## Theme
A simple dice betting game. The player starts with money, bets on dice rolls, and tries to reach a target amount before running out of turns or going broke.

## Planned Classes
- Player — tracks money and bet history
- Dice — handles rolling and randomness
- Game — controls the main loop, turn counter, and win/lose checks

## Limited Resource
Money. The player starts with a fixed amount (e.g. $100) and loses if it hits $0.

## Plan for Handling Time
The game is turn-based. Each turn the player places a bet, rolls the dice, and the result updates their money. The game ends after a fixed number of turns (e.g. 20) or when the player runs out of money.

## Extra Credit
None planned for checkpoint 1.

## Tradeoff System
The player can choose a Safe Bet (low risk, small payout, higher odds of winning) or a Risky Bet (high risk, big payout, lower odds of winning). This creates a tradeoff between steady small gains and risky big gains.

## Mapping Style
No map needed — this is a text-based, turn-driven game with no grid or physical space.

## Win/Lose Condition
Win: reach a target amount of money (e.g. $500) before turns run out.
Lose: money hits $0 at any point, or turns run out below the target.
