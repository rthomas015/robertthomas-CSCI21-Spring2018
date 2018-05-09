/* Computer Class
 * The class will hold the computer player/opponent section of the Battleship game - only partially
 * completed per instruction 
*/

#ifndef computer_h
#define computer_h

#include "node.h"
#include "queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "player.h"
#include "human.h"

using namespace std;

class Computer : public Player {
  private:
    GameBoard PersonalMap_;
    string LastAttack_;
    Queue<string> attackQueue; //using personal queue
    
  public:
    //Constructor
    Computer();
    
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

    //attackPosition
    /*Determines a position to attack and then proceeds to test that attack position
    *@param - human player object that will be attacked
    *@return - returns the value from checkPosition.
    */
    string attackPosition (Human &humanplayer);
  
};

#endif