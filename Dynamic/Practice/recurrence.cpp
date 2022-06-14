#include <iostream>
#include <cstring>
using namespace std;

// By memo

int memo[1000];

int recu(int n)
{
    if (n == 0 || n == 1)
    {
        return 2;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += 2 * recu(i) * recu(i - 1);
    }
    memo[n] = sum;
    return memo[n];
}

int main()
{
    memset(memo, -1, sizeof(memo));
    cout
        << recu(5) << "\n";
}