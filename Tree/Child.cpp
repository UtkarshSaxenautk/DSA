#include <iostream>
using namespace std ;

int main() {
  string s ;
  cin >> s ;
  int count = 00 ;
  if(s.size() < 3){
    return 0 ;
  }
  int x = 0 ;
  while(true){
    int i = 0 ; 
     // x = 0 ;
    while(i < s.size() - 2){
      if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
        s[i] = 'B';
        s[i+1] = 'C';
        s[i+2] = 'A';
        x++ ;
        i = 0 ;
      }
      else {
        i++ ;
      }
    }
    
    if(x == 0){
      break ;
    }
  }
  cout << x << "\n";
}