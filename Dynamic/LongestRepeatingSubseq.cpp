#include <iostream>
using namespace std;

int memo[1000][1000];

int Lcs(string s1, string s2, int m, int n)
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
        if ((s1[m - 1] == s2[n - 1]) && (m != n))
        {
            memo[m][n] = 1 + Lcs(s1, s2, m - 1, n - 1);
        }
        else
        {
            memo[m][n] = max(Lcs(s1, s2, m - 1, n), Lcs(s1, s2, m, n - 1));
        }
    }
    return memo[m][n];
}

int main()
{
    int m, n;
    m = 15, n = 15;
    string s1 = "abcdefefabcdef";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout << Lcs(s1, s1, m, n);
}