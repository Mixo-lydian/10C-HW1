#include <iostream>
#include <vector>
#include <string>

#ifndef CARDS_H
#define CARDS_H

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

using namespace std;

class Card {
public:
	Card();
	string get_spanish_suit() const;
	string get_spanish_rank() const;
	string get_english_suit() const;
	string get_english_rank() const;
	int get_rank() const;
	bool operator < (Card card2) const;
private:
	suit_t suit;
	rank_t rank;
};

class Hand {
public:
	Hand();
	void draw();
	double calcValue() const;
	void printHand();
private:
	vector<Card> v;
};

class Player {
public:
	Player(int m);
	void update_money(int change);
	int get_money() const;
private:
	int money;
};

#endif