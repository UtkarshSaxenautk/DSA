#include <iostream>
using namespace std;

void Knap(int W, int val[], int wei[], int n)
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wei[i - 1] > j)
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = max(table[i - 1][j], val[i - 1] + table[i - 1][j - wei[i - 1]]);
            }
        }
    }
    cout << "max valeu : " << table[n][W] << "\n";

    int res = table[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--)
    {
        if (res == table[i - 1][w])
        {
            continue;
        }
        else
        {
            cout << "---" << wei[i - 1] << "\n";
            res -= val[i - 1];
            w -= wei[i - 1];
        }
    }
}

int main()
{
    int V[] = {4, 6, 7, 9, 10};
    int Wei[] = {3, 5, 7, 8, 9};
    int W = 22;
    Knap(W, V, Wei, 5);
}