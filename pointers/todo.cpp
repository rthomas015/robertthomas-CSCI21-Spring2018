/*
 * Fix this code to accurately determine if it is an anagram.
 * You do not have to delete anything just modify.
 */

#include <iostream> 
#include <iostream> 
#include <cstring> 
using namespace std;   

int main() {
    string firststr = "";
    int nameLength = 0;
    char * name = new char;

    cout << "Please enter a 10 letter word or less" << endl;
    cin >> name;

    char * head  = name;
    char * tail = name;
    nameLength = strlen(name);

    cout << "Your word is " << firststr << endl;

    if (nameLength<10)
    {
         while (*head != '\0')
         {
                cout << *head;
                head++;
         }
     }
     else
     {
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
     }

     cout << endl;

     tail = &name[strlen(name) - 1];

     if (nameLength < 10)
     {
          while (tail != name)
          {
                 cout << *tail;
                 tail--;
          }
     }
     cout << endl;

     head = name;
     tail = &name[strlen(name) - 1];

     head++;
     tail--;

     if (*head == *tail)
     {
         cout << "It is an palindrome!" << endl;
     }
     else
     {
         cout << "It is not an palindrome" << endl;
     }

     return 0; 
}