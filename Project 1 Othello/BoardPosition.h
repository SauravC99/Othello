#pragma once
#include <iostream>
#include <vector>
#include "BoardDirection.h"

class BoardPosition {
public:
	//Constructors
	BoardPosition();
	BoardPosition(char row, char col);

	//Accessors/Getters
	//inline means it is defined in this line, not in cpp file
	//the const after names means it is able to be used on a const function
	inline int getRow() const { return mR; }
	inline int getCol() const { return mC; }

	//Operators
	operator std::string() const; //toString
	friend std::istream& operator>>(std::istream& lhs, BoardPosition& rhs);
	bool operator==(BoardPosition rhs);
	bool operator<(BoardPosition rhs);

	//Member Methods
	bool InBounds(int boardSize);
	bool InBounds(int rows, int columns);
	static std::vector<BoardPosition> GetRectangularPositions(int rows, int columns);

	//One more operator
	BoardPosition operator+(BoardDirection dir);
	BoardPosition operator-(BoardDirection dir);

private:
	//Instance variables
	char mR, mC;
};

std::ostream& operator<<(std::ostream& lhs, const BoardPosition rhs);

