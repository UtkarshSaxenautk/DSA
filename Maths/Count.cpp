#include <iostream>
#include <sstream>
#include <string>
using namespace std ;

int count(int number)
{
    int temp = 0 ;
    while(number != 0 )
    {
        number = number / 10 ;
        temp++ ;
    }
    return temp ;
}

int count2(int number)
{
    stringstream ss ;
    ss << number ;
    string s ;
    ss >> s ;
    return s.length();
     
}


int main()
{
    int n ;
    cin >> n ;
    cout << count(n) << "\n" ;
    cout << count2(n) << "\n" ;
}