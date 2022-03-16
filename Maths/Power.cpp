#include<iostream>
using namespace std ;


template <typename T>
T power(T x , int n) {
    T temp = 1 ;
    for(int i = 1; i <=n ; i++)
    {
        temp = temp * x ;
    }
    return temp ;
}

template <typename T>
T poweer(T x, int n) {
    if( n == 0) {
       return 1 ;
    }

    T temp = power(x , n/ 2);
    temp= temp * temp ;
   if( n % 2 == 0) {
       return temp ;
   }
   else {
       return temp * x ;
   }
}


int main() {
     #ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("./input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("./output.txt", "w", stdout);
 
    #endif   
    cout << power(2, 3) << "\n" ;
    cout << power(3 , 2) << "\n" ;
    cout << poweer(5 , 3) << "\n" ;
    cout << poweer(2 , 5) << "\n" ;
}