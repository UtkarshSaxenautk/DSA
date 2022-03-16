#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std ;

int firstsetbit(int n) {
    string str = bitset<64>(n). to_string();
        int count =0 ;
        
        for(int i = 63 ; i >= 0 ; i--) {
            if(str[i] == '1') {
               count++ ;
                break ;
            }
            count++ ;
        }
        
        if(count == 64) {
            return 0 ;
        }
    
    return count ;
}

int main() {
    int n = 8 ;
    cout << firstsetbit(n) << "\n";
}