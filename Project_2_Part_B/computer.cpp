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
    stringstream coords;
    string temp_string = "";
    char x, temp_x;
    int y = 0, temp_y = 0;
    
    //come up with a position if last attack was a miss and the queue has not been created
    if (LastAttack_ == "Miss" && attackQueue.size()==0) {
        //random number 0-99
        srand(time(0));
        y = (rand() % 10);
        x = (rand() % 10) + 65;

        //per specification doesn't need to test if random pick has been choosen previously
    }
    
    //if the queue has been created exhaust queue
    if (attackQueue.size()>0) {
        //Pick next in queue
        cout << endl << "Next in queue: " << attackQueue.front() << endl;
        temp_string = attackQueue.front();
        x = temp_string[0];
        y = temp_string[2] - 48;
        attackQueue.pop();
    }
    cout << "Computer Guessed: " << x << " " << y << endl;
    
    //test position
    LastAttack_ = humanplayer.checkPosition(x,y);
    
    //Create a new Queue if there was a hit and no Queue exists
    if (LastAttack_ == "Hit" && attackQueue.size()==0) {
        //create queue
        //Push already choosen squares
        //Do not push squares that don't exist
        //add above if x != 65
        //above is really: y = y and x = x - 1
        if (x != 65) {
            coords.str("");
            temp_x = x - 1;
            coords << temp_x << " " << y;
            attackQueue.push(coords.str());
        }
        //Add right if y != 9
        //right is really: y = y + 1 and x = x
        if (y != 9) {
            coords.str("");
            temp_y = y + 1;
            coords << x << " " << temp_y;
            attackQueue.push(coords.str());
        }
        //Add below if x !=74
        //below is really: y = y and x = x + 1
        if (x != 74) {
            coords.str("");
            temp_x = x + 1;
            coords << temp_x << " " << y;
            attackQueue.push(coords.str());
        }
        //Add left if y != 0
        //left is really: y = y - 1 and x = x
        if (y != 0) {
            coords.str("");
            temp_y = y - 1;
            coords << x << " " << temp_y;
            attackQueue.push(coords.str());
        }
    }
    
    return LastAttack_;
}