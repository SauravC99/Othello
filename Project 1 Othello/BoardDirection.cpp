#include "BoardDirection.h"
#include <array>

using namespace std;

BoardDirection::BoardDirection() : mRowDir(0), mColDir(0) {
}

BoardDirection::BoardDirection(char row, char col) : mRowDir(row), mColDir(col) {
}

array<BoardDirection, 8> BoardDirection::CARDINAL_DIRECTIONS = {
	BoardDirection(-1, 0), //up
	BoardDirection(-1, 1), //up right
	BoardDirection(0, 1), //right
	BoardDirection(1, 1), //down right
	BoardDirection(1, 0), //down
	BoardDirection(1, -1), //down left
	BoardDirection(0, -1), //left
	BoardDirection(-1, -1) //up left
};