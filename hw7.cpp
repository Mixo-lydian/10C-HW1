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


// Stub for main
int main() {
	Player player(100);
	Hand playerHand;
	Hand dealerHand;
	bool keepPlaying = true;
	while (keepPlaying) {
		int bet = 0;
		string draw = "";
		cout << "You have " << player.get_money() << " credits. Bet how many?: ";
		bool askForBet = true;
		bool askForDraw = true;
		while (askForBet) {
			cin >> bet;
			if (bet > player.get_money() || bet < 0 || bet == 0) cout << "Invalid bet. Enter another bet: ";
			else askForBet = false;
		}
		player.update_money(-1 * bet);
		while (askForDraw) {
			cout << "Your hand:" << endl << playerHand.printHand() << endl;
			cout << "Total: " << playerHand.calcValue() << ". Draw another? (Y/N): ";
			cin >> draw;
			if (draw == "Y" || draw == "y") playerHand.draw();
			else if (draw == "N" || draw == "n") askForDraw = false;
			else {
				cout << "That's being treated as a no." << endl;
				askForDraw = false;
			}
		}

	}
	return 0;
}