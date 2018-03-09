//Player Class
/*  private: 
 *      shipsections_left_ = integer that holds the number of ship sections the player has remaining (defaults to start at 15, but would also need to match up with the map)
 *
 *  public:
 *      player() - constructor
 *      
 *      virtual void placeShips () - a function to place ships on the board, this may be eventually implemented, but is currently not because the board
 *          supplies the locations of the ships. Its virtual because it will change depending on if its a human or a computer
 *
 *      setShipSectionsLeft - changes the shipsections_left_ variable to what ever value is supplied as an argument 
 *           @param int x - the number to set shipsections_left_
 *      
 *      getShipSectionsLeft - returns whatever value is stored in shipsections_left_ variable
 *          @param none
 *
*/


#ifndef player_h
#define player_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "boardgame.h"

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
  
  
  //setShipSectionsLeft
  //changes the shipsections_left_ variable to what ever value is supplied as an argument
  //@param int x - the number to set shipsections_left_
  void setShipSectionsLeft(int x);
  
  //getShipSectionsLeft
  //returns whatever value is stored in shipsections_left_ variable
  //@param none
  const int getShipSectionsLeft ();
  
};

#endif