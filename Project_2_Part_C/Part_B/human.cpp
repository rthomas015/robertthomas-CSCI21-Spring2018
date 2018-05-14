#include "human.h"

using namespace std;

Human::Human () {
    //runs Gameboard constructor and sets the map to empty
}

void Human::setPersonalMap (GameBoard Map) {
    PersonalMap_.constructBoard(Map.getGameBoard());
}

const vector<string>& Human::getPersonalMap () {
    return PersonalMap_.getGameBoard();
}

void Human::printWholeBoard () {
    PersonalMap_.printBoard();
}

void Human::printTrackingBoardforOpponent () {
    PersonalMap_.printTrackingBoard();
}

string Human::checkPosition(char x, int y) {
    return PersonalMap_.checkPosition(x,y);
}