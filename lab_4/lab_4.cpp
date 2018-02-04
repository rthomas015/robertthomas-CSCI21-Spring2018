/*
 * Name        : lab_4.cpp
 * Author      : Robert Thomas
 * Date        : 2/1/2018
 * Description : Use branching statements, looping statements and string and
 *               character functions to complete the functions
 */

#include "lab_4.h"

using namespace std;

/*
 * Return a string comprised of a label, followed by a space, followed by a
 * separator character, followed by a space, followed by a floating-point value.
 * For example, label="Temperature", value=41.7, separator=':' will return
 * "Temperature : 41.7".
 * @uses stringstream.
 * @param string label - The label for the value
 * @param double value - The value associated with the label
 * @param char separator - The character that separates the label and the value
 * @return string - Comprised of a label, followed by a space, followed by a
 *                  separator character, followed by a space, followed by a
 *                  floating-point value
 */
string MakeString(string label, double value, char separator) {
  stringstream ss;
  ss << label << " " << separator << " " << value;
  string complete_string = ss.str();
  return complete_string;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Return the first character of a length 1 string. If the value is of
 * length 0 or of length > 1, return the null character ('\0').
 * @param string value - The expected single character
 * @return char - The first character of the string or null character ('\0')
 *                when value is length 0 or value is length > 1
 */
char StringToChar(string value) {
  char single_char;
  
  if ((value.size() < 1) || (value.size() > 1)) {
    single_char = '\0';
  }
  else {
    single_char = static_cast<char>(value.at(0));
  }
  
  return single_char;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected integer value (such as a string
 * captured from stdin) into an integer. If value is not valid as an integer,
 * return 0.
 * @uses stringstream
 * @param string value - The expected integer value
 * @return int - An integer representing the value, or 0 on failure
*/

int StringToInt(string value) {
  // THIS FUNCTION PROVIDED AS AN EXAMPLE AND IS ALREADY COMPLETE!
  int ivalue = 0;
  stringstream converter(value);
  converter.exceptions(ios_base::failbit);
 
  try {
    converter >> ivalue;
  } catch (ios_base::failure f) {
  }

  return ivalue;
  
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected floating-point value (such as a
 * string captured from stdin) into a double. If value is not valid as a double
 * return 0.
 * @uses stringstream
 * @param string value - The expected floating-point value
 * @return double - A double representing the value, or 0 on failure
*/

double StringToDouble(string value) {
    stringstream ss;
    ss << value;
    double captured_double = 0;
    ss >> captured_double;
    
    return captured_double;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an boolean value (such as a string captured from
 * stdin) into a bool. Return true if the first character is 'T'
 * (case-insensitive), false if the first character is 'F' (case-insensitive),
 * and false on anything else.
 * @param string value - The expected string to start with either 'T' or 'F'
 * @return bool - If the first character is 'T' (case-insensitive) return true.
 *                If the first character is 'F' (case-insensitive) return false.
 *                Return false on anything else.
*/

bool StringToBool(string value) {
  bool b_value = false;
  
  if (value.size() > 0) {
    if ((value.at(0) == 'T') || (value.at(0) == 't'))
      b_value = true;
  }
  
  return b_value;
}
