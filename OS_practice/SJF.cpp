#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void SJF(string name[], int burst[], int n)
{
    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(burst[i], name[i]));
    }

    int avturnaround = 0;
    int avwaiting = 0;
    int waiting = 0;
    int turnaround = 0;

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        turnaround += v[i].first;
        avturnaround += turnaround;
        cout << i << ")  " << v[i].second << "   " << v[i].first << "   " << turnaround << "   " << waiting
             << "\n";
        avwaiting += waiting;
        waiting += v[i].first;
    }
    cout << "Average Turnaround time : " << avturnaround / n << "\n";
    cout << "Average Waiting Time : " << avwaiting / n << "\n";
}

int main()
{
    int n = 4;
    string name[] = {"first", "second", "third", "forth"};
    int burst[] = {21, 3, 6, 2};

    SJF(name, burst, n);
}