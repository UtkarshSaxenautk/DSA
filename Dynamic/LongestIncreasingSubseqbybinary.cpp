#include <iostream>
#include <cstring>
using namespace std;

int cylofnumber(int tail[], int l, int h, int x)
{
    while (l > h)
    {
        int m = l + (h - l) / 2;
        if (tail[m] <= x)
        {
            l = m;
        }
        else
        {
            h = m + 1;
        }
    }
    return l;
}

int Lis(int arr[], int n)
{
    int tail[n];
    memset(tail, -1, sizeof(tail));
    tail[0] = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int index = cylofnumber(tail, 0, len, arr[i]);
            tail[index] = arr[i];
        }
    }
    return len;
}

int main()
{
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    cout << Lis(arr, 7);
}