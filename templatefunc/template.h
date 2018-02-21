/*
 * Name        : template.h
 * Author      : Robert Thomas
 * Description : Various functions using templates. Please note you can just
 *               write the definitions in here. No need for prototypes.
 */

#ifndef template_h
#define template_h

#include <string>
#include <sstream>  
#include <iostream>
#include <iomanip>

using namespace std;


/*
 * Function Name: PrepareForDisplay
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3". Please note the array can be of any type.
 * If the template function outputs doubles, they should be to a precision of 2.
 * @uses stringstream
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @param char separator - The separator character to use in the returned
 *                         string. Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
 

template<typename T>
string PrepareForDisplay (T an_array[],int size_of_array, char separator = ',') {
      stringstream ss;
      ss << setprecision(2) << fixed << an_array[0];
      for (int i=1;i<(size_of_array);i++) {
          ss << separator << an_array[i] ;
      } 
      
      return ss.str();
}

/*
 * Function Name: HasValue
 * Test to see if an array contains a specified value.
 * @param T values -  An array of any type
 * @param unsigned int size - The size of the array
 * @param T value_to_find - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */

template<typename T>
bool HasValue (T an_array[], unsigned int size_of_array, T value_to_find) {
    bool has_value = false;
    
    for (int i=0;i<size_of_array;i++) {
        if (an_array[i] == value_to_find) {
            has_value = true;
        }
    }
    
    return has_value; 
}


/*
 * Function Name: ValueAt
 * Return the value from an array at a specified index.
 * @param T values -  An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index - The position in the array from which to return a
 *                             value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                     the array, else it will be set to false
 * @return T - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns a zero representation of
 *               the type and sets error to true. To get a zero representation
 *               you can return T()
 */
 
template<typename T>
T ValueAt (T an_array[], unsigned int size_of_array, unsigned int position, bool &error) {
    T value_at;
    error = false;
    
    if (position >= size_of_array) {
        error = true;
        return T();
    }
    else {
        value_at = an_array[position];
    }
    
    return value_at; 
}


/*
 * Function Name: Sum
 * Return the "sum" of the values in the array. Your initial sum should be set
 * to "zero" in your algorithm. To do this use T().
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */
 
template<typename T>
T Sum (T an_array[], unsigned int size_of_array) {
    T values = T();
    
    for (int i=0;i<size_of_array;i++) {
        values = values + an_array[i];
    }
    
    return values; 
}

/*
 * Function Name: SwapValues
 * Swap the positions of two values in an array. The two index values must be
 * valid for the array.
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index1 - The position of the first value to be swapped
 * @param unsigned int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
 
template<typename T>
bool SwapValues (T an_array[], unsigned int size_of_array, unsigned int index1, unsigned int index2) {
    bool swap_occurred = false;
    T place_holder = T();
    
    if ((index1 < size_of_array) && (index2 < size_of_array)) {
        place_holder = an_array[index1];
        an_array[index1] = an_array[index2];
        an_array[index2] = place_holder;
        swap_occurred = true;
    }
    
    return swap_occurred;
}


#endif