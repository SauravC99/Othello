#pragma once
#include <array>

class BoardDirection {
public:
	//Constructors
	BoardDirection();
	BoardDirection(char row, char col);

	//Accessors/Getters
	inline const int getRowChange() { return mRowDir; }
	inline const int getColChange() { return mColDir; }

	static std::array<BoardDirection, 8> CARDINAL_DIRECTIONS;

private:
	//Instance variables
	char mRowDir, mColDir;
};