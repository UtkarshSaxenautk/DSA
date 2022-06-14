#include <iostream>
#include <vector>
using namespace std;

int memo[10000][10000];

int Lcs(string s1, string s2, int m, int n, string s)
{
    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }
    if (m == 0 || n == 0)
    {
        memo[m][n] = 0;
    }
    else
    {
        if (s1[m - 1] == s2[n - 1])
        {
            s.push_back(s1[m - 1]);
            memo[m][n] = 1 + Lcs(s1, s2, m - 1, n - 1, s);
        }
        else
        {
            memo[m][n] = max(Lcs(s1, s2, m - 1, n, s), Lcs(s1, s2, m, n - 1, s));
        }
    }
    return memo[m][n];
}

int main()
{
    int n, m;
    m = 4;
    n = 3;

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            memo[i][j] = -1;
        }
    }
    string s1 = "AXYZ";
    string s2 = "BAZ";
    string s = "";
    int lc = Lcs(s1, s2, 4, 3, s);
    cout << lc << "\n";
    cout << s << "\n";
}