/* class GameBoard
 * This class will hold the information relating to the GameBoard for the Battleship program. It will store the gameboard data and recall/print the data
 * It will also check which moves are valid by looking at information on the board game and return the success of a move: hit, miss, or error.
*/
 
#include "GameBoard.h"

    //Constructor
    GameBoard::GameBoard() {
      //sets gameboard to empty string
      for(int i=0;i<10;i++) {
        gameboard_.push_back("o o o o o o o o o o");
      }
    }
    
    /*Construct Board (a string)
    * contructs the board game by taking in a string (the current line of the GameBoard text file)
    * and then adds it to the vector of strings that comprise the gameboard vector.
    * @param string gameboard_info - the string that is taken from the GameBoard text file
    * @returns nothing
    */
    
    void GameBoard::constructBoard(string gameboard_info) {
      gameboard_.push_back(gameboard_info);
    }
    
    /*Construct Board (vector of strings) overloaded
    * contructs the board game by taking in a vector of strings
    * and then adds it to the vector of strings that comprise the gameboard vector.
    * @param aMap - a vector of strings holding map data
    * @returns nothing
    */
    void GameBoard::constructBoard(vector<string> aMap) {
      gameboard_.resize(0);
      for (int i=0;i<aMap.size();i++) {
        gameboard_.push_back(aMap.at(i));
      }
    }
    
    /* getGameBoard
     * Returns the vector holding the gameboard information
     * @param = none
     * @returns = the gameboard_ vector
     */
    const vector<string>& GameBoard::getGameBoard () const {
      return gameboard_;
    }
    
    
    /*clearBoard
    * clears all contents of the board making it an empty vector
    * @param none
    * @returns nothing
    */
    void GameBoard::clearBoard() {
      gameboard_.resize(0);
    }
    
    /* checkPosition
    * takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
    * @param char x - holds the letter that the user (or computer) passes to the checkPosition function, that is its guess
    * @param int y - holds the number that the user (or computer) passes to the checkPosition function, that is its guess
    * @returns string that says Hit, Miss, or Error depending on the result of the attack
    */
    string GameBoard::checkPosition(char x, int y) {
      string temp_string = "",
             positionResult = "";
      int letter_value = 0;
      //convert letter to number position
      letter_value = x - 65;

      //first check for valid position
      if (letter_value < 10 && y < 10) {
        //valid
        temp_string = gameboard_.at(letter_value);
        if (temp_string.at(y*2) == 'S' || temp_string.at(y*2) == 'H') {
          positionResult = "Hit";
          temp_string.at(y*2) = 'H';
          gameboard_.at(letter_value) = temp_string;
        }
        else {
          positionResult = "Miss";
          temp_string.at(y*2) = 'M';
          gameboard_.at(letter_value) = temp_string;
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
    void GameBoard::printBoard () {
      char array_of_letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      cout << endl << "  0 1 2 3 4 5 6 7 8 9";
      for (int i=0;i<gameboard_.size();i++) {
        cout << endl << array_of_letters[i] << " " << gameboard_.at(i);
      }
    }
    
    
    /* printTrackingBoard
    * iterates through the board game vector and prints out each individual line 
    * @param none
    * @returns nothing
    */
    void GameBoard::printTrackingBoard () {
      char array_of_letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      string temp_string = "";
      
      cout << endl << "  0 1 2 3 4 5 6 7 8 9";
      
      for (int i=0;i<gameboard_.size();i++) {
        temp_string = gameboard_.at(i);
        replace(temp_string.begin(), temp_string.end(), 'S', 'o');
        cout << endl << array_of_letters[i] << " " << temp_string;
      }
    }
