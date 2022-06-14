#include <iostream>
#include <algorithm>
using namespace std;

int Lis(int arr[], int n)
{
    int temp[n];
    temp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        temp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                temp[i] = max(temp[i], temp[j] + 1);
            }
        }
    }
    int ans = *max_element(temp, temp + n);
    return ans;
}

int main()
{
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    cout << Lis(arr, 7);
}