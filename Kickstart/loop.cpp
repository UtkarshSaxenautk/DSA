#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        int count = 0;
        int curr = 0;
        char c;
        for (int i = 0; i < n; i++)
        {
            int distance;
            char direction;
            cin >> distance >> direction;
            if (i == 0)
            {
                curr += distance;
                c = direction;
            }
            if (direction == c && i != 0)
            {
                curr += distance;
            }
            if (direction != c)
            {
                curr -= distance;
                c = direction;
            }
            if (abs(curr) >= l)
            {
                curr = abs(curr) - l;
                count++;
            }
        }
        cout << count << "\n";
    }
}