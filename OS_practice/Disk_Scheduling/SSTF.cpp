#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SSTF(int order[], int n, int s)
{
    vector<int> res;
    int start = s;
    while (res.size() != n)
    {
        int min_diff = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (find(res.begin(), res.end(), order[i]) == res.end())
            {
                int dif = abs(order[i] - start);
                if (dif < min_diff)
                {
                    min_diff = dif;
                    index = i;
                }
            }
        }

        start = order[index];
        cout << start << "\n";
        res.push_back(order[index]);
    }

    int total = abs(res[0] - s);
    for (int i = 1; i < res.size(); i++)
    {
        cout << total << "\n";
        total += abs(res[i - 1] - res[i]);
    }
    cout << total << "\n";
}

int main()
{
    int n = 7;
    int order[] = {82, 170, 43, 140, 24, 16, 190};
    SSTF(order, n, 50);
}
