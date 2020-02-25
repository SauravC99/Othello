#include "OthelloMove.h"
#include "BoardPosition.h"
#include <sstream>

using namespace std;

bool OthelloMove::operator==(const OthelloMove& rhs) {
	return(mPosition == rhs.mPosition);
}

OthelloMove::operator std::string() const {
	ostringstream os;
	os << mPosition;
	return os.str();
	//Does not work
	//return static_cast<string>(mPosition);
}