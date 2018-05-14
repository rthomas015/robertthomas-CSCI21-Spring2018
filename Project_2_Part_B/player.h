/*  Player Class 
 *  Base class of the Player (computer or human), holds the shipsections_left_ variable which is the number of
    ship sections left for the player, along with functions needed for both players
 */


#ifndef player_h
#define player_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "GameBoard.h"

using namespace std;

class Player {
  private:
  int shipsections_left_;
  
  public:
  //Constructor
  Player ();
  
  //placeShips()
  //Function to place ships on the board, this may be eventually implemented, but is currently not because the board
  //supplies the locations of the ships. Its virtual because it will change depending on if its a human or a computer
  //@param none
  virtual void placeShips ();
  
  //printTrackingBoardforOpponent  - pure virtual
  /* this function prints the tracking board for the opponent to use (shows only hits and misses)
   *@param - none
   *@return - none
   */
  virtual void printTrackingBoardforOpponent () = 0;
  
  //printWholeBoard - pure virtual
  /* this function prints the entire board (all ships, hits and misses)
   *@param - none
   *@return - none
   */
  virtual void printWholeBoard () = 0;
  
  //setPersonalMap - pure virtual
  /*sets the personal map (the player's board with ships) based on GameBoard object passed to it
   *@param - GameBoard object with gameboard data
   *@return - none
   */
  virtual void setPersonalMap (GameBoard Map) = 0;
  
  //getPersonalMap  - pure virtual
  /*returns the personal map for the player based on the player object's GameBoard data
   *@param - none
   *@return - returns the vector of strings that holds map data for the player's personal map
   */
  virtual const vector<string>& getPersonalMap () = 0;
  
  //checkPosition  - pure virtual
  /* Returns whether or not the coorindate values provided constitutes a hit, miss or error on the player's personal Map
   *@param - char x (letter or y value for board)
   *@param - int y (letter or x value for board)
   *@return - a string: hit, miss, or error - depending on result of the coordinates
   */  
  virtual string checkPosition(char x, int y) = 0;
  
  //setShipSectionsLeft
  //changes the shipsections_left_ variable to what ever value is supplied as an argument
  //@param int x - the number to set shipsections_left_
  //@return - none
  void setShipSectionsLeft(int x);
  
  //getShipSectionsLeft
  //returns whatever value is stored in shipsections_left_ variable
  //@param none
  //@return - value of ShipSectionsLeft_
  const int getShipSectionsLeft ();
  
};

#endif