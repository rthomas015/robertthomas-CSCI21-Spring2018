#include "computer.h"

Computer::Computer () {
    
}

void Computer::setPersonalMap (GameBoard Map) {
    PersonalMap_.constructBoard(Map.getGameBoard());
}

const vector<string>& Computer::getPersonalMap () {
    return PersonalMap_.getGameBoard();
}

void Computer::printTrackingBoardforOpponent () {
    PersonalMap_.printTrackingBoard();
}

string Computer::checkPosition(char x, int y) {
    return PersonalMap_.checkPosition(x,y);
}