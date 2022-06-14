#include <iostream>
using namespace std;

int Mchain(int arr[], int n)
{
    // As there are two parameters changing which both are n according to partition
    int table[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        // For condition j = i+1 means only one matrix so the result will be zero
        table[i][i + 1] = 0;
    }

    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            table[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                table[i][j] = min(table[i][j], table[i][k] + table[k][j] + arr[i] * arr[j] * arr[k]);
            }
        }
    }
    return table[0][n - 1];
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    cout << Mchain(arr, 5);
}