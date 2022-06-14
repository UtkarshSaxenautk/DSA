#include <iostream>
using namespace std;

int knap(int W, int Val[], int Wei[], int n)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }

    if (Wei[n - 1] > W)
    {
        return knap(W, Val, Wei, n - 1);
    }

    return max(knap(W, Val, Wei, n - 1), knap(W - Wei[n - 1], Val, Wei, n - 1) + Val[n - 1]);
}

int main()
{
    int V[] = {10, 40, 30, 50};
    int Wei[] = {5, 4, 6, 3};
    int W = 10;
    cout << knap(W, V, Wei, 4);
}
