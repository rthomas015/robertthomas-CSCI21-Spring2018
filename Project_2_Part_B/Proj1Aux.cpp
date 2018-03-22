//holds all the non-class function definitions

#include "Proj1Aux.h"

using namespace std;

//Game Introduction
//This prints out the introduction for the game, the name of the game, the rules of the game
//@param none
void gameIntroduction() {
      cout << "Battleship" << endl
           << "Rules: you alternate turns with a computer opponent, choosing locations to attack. Each turn results in a hit or a miss. The game ends when one of the player's ships are all sunk." << endl;
}           

//Read in Gameboard
//This function will request the user input a gameboard file it will then test to see if the
//file is correct, if it is not it will prompt for another file. The file will then recursively input the information into the GameBoard object.
//@param a GameBoard object
void readGameboard (GameBoard &Map, string filename) {
    string file_name = filename,
           gameboard_info = "";
           
    ifstream GameBoard_file;
    GameBoard_file.open(file_name.c_str());
      
      //test if GameBoard file is open correctly
      while (!GameBoard_file.is_open()) {
        cout << endl << "An error occurred, please input another GameBoard file: ";
        cin >> file_name;
        GameBoard_file.open(file_name.c_str());
      }
      
      Map.clearBoard();
      
      while (!GameBoard_file.eof()) {
        getline(GameBoard_file,gameboard_info);
        Map.constructBoard(gameboard_info);
      }
      
    GameBoard_file.close();
}

//attackCoordinates()
//Test User Input for correct formatting (so program doesn't crash)
//Would logically be a player function, but contains input and output
//Error on ###
string attackCoordinates () {
      string input_str = "";
      
      getline(cin, input_str);
      
      while(input_str.length() != 3) {
        input_str = "";
        cout << endl << "Input not recognized" << endl << "Where would you like to attack? (row column) (ex: A 1) ";
        getline(cin, input_str);
      }

    return input_str;
}