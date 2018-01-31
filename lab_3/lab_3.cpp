/*
 * Name        : lab_3.cpp
 * Author      : Robert Thomas
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */
string Goldilocks(string item, int number) {
  string output_str = "";
  
  if (item == "porridge") {
    switch (number) {
      case 1:
        output_str = "This porridge is too hot";
        break;
      case 2:
        output_str = "This porridge is too cold";
        break;
      case 3:
        output_str = "This porridge is just right";
        break;
    };
  }
  else if (item == "chair") {
    switch (number) {
      case 1:
        output_str = "This chair is too big";
        break;
      case 2:
        output_str = "This chair is too small";
        break;
      case 3:
        output_str = "This chair is just right";
        break;
    };
  }
  else if (item == "bed") {
    switch (number) {
      case 1:
        output_str = "This bed is too hard";
        break;
      case 2:
        output_str = "This bed is too soft";
        break;
      case 3:
        output_str = "This bed is just right";
        break;
    };
  }
  else {
    output_str = "Nothing happened";
  }
  
  return output_str;
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalud inputs
 */
int RockScissorPaper(char player_one, char player_two) {
  int score = 0;
  
  if (player_one == 'r' || player_one == 'R') {
    switch (player_two) {
      case 'R':
      case 'r':
        score = 3;
        break;
      case 'P':
      case 'p':
        score = 2;
        break;
      case 'S':
      case 's':
        score = 1;
        break;
    };
  }
  else if (player_one == 's' || player_one == 'S') {
    switch (player_two) {
      case 'R':
      case 'r':
        score = 2;
        break;
      case 'P':
      case 'p':
        score = 1;
        break;
      case 'S':
      case 's':
        score = 3;
        break;
    };
  }
  else if (player_one == 'p' || player_one == 'P') {
    switch (player_two) {
      case 'R':
      case 'r':
        score = 1;
        break;
      case 'P':
      case 'p':
        score = 3;
        break;
      case 'S':
      case 's':
        score = 2;
        break;
    };
  }
  else {
    score = 0;
  }
  
  return score;
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  string converted_string = input;
  int length_str = converted_string.length();
  
  for (int i=0;i<length_str; i++) {
    converted_string.at(i) = tolower(input.at(i));
  }
  return converted_string;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  string converted_string = input;
  int length_str = converted_string.length();
  
  for (int i=0;i<length_str; i++) {
    converted_string.at(i) = toupper(input.at(i));
  }
  return converted_string;
}