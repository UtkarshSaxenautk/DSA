#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PFS(string name[], int burst[], int p[], int n)
{
    vector<pair<int, pair<string, int>>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(p[i], make_pair(name[i], burst[i])));
    }
    sort(v.begin(), v.end());
    int avturnaround = 0;
    int avwaiting = 0;
    int waiting = 0;
    int turnaround = 0;
    for (int i = 0; i < v.size(); i++)
    {
        turnaround += v[i].second.second;
        avturnaround += turnaround;
        cout << i << ")  " << v[i].second.first << "   " << v[i].second.second << "   " << turnaround << "   " << waiting
             << "\n";
        avwaiting += waiting;
        waiting += v[i].second.second;
    }

    cout << "Average Turnaround time : " << avturnaround / n << "\n";
    cout << "Average Waiting Time : " << avwaiting / n << "\n";
}

int main()
{
    int n = 4;
    string name[] = {"first", "second", "third", "forth"};
    int burst[] = {21, 3, 6, 2};
    int p[] = {2, 1, 4, 3};
    PFS(name, burst, p, n);
}