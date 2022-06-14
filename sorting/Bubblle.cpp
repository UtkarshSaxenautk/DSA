#include <iostream>
using namespace std;

void boolSort(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                count++;
            }
        }
    }
    cout << "After Sorting and comparisons : " << count << "\n";
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {5, 2, 1, 4, 3, 7, 6};
    display(arr, 7);
    boolSort(arr, 7);
    display(arr, 7);
}