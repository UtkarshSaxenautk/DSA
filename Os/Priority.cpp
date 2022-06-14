#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes : "
         << "\n";
    cin >> n;
    cout << "Enter process name with priority and burst space "
         << "\n";
    vector<pair<pair<int, int>, string>> v;
    for (int i = 0; i < n; i++)
    {
        string temp;
        int p, t;
        cin >> temp >> p >> t;
        v.push_back(make_pair(make_pair(p, t), temp));
    }

    priority_queue<pair<pair<int, int>, string>, vector<pair<pair<int, int>, string>>, greater<pair<pair<int, int>, string>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(make_pair(v[i].first.first, v[i].first.second), v[i].second));
    }

    int waiting = 0;
    while (!pq.empty())
    {
        cout << pq.top().second << "  :  " << waiting << "\n";

        waiting += pq.top().first.second;
        pq.pop();
    }

    cout << "Turn around time : " << waiting << "\n";
}