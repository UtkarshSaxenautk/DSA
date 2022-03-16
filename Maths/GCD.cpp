#include <iostream>
using namespace std ;


template <typename T>
T GCD(T a , T b)
{
    while(a != b) {
        if(a > b) {
            a = a - b ;
        }
        else {
            b = b - a;
        }
    }
    return a ;
}

template <typename T>
T Gcd(T a , T b) {
    if(b == 0) {
        return a ;
    }
    Gcd(b , a % b);
}


int main() {
      #ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("./input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("./output.txt", "w", stdout);
 
    #endif      
    int x , y ;
    cin >> x >> y ;
    cout << GCD(x , y) << "\n" ;
    double x1, y1 ;
    cin >> x1 >> y1 ;
    cout << GCD(x1 , y1) << "\n" ;
    int x2 , y2 ;
    cin >> x2 >> y2 ;
    cout << Gcd(x2 , y2) << "\n" ;
}