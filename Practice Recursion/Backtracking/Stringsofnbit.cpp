#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}

void binary(int arr[], int n, int i)
{
    if (i == n)
    {
        print(arr, n);
    }
    else
    {
        arr[i] = 0;
        binary(arr, n, i + 1);
        arr[i] = 1;
        binary(arr, n, i + 1);
    }
}

int main()
{
    int arr[2];
    binary(arr, 2, 0);
}