#include <iostream>
#include <sstream>
#include <string>
using namespace std ;


bool palindrome(int number)
{
    stringstream ss ;
    ss << number ;
    string s ;
    ss >> s ;
    int high = s.length() - 1 ;
    int low = 0 ;
    bool ispalindrome = true ;
    while (high > low)
    { 
        if(s[high] != s[low])
        {
          ispalindrome  = false ;
          break ;
        }
        low++ ;
        high-- ;
    }
    return ispalindrome ;

}



int main()
{
    int n ;
    cin >> n ;
    if(palindrome(n))
    {
        cout << n << " is palindrome " << "\n";

    }
    else{
        cout << n << " is not palindrome " << "\n";
    }
}