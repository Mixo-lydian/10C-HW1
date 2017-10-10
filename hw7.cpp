#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)

// Non member functions declarations (if any)


// Non member functions implementations (if any)
void playerTurn(Hand& hand) {
	bool askForDraw = true;
	while (askForDraw) {
		string draw = "";
		cout << "Your hand:" << endl;
		hand.printHand();
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
			hand.printHand();
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
		hand.printHand();
		cout << "Total: " << hand.calcValue() << "." << endl << endl;
		if (hand.calcValue() < 5.5) hand.draw();
		else askForDraw = false;
	}
	return;
}

// Stub for main
int main() {
	Player player(100);
	bool keepPlaying = true;
	while (keepPlaying) {
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
	}
	return 0;
}