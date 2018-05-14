//holds all the non-class function definitions

#include "Proj1Aux.h"
#include <cctype>

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
string attackCoordinates () {
      string input_str = "";
      
      getline(cin, input_str);
      
      while ((input_str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ") != std::string::npos) || input_str.size() < 2 || input_str.size() > 3 || ((input_str.size() == 3) && input_str.at(1) != ' ')) {
          input_str = "";
          cout << endl << "Input not recognized" << endl << "Where would you like to attack? (row column) (ex: A 1) ";
          getline(cin, input_str);
        }
      
      input_str.at(0) = toupper(input_str.at(0));
      
      return input_str;
}


//Human Turn 
void humanTurn(Computer &Comp) {
      char letter;
      string input_str = "",
             temp_string = "";
      int number = 0;
      
      Comp.printTrackingBoardforOpponent();
      cout << endl << "Where would you like to attack? (row column) (ex: A 1) ";
      input_str = attackCoordinates();
      
      if (input_str.length() == 3) {
        letter = input_str[0];
        number = input_str[2] - 48;
      }
      else if (input_str.length() == 2) {
        letter = input_str[0];
        number = input_str[1] - 48;
      }

      temp_string = Comp.checkPosition(letter,number);
      
      while (temp_string == "Error") {
        cout << "Invalid entry please try again: ";
        input_str = attackCoordinates();
      
        if (input_str.length() == 3) {
          letter = input_str[0];
          number = input_str[2] - 48;
        }
        else if (input_str.length() == 2) {
          letter = input_str[0];
          number = input_str[1] - 48;
        }
        
        temp_string = Comp.checkPosition(letter,number);
      }
      
      if (temp_string == "Hit") {
        cout << "You have hit a ship!";
        Comp.setShipSectionsLeft(Comp.getShipSectionsLeft() - 1);
      }
}