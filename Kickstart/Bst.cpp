#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string s, char c)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != c)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool res = true;
        for (int j = 0; j < arr[i].length(); j++)
        {
            cout << check(s, arr[i][j]) << "\n";
            if (check(s, arr[i][j]) == false)
            {
                res = false;
                break;
            }
        }
        if (res == false)
        {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}