/* Human Class
 * Holds the member functions/variables needed for the human user to play the game
 *
*/

#ifndef human_h
#define human_h

#include "player.h"

using namespace std;

class Human : public Player {
  private:
    GameBoard PersonalMap_;
    
  public:
    Human();
    
    void setPersonalMap (GameBoard Map);

    const vector<string>& getPersonalMap ();
    
    void printTrackingBoardforOpponent ();
    
};

#endif