#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

void outputRound(ostream& o, const int& gameCounter, const Player& player, const int& bet, Hand playerHand, Hand dealerHand) {
	o << "-----------------------------------------------" << endl << endl;
	o << "Game number: " << gameCounter << "\tCredits left: " << player.get_money() << endl;
	o << "You bet: " << bet << " credits" << endl << endl;
	o << "Your cards:" << endl;
	playerHand.printHand(o);
	o << "Your total: " << playerHand.calcValue() << endl << endl;
	o << "Dealer's cards:" << endl;
	dealerHand.printHand(o);
	o << "Dealer's total: " << dealerHand.calcValue() << endl << endl;
	return;
}

void playerTurn(Hand& hand) {
	bool askForDraw = true;
	while (askForDraw) {
		string draw = "";
		cout << "Your hand:" << endl;
		hand.printHand(cout);
		cout << "Total: " << hand.calcValue() << ". Draw another? (Y/N): ";
		cin >> draw;
		cout << endl;
		if (draw == "Y" || draw == "y") hand.draw();
		else if (draw == "N" || draw == "n") askForDraw = false;
		else {
			cout << "That's being treated as a no." << endl;
			askForDraw = false;
		}
		if (hand.calcValue() >= 7.5) {
			cout << "Your final hand:" << endl;
			hand.printHand(cout);
			cout << "Total: " << hand.calcValue() << endl << endl;
			askForDraw = false;
		}
	}
	return;
}

void dealerTurn(Hand& hand) {
	bool askForDraw = true;
	while (askForDraw) {
		cout << "Dealer's hand:" << endl;
		hand.printHand(cout);
		cout << "Total: " << hand.calcValue() << "." << endl << endl;
		if (hand.calcValue() < 5.5) hand.draw();
		else askForDraw = false;
	}
	return;
}

// Stub for main
int main() {
	Player player(100);
	ofstream fout;
	fout.open("gamelog.txt");
	bool keepPlaying = true;
	int gameCounter = 0;
	while (keepPlaying) {
		gameCounter++;
		Hand playerHand;
		Hand dealerHand;
		int bet = 0;
		cout << "You have " << player.get_money() << " credits. Bet how many?: ";
		bool askForBet = true;
		bool askForDraw = true;
		while (askForBet) {
			cin >> bet;
			if (bet > player.get_money() || bet < 0 || bet == 0) cout << "Invalid bet. Enter another bet: ";
			else askForBet = false;
		}
		player.update_money(-1 * bet);
		playerTurn(playerHand);
		dealerTurn(dealerHand);
		if (playerHand.calcValue() > 7.5 || (playerHand.calcValue() < dealerHand.calcValue() && dealerHand.calcValue() <= 7.5)) {
			cout << "You lost! Too bad." << endl << endl;
		}
		else if (playerHand.calcValue() > dealerHand.calcValue() || dealerHand.calcValue() > 7.5) {
			cout << "You won! You gained " << bet << " credits." << endl << endl;
			player.update_money(2 * bet);
		}
		else if (playerHand.calcValue() == dealerHand.calcValue()) {
			cout << "A draw! No one wins." << endl << endl;
		}
		if (player.get_money() == 0) {
			keepPlaying = false;
			cout << "You have lost all of your credits. Game over!" << endl;
		}
		else if (player.get_money() >= 1000) {
			keepPlaying = false;
			cout << "You have reached a credit count of 1000 or more. You win!" << endl;
		}
		outputRound(fout, gameCounter, player, bet, playerHand, dealerHand);
	}
	fout.close();
	return 0;
}