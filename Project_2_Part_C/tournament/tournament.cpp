/*Project 2 - Part C
  By: Robert Thomas
  Date: 4/10/2018 
  Description: Write a program that takes in users from a file and creates a tournament bracket for them
  the winner will be declared based on ASCII value of name. Use both a Queue and a Stack and evaluate 
  how the program works with both.
  3.5 - 3:00 p.m
*/

#include "queue.h"
#include "stack.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;


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

//add template
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

int main (int argc, char* argv[]) {
    Queue playerQueue;
    Stack playerStack;
    
    string player_1 = "",
           player_2 = "",
           player_list = "",
           tournament_type = "",
           file_name = "input.txt";
    int totalGamesPlayed = 0,
        totalPlayers = 0;
    double avgGamesPlayed = 0.00;
    vector<string> listofPlayers;
    vector<int> gamesPlayed;
    
    //insert argument logic here
    //No testing needed per instructions
    if (argc == 3) {
        file_name = argv[1];
        tournament_type = argv[2];
    }
    
    //Conditional for tournament type
    if (tournament_type == "Queue") {
        Queue playerList;
        readIn(playerList, file_name, totalPlayers, listofPlayers, gamesPlayed);
        tournament_function (playerList, totalPlayers, totalGamesPlayed, listofPlayers, gamesPlayed);
    }
    else if (tournament_type == "Stack") {
        Stack playerList;
        readIn(playerList, file_name, totalPlayers, listofPlayers, gamesPlayed);
        tournament_function(playerList, totalPlayers, totalGamesPlayed, listofPlayers, gamesPlayed);
    }
    else { //something unexpected happened
        return 1;
    }
   
    //Tournament Function
   // tournament_function(playerStack, playerQueue, totalPlayers, totalGamesPlayed, listofPlayers, gamesPlayed);
    
    avgGamesPlayed = totalGamesPlayed / 7.00;
    
    //fix playerList.peek
    //Tournament Output
    cout << endl << "The Tournament Champion is: " /*<< playerList.peek_name()*/
         << endl << "Total Games Played: " << totalGamesPlayed 
         << endl << "The average number of Games Played: " << fixed << setprecision(2) << avgGamesPlayed;
    
    for (int i=0;i<totalPlayers;i++) {
        cout << endl << listofPlayers.at(i) << " played " << gamesPlayed.at(i) << " games.";
    }
    
    return 0;
}
