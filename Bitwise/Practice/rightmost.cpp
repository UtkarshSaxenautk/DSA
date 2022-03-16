#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std ;

int firstsetbit(int m , int n) {
    string str = bitset<64>(n). to_string();
    string s = bitset<64>(m).to_string();
        int count =0 ;
        
        for(int i = 63 ; i >= 0 ; i--) {
            if(str[i] != s[i]) {
               count++ ;
                break ;
            }
            count++ ;
        }
        
        if(count == 64) {
            return -1 ;
        }
    
    return count ;
}

int main() {
    int n = 11 ;
    int m = 9 ;
    cout << firstsetbit(n , m) << "\n";
}