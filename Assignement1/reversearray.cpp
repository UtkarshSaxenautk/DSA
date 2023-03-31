#include <iostream>
using namespace std;

void Reverse_Array(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int n;
    cout << "Enter size of array" << endl;
    // Size of array
    cin >> n;
    int arr[n];
    // Enter element of array
    cout << "Enter elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Initialize array
    cout << "Initially array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
    Reverse_Array(arr, n);
    // After Processing
    cout << "Final array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}