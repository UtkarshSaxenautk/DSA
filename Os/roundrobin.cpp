#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "Number of processes : ";
    cin >> n;
    vector<pair<string, int>> v;
    cout << "Enter process name and burst time : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        int btime;
        cin >> s >> btime;
        v.push_back(make_pair(s, btime));
    }

    int freq = v[0].second;
    cout << "Here we taken timr fr : " << freq << "\n";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i].second;
    }
    while (!v.empty())
    {
        for (int i = 0; i < v.size(); i++)
        {

            if (v[i].second <= 0)
            {

                v.erase(v.begin() + i);
                break;
            }
            cout << v[i].first << " -> ";
            v[i].second -= freq;
        }
    }
    cout << "End"
         << "\n";

    cout << "\nTurn around time : " << sum << "\n";
}