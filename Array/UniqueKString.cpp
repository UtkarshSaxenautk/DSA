#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    map<string, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            mp.insert(arr[i], new pair<int, int>(mp[arr[i]].first + 1, mp[arr[i]].second));
        }
        else
        {
            mp.insert(arr[i], new pair<int, int>(1, i));
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]].first == 1)
        {
            if (k == 0)
            {
                cout << arr[i] << "\n";
                break;
            }
            k--;
        }
    }
}