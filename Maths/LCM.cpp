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
   return Gcd(b , a % b);
}


template <typename T>
T LCM(T a , T b) {
    T temp =  (a * b) / GCD(a , b) ;
    return temp ;
}

template <typename T>
T Lcm(T a , T b) {
    T temp = ( a * b) / Gcd( a, b);
    return temp ;
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
    cout << LCM(x , y) << "\n" ;
    int x1, y1 ;
    cin >> x1 >> y1 ;
    cout << Lcm(x1 , y1) << "\n" ;
    int x2 , y2 ;
    cin >> x2 >> y2 ;
    cout << LCM(x2 , y2) << "\n" ;
}