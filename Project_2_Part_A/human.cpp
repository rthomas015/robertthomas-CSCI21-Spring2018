//Human Class
/*There is nothing yet that needs to be handled by the human class. Since we shouldn't have input and output
 * inside the class we cant query the user for attack moves from the class, and since we have no ship placement 
 * functions to build yet there's nothing for the class to do, that wouldn't be handled by the player base class
 * functions.
 * A function figuring out if a move is valid or not should be contained within the GameBoard class, this information is
 * logically connected to the GameBoard itself.
*/

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