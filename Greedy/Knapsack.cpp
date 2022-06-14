#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Total number of items : "
         << "\n";
    cin >> n;
    vector<pair<pair<int, int>, int>> item;

    int max_capacity;
    cout << "Enter maximum capacity : "
         << "\n";
    cin >> max_capacity;
    cout << "Enter weight and capacity with space : "
         << "\n";

    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        item.push_back(make_pair(make_pair(w, v), i + 1));
    }

    sort(item.begin(), item.end());

    for (int i = 0; i < n; i++)
    {
        cout << item[i].second << " : " << item[i].first.first << " with value " << item[i].first.second << "\n";
    }

    int res = 0;
    int cap = 0;
    int i = 0;
    while (cap <= max_capacity)
    {
        cout << item[i].second << " + ";
        res += item[i].first.second;
        cap += item[i].first.first;
        i++;
        if (i <= n - 1 && cap + item[i + 1].first.first >= max_capacity)
        {
            break;
        }
    }
    cout << "\n"
         << res << "\n";
}