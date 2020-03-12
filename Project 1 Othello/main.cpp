//Saurav Chhapawala

#include "OthelloBoard.h"
//#include "OthelloGame.h"
#include "OthelloMove.h"
#include "OthelloView.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
	// Initialization
	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice
	unique_ptr<OthelloMove> m;
	int pass;
}