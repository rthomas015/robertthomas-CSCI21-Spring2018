#include "computer.h"

Computer::Computer () {
    //runs Gameboard constructor and sets the map to empty
    LastAttack_ = "Miss";
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

string Computer::attackPosition (Human &humanplayer) {
    char x;
    int y = 0;
    //come up with a position
    if (LastAttack_ == "Miss") {
        //random number 0-99
        srand(time(0));
        y = (rand() % 10);
        x = (rand() % 10) + 65;
        //then test number to see if already picked
    }
    else if (LastAttack_ == "Hit") {
        //Pick next in queue
        cout << endl << "Next in queue: " << attackQueue.front() << endl;
        x = 'B';
        y = 0;
        attackQueue.pop();
    }
     
    //test position
    LastAttack_ = humanplayer.checkPosition(x,y);
    
    if (LastAttack_ == "Hit" && attackQueue.size()==0) {
        //create queue
        attackQueue.push("Above");
        attackQueue.push("Right");
        attackQueue.push("Below");
        attackQueue.push("Left");
    }
    
    return LastAttack_;
}