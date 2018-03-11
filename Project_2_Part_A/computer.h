/* Computer Class
 * The class will hold the computer player/opponent section of the Battleship game
 *
*/

#ifndef computer_h
#define computer_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "player.h"

using namespace std;

class Computer : public Player {
  private:
    GameBoard PersonalMap_;
  public:
    Computer();
    
    void setPersonalMap (GameBoard Map);

    const vector<string>& getPersonalMap ();
    
    void printTrackingBoardforOpponent ();
    
    string checkPosition(char x, int y);

};

#endif