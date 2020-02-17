#include "BoardPosition.h"
#include <sstream>
#include "BoardDirection.h"

using namespace std;

BoardPosition::BoardPosition() : mR(0), mC(0) {
}

BoardPosition::BoardPosition(char row, char col) : mR(row), mC(col) {
}

BoardPosition::operator std::string() const {
	ostringstream os;
	os << "(" << mR << ", " << mC << ")";
	return os.str();
}

ostream& operator<<(ostream& lhs, BoardPosition rhs) {
	lhs << "(" << (int)rhs.getRow() << ", " << (int)rhs.getCol() << ")";
	return lhs;
}

istream& operator>>(istream& lhs, BoardPosition& rhs) {
	char firstParen, ignore, secondParen;
	int row, col;
	lhs >> firstParen >> row >> ignore >> col >> secondParen;
	rhs.mR = row;
	rhs.mC = col;
	return lhs;
}

bool BoardPosition::operator==(BoardPosition rhs) {
	return ((mR == rhs.mR) && (mC == rhs.mC));
}

bool BoardPosition::operator<(BoardPosition rhs) {
	if (mR < rhs.mR)
		return true;
	if (mR == rhs.mR && mC < rhs.mC)
		return true;
	else
		return false;
}

bool BoardPosition::InBounds(int boardSize) {
	return ((mR >= 0 && mR <= boardSize - 1) && (mC >= 0 && mC <= boardSize - 1));
}

bool BoardPosition::InBounds(int rows, int columns) {
	return ((mR >= 0 && mR <= rows - 1) && (mC >= 0 && mC <= columns - 1));
}

vector<BoardPosition> BoardPosition::GetRectangularPositions(int rows, int columns) {
	vector<BoardPosition> board;

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++) {
			board.push_back(BoardPosition(r, c));
		}
	}

	return board;
}

BoardPosition BoardPosition::operator+(BoardDirection dir) {
	return BoardPosition(mR + dir.getRowChange(), mC + dir.getColChange());
}

BoardPosition BoardPosition::operator-(BoardDirection dir) {
	return BoardPosition(mR - dir.getRowChange(), mC - dir.getColChange());
}