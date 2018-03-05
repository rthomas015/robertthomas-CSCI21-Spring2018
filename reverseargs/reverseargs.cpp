/*Reverse args
  By: Robert Thomas
  Date: 3/1/2018 
  Description: Write a program that takes in arguments from the command line and reverses them, then outputs
  the information to the console (the reversed sentence)
*/

#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]) {
    string back_array[argc];
    int reversed_index = 0;
    
    //build the backwards array by looping through the argv array and looping through the 
    //backwards array (backwards) simultaneously and assiging values from the argv array to the backwards array
    for (int i=0; i<argc;i++) {
        reversed_index = argc - i - 1;
        back_array[reversed_index] = argv[i];
    }
    
    //delete program name from array
    back_array[argc-1] = "";
    
    //loop through array and output information
    for (int i=0; i<argc;i++) {
       cout << back_array[i] << " ";
    }
    
    //Output of Program:
    /*
    Test #1:
    rthomas015:~/workspace/reverseargs (master) $ ./reverseArgs.exe first_arg second_arg
    second_arg first_arg
    
    Test #2:
    rthomas015:~/workspace/reverseargs (master) $ ./reverseArgs.exe I love gorgonzola cheese, but I hate toothpaste
    toothpaste hate I but cheese, gorgonzola love I
    
    Test #3:
    rthomas015:~/workspace/reverseargs (master) $ ./reverseArgs.exe I would rather be at "UC Santa Barbara"
    UC Santa Barbara at be rather would I  rthomas015:~/workspace/reverseargs (master) $ 
    */
    
    return 0;
}