#include <iostream>
#include <vector>
using namespace std;

int knap(int val[], int wei[], int n, int cap)
{
    int table[n + 1][cap + 1];

    // For zero weight value will be zero so :

    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 0;
    }

    // For zero item value again will be zero so :

    for (int i = 0; i <= cap; i++)
    {
        table[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            // If weight is greater  than j take previous value from table

            if (wei[i - 1] > j)
            {
                table[i][j] = table[i - 1][j];
            }

            // Else find maximum value between previous and value + value of remaining weight in tbale for previous item

            else
            {
                table[i][j] = max(table[i - 1][j], val[i - 1] + table[i - 1][j - wei[i - 1]]);
            }
        }
    }
    return table[n][cap];
}

int main()
{
    int V[] = {10, 40, 30, 50};
    int Wei[] = {5, 4, 6, 3};
    int W = 10;
    cout << knap(V, Wei, 4, W) << "\n";
}