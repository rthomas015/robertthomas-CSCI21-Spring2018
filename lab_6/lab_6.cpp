/*
 * Name        : lab_6.cpp
 * Author      : FILL IN
 * Description : Working with Arrays
 */

#include "lab_6.h"


string PrepareForDisplay(int values[], int size, char separator = ',') {
    stringstream ss_object;
    string final_string = "";
    ss_object << values[0];
    
    for (int i=1;i<size;i++) {
        ss_object << separator << values[i];
    }
    
    final_string = ss_object.str();
    return final_string;
}


bool HasValue(int values[], int size, int value){
    bool test_value = false;
    
    for (int i=0;i<size;i++) {
        if (values[i] == value) {
            test_value = true;
        }
    }
    
    return test_value;
}

/*
 * Return the value from an array at a specified index.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int index - The position in the array from which to return a value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                      the array, else it will be set to false
 * @return int - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns 0 and sets error to true
 */
 
int ValueAt(int values[], int size, int index, bool &error) {
    int value = 0;
    error = false;
    
    if (index < size) {
        value = values[index];
    }
    else {
        error = true;
    }
    
    return value;
}


/*
 * Return the sum of the values in an integer array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @return int - The sum of the values in the array
 */
int Sum(int values[], int size) {
    int summation = 0;
    for (int i=0;i<size;i++) {
        summation = summation + values[i];
    }
    
    return summation;
}


/*
 * Swap the positions of two values in an integer array. The two
 * index values must be valid for the array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @param int index1 - The position of the first value to be swapped
 * @param int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
bool SwapValues(int values[], int size, int index1, int index2) {
    bool swapsuccess = false;
    int place_holder = 0;
    
    if ((index1 < size) && (index2 < size) && (index1 >= 0) && (index2 >= 0)) {
        place_holder = values[index1];
        values[index1] = values[index2];
        values[index2] = place_holder;
        swapsuccess = true;
    }

    return swapsuccess;
}