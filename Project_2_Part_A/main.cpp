/*Project 2 - Part A
  By: Robert Thomas
  Date: 3/5/2018 
  Description: Write a program that takes in information from a file (user specified) and stores it as a map for a game of Battleship. The program
  should have a base class (Player) and two classes derived from it (Computer) and (Human). For Part A only the Human player needs to be completed.
  13
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "GameBoard.h"
#include "Proj1Aux.h"
#include "player.h"
#include "computer.h"
#include "human.h"

using namespace std;

//start of main program
int main () {
    GameBoard GameMap;
    Human Human_Player;
    Computer Computer_Player;
    string temp_string = "",
           input_str = "";
    char letter;
    int number = 0;
  
    //Game Introduction
    gameIntroduction();
    
    //Read in Gameboard from file into GameBoard object
    readGameboard(GameMap);
    
    //Set the extracted GameMap to the Computer's GameMap
    //Note: Human_Player will just have a default map of no ships
    Computer_Player.setPersonalMap(GameMap);
    
    //main game loop
    //This will have to be changed/altered in Part B and Part C to include human and computer move sections
    //And to test a win or loss condition that includes both players (i.e. which one is at 0 ships first loses)
    while (Computer_Player.getShipSectionsLeft() != 0) {
      Computer_Player.printTrackingBoardforOpponent();
      cout << endl << "Where would you like to attack? (row column) (ex: A 1) ";
      input_str = attackCoordinates();
      
      letter = input_str[0];
      number = input_str[2] - 48;
      temp_string = Computer_Player.checkPosition(letter,number);
      
      while (temp_string == "Error") {
        cout << "Invalid entry please try again: ";
        input_str = attackCoordinates();
      
        letter = input_str[0];
        number = input_str[2] - 48;
        temp_string = Computer_Player.checkPosition(letter,number);
      }
      
      if (temp_string == "Hit") {
        cout << "You have hit a ship!";
        Computer_Player.setShipSectionsLeft(Computer_Player.getShipSectionsLeft() - 1);
      }
    } //<-- end game loop

    
    cout << endl << "Congratulations, you have won the game!";
    
    return 0;
}