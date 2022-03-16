#include <iostream>
using namespace std ;


bool Isprime(int n){
    if(n == 1) {
        return false ;

    }
    for(int i = 2 ; i * i <= n ; i++) {
        if(n % i == 0) {
            return false ;
        }
    }
    return true ;
}

void Printnumber(int n) {
    if(n == 1) {
        cout << "NO prime number" << "\n" ;
    }
    for(int i = 2 ; i <= n ; i++) {
        if(Isprime(i)) {
            cout << i << " " ;
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
int n ;
cin >> n ;
if(Isprime(n)) {
    cout << n << " is prime" << "\n" ;
}
else {
    cout << n << " is not prime number " << "\n" ;
}

Printnumber(19);

}