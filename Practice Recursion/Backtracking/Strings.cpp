#include <iostream>
using namespace std;

void Print(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void K_String(string arr[], int n, int i)
{
    if (n == i)
    {
        Print(arr, n);
        return;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            arr[i] = to_string(j);
            K_String(arr, n, i + 1);
        }
    }
}

int main()
{
    string arr[2];
    K_String(arr, 2, 0);
}
