#include <iostream>
using namespace std ;

int Maxpiece(int n , int a , int b , int c) {
    if(n == 0) {
        return 0 ;
    }
    if( n < 0) {
        return -1 ;
    }
    int res = max(Maxpiece(n -a, a , b , c) , max(Maxpiece(n - b , a , b , c), Maxpiece(n - c , a , b , c)));
    if(res == -1) {
        return -1 ;
    }
    return res + 1 ;
}

int main() {
    cout << Maxpiece(5 , 2 , 5 , 1) ;
}