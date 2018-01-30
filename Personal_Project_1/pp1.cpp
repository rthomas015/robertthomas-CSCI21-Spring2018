/*Project 1 - Part A
  By: Robert Thomas
  Date: 1/27/2018 
  Description: Build a basic tic-tac-toe game. AI will not function, only placing markers by random on the
  board.
    Incremental Change 1: Since the game is solved (all known states and only one
  real strategy) eventually that specific set of moves to reach that end state should be added to the program.
    Incremental Change 2: Attempt to move from that specfic maximized strategy to something more abstract.
    Where the program plays games and makes changes to its strategy based on its wins and losses.
  */

//preprocessor directives
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//start of main program
int main () {
    //create board and initalize it to an empty state
    int game_board [3][3] = 
    {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    
    int random_choice1 = 0, random_choice2 = 0, user_choice1 = 0, user_choice2 = 0;
    bool end_state = false, draw = true;
    srand (time(0));
    
    
    cout << "Tic-Tac-Toe" << endl
         << "-----------" << endl;
    
    
    
    //game loop
    while (end_state != true) {
        
        cout << "Select a position: ";
        cin >> user_choice1;
        cout << "Select other coordinate: ";
        cin >> user_choice2;
        
        while (game_board [user_choice1][user_choice2] != 0) {
            cout << "Select again" << endl;
            cin >> user_choice1;
            cin >> user_choice2;
        }
        
        game_board [user_choice1][user_choice2] = 1;
        
        //test draw game (no more spaces)
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (game_board[i][j] == 0)
                    draw = false;
            }
        }
        
        //test for end state
        if ((game_board [0][0] == 1 && game_board [0][1] == 1 && game_board [0][2] == 1) ||
            (game_board [0][0] == 1 && game_board [1][0] == 1 && game_board [2][0] == 1) ||
            (game_board [0][0] == 1 && game_board [1][1] == 1 && game_board [2][2] == 1) ||
            (game_board [0][1] == 1 && game_board [1][1] == 1 && game_board [2][1] == 1) ||
            (game_board [0][2] == 1 && game_board [1][2] == 1 && game_board [2][2] == 1) ||
            (game_board [1][0] == 1 && game_board [1][1] == 1 && game_board [1][2] == 1) ||
            (game_board [2][0] == 1 && game_board [2][1] == 1 && game_board [2][2] == 1) ||
            (game_board [2][0] == 1 && game_board [1][1] == 1 && game_board [0][2] == 1)) {
                cout << "Player x won the game." << endl;
                end_state = true;
        }
        
        else if ((game_board [0][0] == -1 && game_board [0][1] == -1 && game_board [0][2] == -1) ||
                (game_board [0][0] == -1 && game_board [1][0] == -1 && game_board [2][0] == -1) ||
                (game_board [0][0] == -1 && game_board [1][1] == -1 && game_board [2][2] == -1) ||
                (game_board [0][1] == -1 && game_board [1][1] == -1 && game_board [2][1] == -1) ||
                (game_board [0][2] == -1 && game_board [1][2] == -1 && game_board [2][2] == -1) ||
                (game_board [1][0] == -1 && game_board [1][1] == -1 && game_board [1][2] == -1) ||
                (game_board [2][0] == -1 && game_board [2][1] == -1 && game_board [2][2] == -1) ||
                (game_board [2][0] == -1 && game_board [1][1] == -1 && game_board [0][2] == -1)) {
                    cout << "Player y won the game." << endl;
                    end_state = true;
                }
        else if (draw == true) {
            cout << "Draw game." << endl;
            end_state = true;
        }
        
        
        //computer turn (this wont work well because the program executes too quickly to give a non equal number)
        random_choice1 = rand() % 2 + 1;
        random_choice2 = rand() % 2 + 1;
 
        while (game_board[random_choice1][random_choice2] != 0) {
            random_choice1 = rand() % 2 + 1;
            random_choice2 = rand() % 2 + 1;
        }
        
        game_board[random_choice1][random_choice2] = -1;
        //convert win state check to a separate function so it can be called again easily when alternating turns between
        //computer and user

    }
    
    /*
     //TODO:
    
    */
    return 0;
}