#include <iostream>
#include <cmath>
using namespace std ;

void PowerSet(string s) {
    int n = s.length();
    int size = pow(2 ,n);
    for(int counter = 0 ; counter < size ; counter++) {
        for(int j =0 ; j < n ; j++) {
            if((counter & (1 << j)) != 0) {
                cout << s[j];
            }
        }
        cout << "\n";
    }


}

int main() {
    string s = "abc";
    PowerSet(s);
}