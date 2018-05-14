/*Project 2 - Part C
  By: Robert Thomas
  Date: 4/10/2018 
  Description: Write a program that takes in users from a file and creates a tournament bracket for them
  the winner will be declared based on ASCII value of name. Use both a Queue and a Stack and evaluate 
  how the program works with both.
  3.5 - 9:00 pm
*/

#include "queue.h"
#include "stack.h"
#include "Iterator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//QS Template - to utilize either stacks or queues
//tournament_function
/*The tournament function takes first two players from list/queue, selects winner for the match, prints
 *winner userID and loser's userID and then adds the winner back to the list/queue
 *@param - QS& playerList (by value: queue or list to function)
 *@param - int& totalPlayers (by value: totalPlayers is the number of total players)
 *@param - int& totalGamesPlayed (by value: is a value that holds the total number of games played)
 *@param - vector<string>& listofPlayers - a vector holding the list of players
 *@param - vector<int>& gamesPlayed - a vector holding the number of games each of those players played
 *@return - void
*/
template <typename QS>
void tournament_function(QS& playerList, int& totalPlayers, int& totalGamesPlayed, vector<string>& listofPlayers, vector<int>& gamesPlayed) {
    string player_1 = "",
           player_2 = "";

    while (playerList.size() > 1) {
        //Dequeue first two players
        player_1 = playerList.peek_name();
        playerList.pop();
        
        player_2 = playerList.peek_name();
        playerList.pop();

        //select a winner
        if (player_1 < player_2) {
            //player_1 is the winner
            cout << player_1 << " won against " << player_2 << endl;
            playerList.push(player_1);
        }
        else {
            //player_2 is the winner
            cout << player_2 << " won against " << player_1 << endl;
            playerList.push(player_2);
        }
        
        for (int i=0;i<totalPlayers;i++) {
            if (listofPlayers.at(i) == player_1) {
                gamesPlayed.at(i) = gamesPlayed.at(i) + 1;
            }
            if (listofPlayers.at(i) == player_2) {
                gamesPlayed.at(i) = gamesPlayed.at(i) + 1;
            }
        }
        
        totalGamesPlayed = totalGamesPlayed + 1;
    }

}

//QS Template - to utilize either stacks or queues
//readIn
/*takes a file and reads in a list of players from that file one by one into a queue/list, and also into a vector holding the listofPlayers
 *@param - QS& playerList (by value: queue or list to function)
 *@param - string file_name - the name of the file passed as an argument
 *@param - int& totalPlayers (by value: totalPlayers is the number of total players)
 *@param - vector<string>& listofPlayers - a vector holding the list of players
 *@param - vector<int>& gamesPlayed - a vector holding the number of games each of those players played
 *@return - void
*/
template <typename QS>
void readIn (QS& playerList, string file_name, int& totalPlayers, vector<string>& listofPlayers, vector<int>& gamesPlayed) {
    //read in list of players from file
    string player_list = "";
    ifstream player_file;
    player_file.open(file_name.c_str());
      
      //test if file is open correctly
      while (!player_file.is_open()) {
        cout << endl << "An error occurred, please input another file: ";
        cin >> file_name;
        player_file.open(file_name.c_str());
      }
      
      while (!player_file.eof()) {
        getline(player_file, player_list);
        playerList.push(player_list);
        listofPlayers.push_back(player_list);
        gamesPlayed.push_back(0);
        totalPlayers = totalPlayers + 1;
      }
      
    player_file.close();
}

//start of main program
int main (int argc, char* argv[]) {
    /* Variables
    * - string file_name - the name of the file passed as an argument, defaults to input.txt
    * - int totalPlayers - the number of total players
    * - vector<string> listofPlayers - a vector holding the list of players
    * - vector<int> gamesPlayed - a vector holding the number of games each of those players played
    * - string tournament_champion - holds the name of the champion
    * - string player_1, player_2 - temp strings holding current player 1 and current player 2
    * - string tournament_type = holds information from argument whether game is to be played with Queue or Stack
    * - string player_list - temp string holding information during file input
    * - double avgGamesPlayed - holds the average number of games played
    */
    string player_1 = "",
           player_2 = "",
           player_list = "",
           tournament_type = "",
           file_name = "input.txt",
           tournament_champion = "";
    int totalGamesPlayed = 0,
        totalPlayers = 0;
    double avgGamesPlayed = 0.00;
    vector<string> listofPlayers;
    vector<int> gamesPlayed;
    
    //Argument logic here
    //No testing needed per instructions - so the program can fail if the right arguments are passed
    //but added a basic test to make program semi responsible
    if (argc == 3) {
        file_name = argv[1];
        tournament_type = argv[2];
    }
    
    //Conditional for tournament type
    //1: create Queue or Stack of type string
    //2: call ReadIn to read in information into that data type
    //3: call tournament_function to run main tournament
    //4: set tournament_champion to player left in stack or queue
    if (tournament_type == "Queue") {
        Queue<string> playerList;
        readIn(playerList, file_name, totalPlayers, listofPlayers, gamesPlayed);
        
        //Test Queue Iterator using ++
        cout << "Queue Iterator using ++ (starts at tail):" << endl;
        for (Iterator<string> iter = playerList.begin();iter != playerList.end();iter++) {
            cout << "Names: " << iter.print() << endl;
        }
        
        cout << endl;
        
        //Test Queue Iterator using --
        cout << endl << "Queue Iterator using -- (starts at head):" << endl;
        for (Iterator<string> iter = playerList.rbegin();iter != playerList.end();iter--) {
            cout << "Names: " << iter.print() << endl;
        }
        
        cout << endl;
        
        tournament_function (playerList, totalPlayers, totalGamesPlayed, listofPlayers, gamesPlayed);
        tournament_champion = playerList.peek_name();
        
    }
    else if (tournament_type == "Stack") {
        Stack<string> playerList;
        readIn(playerList, file_name, totalPlayers, listofPlayers, gamesPlayed);
        tournament_function(playerList, totalPlayers, totalGamesPlayed, listofPlayers, gamesPlayed);
        tournament_champion = playerList.peek_name();
    }
    else { //something unexpected happened
        cout << "You did something unexpected!" << endl;
        return 1;
    }
    
    //Calculate average number of games played
    avgGamesPlayed = static_cast<double>(totalGamesPlayed) / static_cast<double>(totalPlayers);
    
    //Tournament Output
    cout << endl << "The Tournament Champion is: " << tournament_champion
         << endl << "Total Games Played: " << totalGamesPlayed 
         << endl << "The average number of Games Played: " << fixed << setprecision(2) << avgGamesPlayed;
    
    //Output number of games played
    for (int i=0;i<totalPlayers;i++) {
        cout << endl << listofPlayers.at(i) << " played " << gamesPlayed.at(i) << " games.";
    }
    
    return 0;
}