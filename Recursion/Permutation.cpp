#include <iostream>
using namespace std ;

void swap(int a , int b) {
    int temp = a ;
    a  = b ;
    b = temp ;
}

void Permutation(string s , int i=0) {
    if(i == s.length() -1) {
        cout << s << "\n" ;
        return ;
    }
    for(int j =i ; j < s.length() ; j++) {
        swap(s[i] , s[j]);
        Permutation(s , i +1);
        swap(s[j] , s[i]);
    }
}


int main() {
    string s = "ABC" ;
    Permutation(s );
}