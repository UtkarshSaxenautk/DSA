#include <iostream>
#include <vector>
using namespace std;

int Mchain(int arr[], int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        res = min(res, Mchain(arr, i, k) + Mchain(arr, k, j) + arr[i] * arr[j] * arr[k]);
    }
    return res;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    cout << Mchain(arr, 0, 4);
}