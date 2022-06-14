#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans(int val[], int w[], int cap, int n)
{
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        int temp = val[i] / w[i];
        v.push_back(make_pair(temp, make_pair(val[i], w[i])));
    }

    sort(v.begin(), v.end(), greater<>());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.second <= cap)
        {
            cap -= v[i].second.second;
            res += v[i].second.first;
        }
        else
        {
            res += (v[i].second.first * cap) / v[i].second.second;
            break;
        }
    }

    return res;
}

int main()
{
    int val[] = {600, 500, 400};
    int w[] = {50, 20, 30};
    cout << ans(val, w, 70, 3);
}