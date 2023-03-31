#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int No_of_Increments(int arr[], int n)
{
    int answer = 0;
    sort(arr, arr + n);
    unordered_map<int, int> mp;
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        mp[arr[i]]++;
        temp = arr[i];
        if (arr[i] == arr[i + 1] || mp.find(arr[i + 1]) != mp.end())
        {
            answer += temp + 1 - arr[i + 1];
            arr[i + 1] = temp + 1;
        }
    }
    return answer;
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

    cout << "Number of Increments to be done in array to make it of distinct element  : " << No_of_Increments(arr, n) << "\n";
}