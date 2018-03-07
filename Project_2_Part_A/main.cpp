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

using namespace std;

/* class BoardGame
 * 
 * private
      vector<string> gameboard -  A vector of strings that holds the gameboard data one horizontal line at a time
 * public
      constructBoard(string gameboard_info) - contructs the board game by taking in a string (the current line of the boardgame text file)
        and then adds it to the vector of strings that comprise the gameboard vector.
      string checkPosition(char x, int y) - takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
      printBoard - prints the board
      
 */
class BoardGame {
  private:
    vector<string> gameboard;
    
  public:
    BoardGame() {
      
    }
    
    /* constructBoard
    * contructs the board game by taking in a string (the current line of the boardgame text file)
    * and then adds it to the vector of strings that comprise the gameboard vector.
    * @param string gameboard_info - the string that is taken from the boardgame text file
    * @returns nothing
    */
    
    void constructBoard(string gameboard_info) {
      gameboard.push_back(gameboard_info);
    }
    
    
    /* checkPosition
    * takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
    * @param char x - holds the letter that the user (or computer) passes to the checkPosition function, that is its guess
    * @param int y - holds the number that the user (or computer) passes to the checkPosition function, that is its guess
    * @returns string that says Hit, Miss, or Error depending on the result of the attack
    */
    string checkPosition(char x, int y) {
      string temp_string = "",
             positionResult = "";
      int letter_value = 0;
      //convert letter to number position
      letter_value = x - 65;

      //first check for valid position
      if (letter_value < 10 && y < 10) {
        //valid
        temp_string = gameboard.at(letter_value);
        if (temp_string.at(y*2) == 'S' || temp_string.at(y*2) == 'H') {
          positionResult = "Hit";
          temp_string.at(y*2) = 'H';
          gameboard.at(letter_value) = temp_string;
          //reduce ships: player.setShipsLeft() only on a new Hit
        }
        else {
          positionResult = "Miss";
          temp_string.at(y*2) = 'M';
          gameboard.at(letter_value) = temp_string;
        }
      }
      else {
        //invalid
        positionResult = "Error";
      }
      
      return positionResult;
    }  
    
    
    /* printBoard
    * iterates through the board game vector and prints out each individual line
    * @param none
    * @returns nothing
    */
    void printBoard () {
      char array_of_letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      cout << endl << "  0 1 2 3 4 5 6 7 8 9";
      for (int i=0;i<gameboard.size();i++) {
        cout << endl << array_of_letters[i] << " " << gameboard.at(i);
      }
    }
    /* printTrackingBoard
    * iterates through the board game vector and prints out each individual line 
    * @param none
    * @returns nothing
    */
    void printTrackingBoard () {
      char array_of_letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      string temp_string = "";
      
      cout << endl << "  0 1 2 3 4 5 6 7 8 9";
      
      for (int i=0;i<gameboard.size();i++) {
        temp_string = gameboard.at(i);
        replace(temp_string.begin(), temp_string.end(), 'S', 'o');
        cout << endl << temp_string;
      }
    }
};

class Player {
  private:
  int shipsections_left_;
  
  public:
  //Constructor
  Player () {
    shipsections_left_ = 1;
  }
  
  //Function to place ships on the board - not needed, maybe later?
  virtual void placeShips (){
  }
  
  void setShipSectionsLeft(int x) {
    shipsections_left_ = x;
  }
  
  const int getShipSectionsLeft () {
    return shipsections_left_;
  }
  
};

class Human : public Player {
  private:
  public:
};

class Computer : public Player {
  //empty
};

int main () {
    string file_name = "defaultmap.txt",
           gameboard_info = "";
    BoardGame Map;
    Human Human_Player;
    vector<string> gameboard;
    
    
    //Game Introduction
      cout << "Battleship" << endl
           << "This application tests the Human component of the game and ensures that boards can be read in from a file." << endl;
           
           //Description to add in final version
           //First input a file name to load map data. Then place your five ships on the map. Then alternate
           //turns with computer selecting prositions on the map. Each turn results in a hit or a miss.
           //The game ends when on players ships are all sunk.
           
           
    //end of Game Introduction
    
    
    //Read in Gameboard
    cout << "Please choose a file that holds map data for the game: ";
    //cin >> file_name;
    ifstream boardgame_file;
    //boardgame_file.open(file_name.c_str());
    boardgame_file.open("defaultmap.txt");
      
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
    //end of Read in Gameboard
    
    
    string temp_string = "";
    char x;
    int y = 0;
    
    //main game loop
    while (Human_Player.getShipSectionsLeft() != 0) {
      Map.printBoard();
      cout << endl << "Where would you like to attack? (row column) (ex: A 1) ";
      cin >> x;
      cin >> y;
      
      temp_string = Map.checkPosition(x,y);
      
      while (temp_string == "Error") {
        cout << "Invalid entry please try again: ";
        cin >> x;
        cin >> y;
        temp_string = Map.checkPosition(x,y);
      }
      if (temp_string == "Hit") {
        cout << "You have hit a ship!";
        Human_Player.setShipSectionsLeft(Human_Player.getShipSectionsLeft() - 1);
      }
    } //<-- end game loop

    
    cout << endl << "Congratulations, you have won the game!";
    
    return 0;
}