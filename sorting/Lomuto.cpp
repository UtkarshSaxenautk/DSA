#include <iostream>
using namespace std;

int Lomuto(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    int temp = 0;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[h];
    arr[h] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;
}

int main()
{
    int arr[] = {3, 4, 1, 7, 9, 6, 5};
    cout << Lomuto(arr, 0, 6) << "\n";
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}