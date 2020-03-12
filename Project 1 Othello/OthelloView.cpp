#include "OthelloView.h"
#include <sstream>

using namespace std;

void OthelloView::PrintBoard(std::ostream& s) const {
	s << "- 0 1 2 3 4 5 6 7" << endl;
	for (int i = 0; i < mOthelloBoard->BOARD_SIZE; i++) {
		s << i << " ";
		for (int j = 0; j < mOthelloBoard->BOARD_SIZE; j++) {
			if (mOthelloBoard->mBoard[i][j] == OthelloBoard::Player::EMPTY) {
				s << ".";
			}
			if (mOthelloBoard->mBoard[i][j] == OthelloBoard::Player::BLACK) {
				s << "B";
			}
			if (mOthelloBoard->mBoard[i][j] == OthelloBoard::Player::WHITE) {
				s << "W";
			}
			s << " ";
		}
		s << endl;
	}
}