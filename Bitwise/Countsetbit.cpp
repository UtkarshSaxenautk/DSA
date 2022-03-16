#include <iostream>
#include <bitset>
using namespace std ;

int table[256];

void Initialize() {
    table[0] = 0 ;
    for(int i =0 ; i < 256 ; i++) {
        table[i] = (i & 1) + table[i / 2];
    }
}

int count(int n) {
    int res = table[n & 0xff];
    n = n >> 8 ;
    res = res + table[n & 0xff];
    n = n >> 8 ;
    res = res + table[n & 0xff];
    n = n >> 8 ;
    res = res + table[n & 0xff];
    return res ;
}

int countbitsbybrianAlgo(int n) {
    int res = 0 ;
    while(n > 0) {
        n = (n & (n -1));
        res++ ;
    }
    return res ;
}
int countbynaive(int n) {
    int res = 0 ;
    while(n > 0) {
    if(n % 2 != 0) {
        res++ ;
    }
    n = n / 2;
    }
    return res ;
}



int main() {
    int n ;
    cin >> n ;
    cout << countbitsbybrianAlgo(n) << "\n";
    cout << countbynaive(n) << "\n";
    cout << count(n) << "\n";
}