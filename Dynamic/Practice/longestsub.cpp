#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int memo[1000][1000];

int Lcs(string s1, int i, int m, string s2, int j, int n)
{
    if (i == m || j == n)
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    if (s1[i] == s2[j])
    {
        // s.push_back(s1[i]);
        memo[i][j] = 1 + Lcs(s1, i + 1, m, s2, j + 1, n);
    }
    else
    {
        memo[i][j] = max(Lcs(s1, i, m, s2, j + 1, n), Lcs(s2, i + 1, m, s2, j, n));
    }
    return memo[i][j];
}

pair<string, int> Lcsbydp(string s1, string s2)
{
    string s = "";
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                s.push_back(s1[i - 1]);
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return {s, dp[m][n]};
}

int main()
{
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    memset(memo, -1, sizeof(memo));
    cout << Lcs(s1, 0, s1.length(), s2, 0, s2.length()) << "\n";

    cout << Lcsbydp(s1, s2).first << Lcsbydp(s1, s2).second << "\n";
}