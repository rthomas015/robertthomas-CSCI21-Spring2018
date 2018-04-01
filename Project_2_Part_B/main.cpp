/*Project 2 - Part A
  By: Robert Thomas
  Date: 3/5/2018 
  Description: Write a program that takes in information from a file (user specified) and stores it as a map for a game of Battleship. The program
  should have a base class (Player) and two classes derived from it (Computer) and (Human). For Part A only the Human player needs to be completed.
  3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "GameBoard.h"
#include "Proj1Aux.h"
#include "player.h"
#include "computer.h"
#include "human.h"

using namespace std;

//start of main program
int main (int argc, char* argv[]) {
    GameBoard GameMap;
    Human Human_Player;
    Computer Computer_Player;
    string temp_string = "",
           input_str = "",
           filename_computer = "",
           filename_human = "",
           first_turn = "";
    
    //random generator
    srand(time(0));
    
    int random_num = 0;
    random_num = (rand() % 2);

    
    //Command Line Arguments
    if (argc >= 3) {
      //filename plus two arguments or more
      filename_human = argv[1];
      filename_computer = argv[2];
      if (argc >= 4) {
        //filename plus three arguments
        first_turn = argv[3];
      }
      else {
        //select random player
        if (random_num == 0) {
          first_turn = "HUMAN";
        }
        else if (random_num == 1) {
          first_turn = "COMPUTER";
        }
      }
    }
    else {
      cout << "Invalid number of arguments - terminating program.";
      return 1;
    }
    
    //Game Introduction
    gameIntroduction();
    
    //Read in Gameboard from computer player file into GameBoard object
    readGameboard(GameMap,filename_computer);
    //Set the extracted GameMap to the Computer's GameMap
    Computer_Player.setPersonalMap(GameMap);
    GameMap.clearBoard();
    
    //Read in Gameboard from human player file into GameBoard object
    readGameboard(GameMap,filename_human);
    //Set the extracted GameMap to the Humans's GameMap
    Human_Player.setPersonalMap(GameMap);
  
    //<-- main game loop
    if (first_turn == "HUMAN") { //<-- game loop if Human is first turn
      while ((Computer_Player.getShipSectionsLeft() > 0) && (Human_Player.getShipSectionsLeft() > 0)) {
        humanTurn(Computer_Player);
        cout << endl << "Computer player: " << Computer_Player.attackPosition(Human_Player);
      } 
    }
    else if (first_turn == "COMPUTER") { //<-- game loop if Computer is first turn
      while ((Computer_Player.getShipSectionsLeft() > 0) && (Human_Player.getShipSectionsLeft() > 0)) {
        cout << endl << "Computer player: " << Computer_Player.attackPosition(Human_Player);
        humanTurn(Computer_Player);
      }
    }
    //<-- end game loop
    
    //Give appropriate ending based on if you won or lost
    if (Computer_Player.getShipSectionsLeft() == 0) {
      cout << endl << "Congratulations, you have won the game!";
    }
    else if (Human_Player.getShipSectionsLeft() == 0) {
      cout << endl << "You lose!";
    }
    
    return 0;
}