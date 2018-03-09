#include "player.h"

  //Constructor
  Player::Player () {
    shipsections_left_ = 1;
  }
  
  void Player::placeShips (){
  }
  
  void Player::setShipSectionsLeft(int x) {
    shipsections_left_ = x;
  }
  
  const int Player::getShipSectionsLeft () {
    return shipsections_left_;
  }
