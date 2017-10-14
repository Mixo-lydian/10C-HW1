# 10C HW 1: Siete y medio

This project is a single-player version of the game "siete y medio", where the goal is to draw cards to get closest to a score of 7.5 without going over ("busting"). The player bets credits before each game, and faces an AI dealer who draws as long as their total is less than 5.5. On a win, the player receives twice their bet as a reward. On a draw, the player receives their bet back. On a loss, the player loses their bet to the dealer.

The goal of the game is to accumulate 1000+ credits, which means that the dealer must lose 900 credits. Doing so will result in a win. Reaching 0 credits will result in a loss. All games are logged in an output text file.

--- 
Files in this repo:

- [`readme.md`][read-me] This file, which explains how the game works.
- [`hw7.cpp`][main] The main file containing the necessary functions to run the game.
- [`cards.h`][header] The header file which contains the classes Player, Hand, and Card which are the building blocks for the functions in `hw7.cpp`.
- [`cards.cpp`][members] The file containing all the member functions for the classes from `cards.h`.

[read-me]: readme.md
[main]: hw7.cpp
[header]: cards.h
[members]: cards.cpp
