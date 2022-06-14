#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second > b.second);
}

// Knapsack is maximum value that can be achieved by inserting with given item under given capacity

int Knap(int value[], int weight[], int n, int cap)
{
    // On basis of greedy it can done in two ways and its not optimized way

    // First sort according to increasing weight

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(weight[i], value[i]));
    }

    sort(v.begin(), v.end());
    int rem_cap = cap;
    int max_by_weight = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first > rem_cap)
        {
            break;
        }
        max_by_weight += v[i].second;
        rem_cap -= v[i].first;
    }

    // Second sort according to decreasing value
    sort(v.begin(), v.end(), sortbysec);
    int rem = cap;
    int max_by_val = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first > rem)
        {
            break;
        }
        max_by_val += v[i].second;
        rem -= v[i].first;
    }

    return max(max_by_weight, max_by_val);
}

int main()
{
    int V[] = {10, 40, 30, 50};
    int Wei[] = {5, 6, 4, 3};
    int W = 10;
    cout << Knap(V, Wei, 4, W) << "\n";
}