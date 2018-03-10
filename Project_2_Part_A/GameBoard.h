//GameBoard.h
/* class GameBoard
 * This class will hold the information relating to the GameBoard for the Battleship program. It will store the gameboard data and recall/print the data
 * It will also check which moves are valid by looking at information on the board game and return the success of a move: hit, miss, or error.
 *
 * private
 *     vector<string> gameboard -  A vector of strings that holds the gameboard data one horizontal line at a time
 *
 * public
 *     -constructBoard(string gameboard_info) - contructs the board game by taking in a string (the current line of the GameBoard text file)
 *       and then adds it to the vector of strings that comprise the gameboard vector.
 *       
 *     -string checkPosition(char x, int y) - takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
 *     
 *     -printBoard - prints the board
 *     
 */
 

#ifndef GameBoard_h
#define GameBoard_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class GameBoard {
  private:
    vector<string> gameboard_;
    
  public:
  
    //Constructor
    GameBoard();
    
    /*constructBoard
    * contructs the board game by taking in a string (the current line of the GameBoard text file)
    * and then adds it to the vector of strings that comprise the gameboard vector.
    * @param string gameboard_info - the string that is taken from the GameBoard text file
    * returns nothing
    */
    
    void constructBoard(string gameboard_info);
    
    void constructBoard(vector<string> aMap);
    
    const vector<string>& getGameBoard () const;
    
    /*clearBoard
    * clears all contents of the board making it an empty vector
    * @param none
    * @returns nothing
    */
    void clearBoard();
    
    /* checkPosition
    * takes in a position letter and number (e.g A1) then checks the position to see whether the guess resulted in a hit, miss or an error (e.g. outside the range)
    * @param char x - holds the letter that the user (or computer) passes to the checkPosition function, that is its guess
    * @param int y - holds the number that the user (or computer) passes to the checkPosition function, that is its guess
    * @returns string that says Hit, Miss, or Error depending on the result of the attack
    */
    string checkPosition(char x, int y);

    /* printBoard
    * iterates through the board game vector and prints out each individual line
    * @param none
    * @returns nothing
    */
    void printBoard ();
    /* printTrackingBoard
    * iterates through the board game vector and prints out each individual line 
    * @param none
    * @returns nothing
    */
    void printTrackingBoard ();
    
};

#endif