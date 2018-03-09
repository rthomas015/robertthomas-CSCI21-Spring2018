/* class BoardGame
 * 
 * private
 *     vector<string> gameboard -  A vector of strings that holds the gameboard data one horizontal line at a time
 *
 * public
 *     -constructBoard(string gameboard_info) - contructs the board game by taking in a string (the current line of the boardgame text file)
 *       and then adds it to the vector of strings that comprise the gameboard vector.
 *       
 *     -string checkPosition(char x, int y) - takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
 *     
 *     -printBoard - prints the board
 *     
 */
 
#include "boardgame.h"

    //Constructor
    BoardGame::BoardGame() {
      //sets gameboard to empty string
      gameboard.push_back("   ");
    }
    
    /* constructBoard
    * contructs the board game by taking in a string (the current line of the boardgame text file)
    * and then adds it to the vector of strings that comprise the gameboard vector.
    * @param string gameboard_info - the string that is taken from the boardgame text file
    * @returns nothing
    */
    
    void BoardGame::constructBoard(string gameboard_info) {
      gameboard.push_back(gameboard_info);
    }
    
    
    /* checkPosition
    * takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
    * @param char x - holds the letter that the user (or computer) passes to the checkPosition function, that is its guess
    * @param int y - holds the number that the user (or computer) passes to the checkPosition function, that is its guess
    * @returns string that says Hit, Miss, or Error depending on the result of the attack
    */
    string BoardGame::checkPosition(char x, int y) {
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
    void BoardGame::printBoard () {
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
    void BoardGame::printTrackingBoard () {
      char array_of_letters[10] = {'A','B','C','D','E','F','G','H','I','J'};
      string temp_string = "";
      
      cout << endl << "  0 1 2 3 4 5 6 7 8 9";
      
      for (int i=0;i<gameboard.size();i++) {
        temp_string = gameboard.at(i);
        replace(temp_string.begin(), temp_string.end(), 'S', 'o');
        cout << endl << temp_string;
      }
    }
