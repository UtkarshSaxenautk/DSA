#include <iostream>
#include <cstring>
using namespace std;

int memo[1000][1000];

int knap(int W, int val[], int w[], int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (memo[n][W] != -1)
    {
        return memo[n][W];
    }
    else if (W < w[n - 1])
    {
        memo[n][W] = knap(W, val, w, n - 1);
    }
    else
    {
        memo[n][W] = max(knap(W, val, w, n - 1), val[n - 1] + knap(W - w[n - 1], val, w, n - 1));
    }
    return memo[n][W];
}

int main()
{
    memset(memo, -1, sizeof(memo));
    int V[] = {10, 40, 30, 50};
    int Wei[] = {5, 4, 6, 3};
    int W = 10;
    cout << knap(W, V, Wei, 4);
}