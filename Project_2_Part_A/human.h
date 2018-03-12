/* Human Class
 * Holds the member functions/variables needed for the human user to play the game
 * (see below for more detail on each function)
*/

#ifndef human_h
#define human_h

#include "player.h"

using namespace std;

class Human : public Player {
  private:
    GameBoard PersonalMap_;
    
  public:
    //Constructor
    Human();
    
    //setPersonalMap
   /*sets the personal map (the player's board with ships) based on GameBoard object passed to it
   *@param - GameBoard object with gameboard data
   *@return - none
   */
    void setPersonalMap (GameBoard Map);

  //getPersonalMap
  /*returns the personal map for the player based on the player object's GameBoard data
   *@param - none
   *@return - returns the vector of strings that holds map data for the player's personal map
   */
    const vector<string>& getPersonalMap ();
    
  //printTrackingBoardforOpponent
  /* this function prints the tracking board for the opponent to use (shows only hits and misses)
   *@param - none
   *@return - none
   */
    void printTrackingBoardforOpponent ();
    
    
    //checkPosition
   /* Returns whether or not the coorindate values provided constitutes a hit, miss or error on the player's personal Map
   *@param - char x (letter or y value for board)
   *@param - int y (letter or x value for board)
   *@return - a string: hit, miss, or error - depending on result of the coordinates
   */  
    string checkPosition(char x, int y);
    
};

#endif