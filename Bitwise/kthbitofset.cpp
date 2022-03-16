#include <iostream>
using namespace std ;

bool CheckOnebyLeftShift(int n , int k) {
    if(n & (1 << (k-1)) != 0) {
        return true ;
    }
    return false ;
}

bool CheckOnebyRightShift(int n , int k) {
    if(1 && (n >> (k-1)) == 1) {
        return true ;
    }
    return false ;

}


int main() {
    cout << CheckOnebyLeftShift(4 , 1) << "\n";
    cout << CheckOnebyLeftShift(13 , 2) << "\n";
    cout << CheckOnebyRightShift(13 , 3) << "\n";
    cout << CheckOnebyRightShift(500 , 4) << "\n";
}