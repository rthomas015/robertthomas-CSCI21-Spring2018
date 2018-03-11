#include "human.h"

using namespace std;

Human::Human () {
    
}

void Human::setPersonalMap (GameBoard Map) {
    PersonalMap_.constructBoard(Map.getGameBoard());
}

const vector<string>& Human::getPersonalMap () {
    return PersonalMap_.getGameBoard();
}

void Human::printTrackingBoardforOpponent () {
    PersonalMap_.printTrackingBoard();
}