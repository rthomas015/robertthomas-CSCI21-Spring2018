/*Project 2 - Part A
  By: Robert Thomas
  Date: 3/5/2018 
  Description: Write a program that takes in information from a file (user specified) and stores it as a map for a game of Battleship. The program
  should have a base class (Player) and two classes derived from it (Computer) and (Human). For Part A only the Human player needs to be completed.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "boardgame.h"
#include "Proj1Aux.h"
#include "player.h"
#include "computer.h"
#include "human.h"


using namespace std;

int main () {
    BoardGame GameMap;
    Human Human_Player;
    string temp_string = "",
           input_str = "";
    char letter;
    int number = 0;
  
    //Game Introduction
    gameIntroduction();
    
    //Read in Gameboard
    readGameboard(GameMap);
    
    //main game loop
    //This will have to be changed/altered in Part B and Part C to include the computer opponent
    //And to test a win or loss condition that includes the computer opponent
    while (Human_Player.getShipSectionsLeft() != 0) {
      GameMap.printBoard();
      cout << endl << "Where would you like to attack? (row column) (ex: A 1) ";
      input_str = attackCoordinates();
      
      letter = input_str[0];
      number = input_str[2] - 48;
      temp_string = GameMap.checkPosition(letter,number);
      
      while (temp_string == "Error") {
        cout << "Invalid entry please try again: ";
        input_str = attackCoordinates();
      
        letter = input_str[0];
        number = input_str[2] - 48;
        temp_string = GameMap.checkPosition(letter,number);
      }
      
      if (temp_string == "Hit") {
        cout << "You have hit a ship!";
        Human_Player.setShipSectionsLeft(Human_Player.getShipSectionsLeft() - 1);
      }
    } //<-- end game loop

    
    cout << endl << "Congratulations, you have won the game!";
    
    return 0;
}