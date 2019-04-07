#include <iostream>
#include <array>
#include "OthelloGame.h"

using namespace std;

int main() {
	int r = 0;
	int c = 0;
	OthelloMatrix board = { 0 };
	board[3][3] = -1;
	board[3][4] = 1;
	board[4][3] = 1;
	board[4][4] = -1;

	int player = 1;
	int &currentPlayer = player;

	int skip = 0;

	while (true) {
		PrintBoard(board);

		if (currentPlayer == 1)
			cout << "Black's turn.";
		else
			cout << "White's turn.";

		//Goes here
		here:

		cout << "Please choose a move: " << endl;

		GetMove(r, c);
		
		//Check if move can be applied and reset skip if not in succession
		if (InBounds(r, c) && IsValidMove(board, r, c) && r != -1 && c != -1) {
			ApplyMove(board, r, c, currentPlayer);
			if (skip != 0)
				skip = 0;
		}
		else if (r == -1 && c == -1) {
			skip++;
		}
		else {
			cout << "Invalid move. ";
			//Go there
			goto here;
		}

		//Game end and check for winner
		if (skip == 2) {
			int total = GetValue(board);
			if (total == 0)
				cout << "Tie" << endl;
			if (total > 0)
				cout << "Black won" << endl;
			else
				cout << "White won" << endl;
			break;
		}

		//Switch player
		if (currentPlayer == 1) {
			currentPlayer = -1;
		}
		else {
			currentPlayer = 1;
		}
		
	}
}
//41 lines
