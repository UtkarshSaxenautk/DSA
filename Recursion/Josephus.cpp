#include <iostream>
using namespace std ;


int Jos(int n , int k) {
    if(n == 1) {
       return 0 ;
    }
    else{
        return (Jos(n-1 ,k) + k) % n ;
    }
}

int main() {
    int n = 5 , k = 3 ;
    cout << Jos(n , k) << "\n";
    int m = 4 ;
    cout << Jos(m , k);
}