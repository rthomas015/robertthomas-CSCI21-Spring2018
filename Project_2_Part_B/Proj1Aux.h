//Project1Aux - holds all the non-class functions prototypes
//

#ifndef Proj1Aux_h
#define Proj1Aux_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "GameBoard.h"
#include "player.h"
#include "computer.h"
#include "human.h"

using namespace std;

//Game Introduction
//This prints out the introduction for the game, the name of the game, the rules of the game
//@param none
void gameIntroduction();

//Read in Gameboard
//This function will request the user input a gameboard file (right now its disabled so we can test the program easier) it will then test to see if the
//file is correct, if it is not it will prompt for another file. The file will then recursively input the information into the boardgame object.
//@param BoardGame file
void readGameboard(GameBoard &Map);

//attackCoordinates()
//Test User Input for correct formatting (so program doesn't crash)
//Would logically be a player function, but contains input and output
//@param none
//returns properly formatted coordinates in the form of a string
string attackCoordinates ();

#endif