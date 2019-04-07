#include <iostream>
#include <array>
#include "OthelloGame.h"
using namespace std;

//Prints the board
void PrintBoard(const OthelloMatrix &board) {
	cout << "- 0 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < board.size(); i++) {
		cout << i << " ";
		for (int j = 0; j < board.size(); j++) {
			if ((int)board[i][j] == 0) {
				cout << ".";
			}
			if ((int)board[i][j] == 1) {
				cout << "B";
			}
			if ((int)board[i][j] == -1) {
				cout << "W";
			}
			cout << " ";
		}
		cout << endl;
	}
}
//12 lines

bool InBounds(int row, int col) {
	return (row <= 7 && row >= 0 && col <= 7 && col >= 0);
}
//1 line

bool IsValidMove(const OthelloMatrix &board, int row, int col) {
	if ((InBounds(row, col) && board[row][col] == 0) || (row == -1 && col == -1)) {
		return true;
	}
	return false;
}
//3 lines

void GetMove(int &row, int &col) {
	char paren1, ignore, paren2;
	cin >> paren1 >> row >> ignore >> col >> paren2;
}
//2 lines

void ApplyMove(OthelloMatrix &board, int row, int col, char currentPlayer) {
	board[row][col] = currentPlayer;

	int r = row;
	int c = col;
	int count = 0;

	//Go through all the directions
	for (int rD = -1; rD <= 1; rD++) {
		for (int cD = -1; cD <= 1; cD++) {
			//Move in that direction
			r += rD;
			c += cD;
			//While its still on the board and its an enemy piece
			while (InBounds(r, c) && board[r][c] != currentPlayer && board[r][c] != 0) {
				//Keep going that direction
				r += rD;
				c += cD;
				//Keep track of how many times moved
				count++;
				//If its on the board and it your own piece
				if (InBounds(r, c) && board[r][c] == currentPlayer) {
					//Backtrack and flip
					while (count > 0) {
						board[r -= rD][c -= cD] = currentPlayer;
						count--;
					}
				}
			}
			//Reset each time we try a new direction
			count = 0;
			r = row;
			c = col;
		}
	}
}
//19 lines

int GetValue(const OthelloMatrix &board) {
	int total = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			total += board[i][j];
		}
	}
	return total;
}
//5 lines