#include <iostream>
#include <string>

using namespace std;

//GCD
//Greatest common denominator
//@param a = first number
//@param b = second number
//@return the greatest common denominator
int gcd (int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd (b, (a % b));
    }
}

//LCM
//Least common multiple
//@param a = first number
//@param b = second number
//@return the least common multiple
//*this one doesn't really seem recursive unless you count the recursion in the gcd function*
int lcm (int a, int b) {
    if (a == 1) {
        return 1;
    }
    else {
        return ((a * b) / gcd (a,b));
    }
}


int main () {
    int choice = 1,
        a = 0,
        b = 0;
    
    cout << "The GCD of 10 and 20 is: " << gcd (10,20) << endl
         << "The GCD of 17 and 32 is: " << gcd (17,32) << endl
         << "The GCD of 45 and 15 is: " << gcd (45,15) << endl;
    
    cout << "Run again? 1 for Yes any other digit for No: ";
    cin >> choice;

    while (choice == 1) {
        cout << "Enter two positive integers: ";
        cin >> a;
        cin >> b;
        cout << "The GCD of " << a << " and " << b << " is " << gcd (a,b) << endl;
        cout << "Run again? 1 for Yes any other digit for No: ";
        cin >> choice;
    }
    
    cout << "The LCM of 10 and 20 is: " << lcm (10,20) << endl
         << "The LCM of 17 and 32 is: " << lcm (17,32) << endl
         << "The LCM of 45 and 15 is: " << lcm (45,15) << endl;
    
    cout << "Run again? 1 for Yes any other digit for No: ";
    cin >> choice;
    
    while (choice == 1) {
        cout << "Enter a positive integer: ";
        cin >> a;
        cout << "Enter a second positive integer: ";
        cin >> b;
        cout << "The LCM of " << a << " and " << b << " is " << lcm (a,b) << endl;
        cout << "Run again? 1 for Yes any other digit for No: ";
        cin >> choice;
    }
        
    return 0;
}