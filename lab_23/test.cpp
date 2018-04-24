#include <iostream>

using namespace std;

int power (int x, int n) {
    if (n==0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return (power(x,n/2) * power (x,n/2));
    }
    else {
        return (x * power (x,n-1));
    }
}

int main () {
    
    cout << "2^2: " << power (2,3) << endl;
    cout << power (3,6);
    
    return 0;
}