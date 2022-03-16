#include <iostream>
using namespace std ;

void Subset(string s , string curr = "" , int i =0 ) {
    if(i == s.length()) {
        cout << curr << "\n";
        return ;
    }
    Subset(s , curr , i+ 1);
    Subset(s , curr + s[i], i+ 1);
}


int main(){
     string  ss = "ABC";
    Subset(ss);
}








