#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int countUnique(int arr[], int n)
{

    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int length = arr[i];
        int temp = 0;
        if (i - length + 1 >= 0)
        {
            temp = i - length + 1;
        }

        if ((mp.count(arr[i])) && (mp.at(arr[i]) >= temp))
        {
            temp = mp.at(arr[i]) + 1;
        }

        int x;
        if (temp + length - 1 >= n)
        {
            x = n - 1;
        }
        else
        {
            x = temp + length - 1;
        }
        if (x - temp + 1 != length)
        {
            continue;
        }
        count += min((i - temp + 1), (n - x));
        mp.insert({arr[i], i});
    }
    return count;
    // Set to store unique pairs
    // set<pair<int, int>> s;

    // // Make all possible pairs
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {

    //         s.insert(make_pair(i, j));
    //     }
    // }
    // int count = 0;
    // for (auto &x : s)
    // {
    //     int temp = x.second - x.first + 1;

    //     for (int i = x.first; i <= x.second; i++)
    //     {
    //         if (arr[i - 1] == temp)
    //         {
    //             count++;
    //             break;
    //         }
    //     }
    // }
    // return count;

    // set<pair<int , int> >::iterator itr;
    //  int count = 0 ;
    // for (itr = s.begin(); itr != s.end(); itr++) {
    //   int x = (*itr.second - *itr.first) + 1;
    //   if(find(arr , arr+n , x) != arr+n) {

    //       count++ ;
    //   }
    // }
    // //cout << endl;

    // // Return the size of the set

    // return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = countUnique(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
