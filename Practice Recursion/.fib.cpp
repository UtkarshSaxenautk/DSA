#include <iostream>
using namespace std;

int fib(int x)
{
    if (x <= 1)
    {
        return x;
    }
    return (fib(x - 1) + fib(x - 2));
}

int main()
{
    int n = 5;
    cout << fib(n);
}