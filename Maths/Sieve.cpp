#include <iostream>
using namespace std ;


void Sieve(int n) {
    if(n == 1) {
        cout << "NO prime numbers " << "\n" ;

    }
    else {
        bool prime[n + 1];
        for(int i = 2 ; i <= n ; i++) {
            prime[i] = true ;
        }
        prime[0] = prime[1] = false ;

        for(int i = 2 ; i*i <= n ; i++)
        {
            if(prime[i]) {
                for(int j = i * 2 ; j <= n ; j= j + i) {
                    prime[j] = false ;
                }
            }
        }

        for(int i = 2 ; i <= n ; i++)
        {
            if(prime[i]) {
                cout << i << " " ;
            }
        }
    }
}

int main() {
     #ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("./input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("./output.txt", "w", stdout);
 
    #endif   
    Sieve(19);
}