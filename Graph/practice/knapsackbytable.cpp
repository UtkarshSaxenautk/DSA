#include <iostream>
using namespace std;

void knap(int W, int val[], int w[], int n)
{
    int table[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 0;
    }
    for (int i = 0; i <= W; i++)
    {
        table[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (j < w[i - 1])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - w[i - 1]] + val[i - 1]);
            }
        }
    }

    cout << "Ans  :" << table[n][W] << "\n";
    int res = table[n][W];
    int x = W;
    // cout << n << " weight : " << w[n] << "\n";
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == table[i - 1][x])
        {
            continue;
        }
        else
        {
            cout << i << " weight : " << w[i - 1] << "\n";
            res -= val[i - 1];
            x -= w[i - 1];
        }
    }
}

int main()
{
    int V[] = {10, 40, 30, 50};
    int Wei[] = {5, 4, 6, 3};
    int W = 10;
    knap(W, V, Wei, 4);
}