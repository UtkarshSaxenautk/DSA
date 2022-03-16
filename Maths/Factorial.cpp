#include <bits/stdc++.h>
using namespace std ;


int factorial(int n)
{
    if(n == 0)
    {
        return 1 ;
    }
    return n * factorial(n - 1);
}


int factorial1(int n)
{
    int temp = 1 ;
    int i =n ;
    while(i >= 1)
    {
        temp *= i ;
        i-- ;
    }
    return temp ;
}



int main()
{
    cout << factorial(5) << "\n" ;
    cout << factorial1(5) << "\n" ;
}