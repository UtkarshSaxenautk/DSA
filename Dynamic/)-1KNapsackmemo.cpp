#include <iostream>
#include <cstring>
using namespace std;

int memo[1000][1000];

int Knap(int W, int Val[], int Wei[], int n)
{
    if (W == 0 || n == 0)
    {
        memo[n][W] = 0;
    }

    if (memo[n][W] != -1)
    {
        return memo[n][W];
    }

    if (W < Wei[n - 1])
    {
        memo[n][W] = Knap(W, Val, Wei, n - 1);
    }

    else
    {
        memo[n][W] = max(Knap(W, Val, Wei, n - 1), Knap(W - Wei[n - 1], Val, Wei, n - 1) + Val[n - 1]);
    }

    return memo[n][W];
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int V[] = {10, 40, 30, 50};
    int Wei[] = {5, 4, 6, 3};
    int W = 10;
    cout << Knap(W, V, Wei, 4);
}