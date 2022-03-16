#include <iostream>
#include <bitset>
using namespace std ;


int main() {
    int a = 8 ;
    int b = 4 ;
    cout << (a & b) << "\n";
    //cout << (a : b) << "\n";
    cout << (a | b) << "\n";
    cout << (a ^ b) << "\n";
    //Left-shift operator
    cout << (a << 1) << "\n";
    cout << (a >> 2) << "\n";
    cout << (~a) << "\n";

}