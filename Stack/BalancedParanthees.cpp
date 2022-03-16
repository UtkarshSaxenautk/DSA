#include <iostream>
#include <stack>
using namespace std ;

bool chechchar(char *a ,char *b) {
    if((*a == '(' && *b == ')')|| (*a == '{' && *b == '}')||(*a == '[' && *b == ']'))
    {
        return true ;

    }
    return false ;
}

bool Isbalanced(string s){
    stack<char> st ;
    for(int i=0 ; i < s.length() ; i++)

     {
       if( s[i] == '(' || s[i] == '{' || s[i] == '[')
       {
           st.push(s[i]);
       }
       else {
           if(st.empty() == true){
               return false ;
           }
           else if(chechchar(&st.top(), &s[i]) == false)
           {
               return false ;
           }
           else {
               st.pop();
           }
       }
       
    }
    return (st.empty() == true);
}

int main() {
  string test1 , test2 ;
  cin >> test1 >> test2;
  cout << Isbalanced(test1) << "\n" ;
    cout << Isbalanced(test2) << "\n" ;

}