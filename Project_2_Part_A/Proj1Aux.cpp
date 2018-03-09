//holds all the non-class function definitions

#include "Proj1Aux.h"

using namespace std;

//Game Introduction
//This prints out the introduction for the game, the name of the game, the rules of the game
//@param none
void gameIntroduction() {
      cout << "Battleship" << endl
           << "This application tests the Human component of the game and ensures that boards can be read in from a file." << endl;
           
           //Description to add in final version
           //First input a file name to load map data. Then place your five ships on the map. Then alternate
           //turns with computer selecting prositions on the map. Each turn results in a hit or a miss.
           //The game ends when on players ships are all sunk.
}           

//Read in Gameboard
//This function will request the user input a gameboard file (right now its disabled so we can test the program easier) it will then test to see if the
//file is correct, if it is not it will prompt for another file. The file will then recursively input the information into the boardgame object.
//@param none
void readGameboard (BoardGame &Map) {
    string file_name = "defaultmap.txt",
           gameboard_info = "";
           
    cout << "Please choose a file that holds map data for the game: ";
    getline(cin,file_name);
    ifstream boardgame_file;
    boardgame_file.open(file_name.c_str());
      
      //test if boardgame file is open correctly
      while (!boardgame_file.is_open()) {
        cout << endl << "An error occurred, please input another boardgame file: ";
        cin >> file_name;
        boardgame_file.open(file_name.c_str());
      }
      
      while (!boardgame_file.eof()) {
        getline(boardgame_file,gameboard_info);
        Map.constructBoard(gameboard_info);
      }
      
    boardgame_file.close();
}

//attackCoordinates()
//Test User Input for correct formatting (so program doesn't crash)
//Would logically be a player function, but contains input and output
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