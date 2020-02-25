#include "OthelloBoard.h"

using namespace std;

OthelloBoard::OthelloBoard() : mCurrentValue(0), mCurrentPlayer(Player::BLACK), mBoard() {
	mBoard[3][3] = Player::WHITE;
	mBoard[4][4] = Player::WHITE;
	mBoard[3][4] = Player::BLACK;
	mBoard[4][3] = Player::BLACK;
}

std::vector<std::unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {
	vector<unique_ptr<OthelloMove>> moves;
	//for loops to gets moves starting from front of board
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			//check in each direction
			for (BoardDirection direction : BoardDirection::CARDINAL_DIRECTIONS) {
				BoardPosition p = BoardPosition(i, j);
				//If not inbounds, look somewhere else
				if (!InBounds(p + direction)) {
					continue;
				}
				if (GetPlayerAtPosition(p) == Player::EMPTY && PositionIsEnemy(p + direction, mCurrentPlayer)) {
					//while loop to keep going in that direction if there are enemies
					p = p + direction;
					while (InBounds(p) && PositionIsEnemy(p, mCurrentPlayer)) {
						if (!InBounds(p + direction)) {
							break;
						}
						p = p + direction;
					}
					//If you find yourself after enemies, add to vector
					if (InBounds(p) && GetPlayerAtPosition(p) == mCurrentPlayer) {
						moves.push_back(make_unique<OthelloMove>(BoardPosition(i, j)));
						break;
					}
				}
			}
		}
	}
	return moves;
}

void OthelloBoard::ApplyMove(std::unique_ptr<OthelloMove> m) {
	//check in all directions
	if (!m->IsPass()) {
		for (BoardDirection direction : BoardDirection::CARDINAL_DIRECTIONS) {
			int count = 0;
			BoardPosition p = m->mPosition;
			//keep counting how many enemies are there
			p = p + direction;
			while (InBounds(p) && PositionIsEnemy(p, mCurrentPlayer)) {
				count++;
				p = p + direction;
			}
			//if inbounds, is the current player, and not a pass
			if (InBounds(p) && GetPlayerAtPosition(p) == mCurrentPlayer && !(m->IsPass())) {
				//add the flip
				m->AddFlipSet(OthelloMove::FlipSet((int)count, direction));
				while (count >= 0) {
					//move back
					p = p - direction;
					//(condition) ? (if_true) : (if_false)
					mCurrentValue += PositionIsEnemy(p, mCurrentPlayer) ? (int)mCurrentPlayer * 2 : 0;
					//put your move on the board
					mBoard[p.getRow()][p.getCol()] = mCurrentPlayer;
					count--;
				}
			}
		}
		//(condition) ? (if_true) : (if_false)
		mCurrentValue += (!m->IsPass() ? (int)mCurrentPlayer : 0);
	}
	//Add the move to history
	mHistory.push_back(move(m));
	//Switch Player
	mCurrentPlayer = (mCurrentPlayer == Player::WHITE ? Player::BLACK : Player::WHITE);
}

void OthelloBoard::UndoLastMove() {
	//this is the last move made
	auto last = move(mHistory.back());
	BoardPosition p = last->mPosition;
	//only do this if the move is not a pass
	if (!last->IsPass()) {
		//set that spot to empty
		mBoard[p.getRow()][p.getCol()] = Player::EMPTY;
		//Update value with whoever undid
		mCurrentValue += (int)mCurrentPlayer;
		int r = p.getRow();
		int c = p.getCol();
		for (OthelloMove::FlipSet flip : last->mFlips) {
			for (int i = 0; i < flip.mFlipCount; i++) {
				r += flip.mDirection.getRowChange();
				c += flip.mDirection.getColChange();
				mBoard[r][c] = mCurrentPlayer;
				mCurrentValue += (int)mCurrentPlayer + (int)mCurrentPlayer;
			}
		}
	}
	//remove from history
	mHistory.pop_back();
	//Switch Player
	mCurrentPlayer = (mCurrentPlayer == Player::WHITE ? Player::BLACK : Player::WHITE);
}