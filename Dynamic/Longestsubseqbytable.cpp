#include <iostream>
#include <vector>
using namespace std;

void Lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    string ans = "";
    int temp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        temp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        temp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                temp[i][j] = 1 + temp[i - 1][j - 1];
                ans.push_back(s1[i - 1]);
            }
            else
            {
                temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);
            }
        }
    }
    cout << ans << "\n";
    cout << temp[m][n] << "\n";
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BAZ";
    Lcs(s1, s2);
}
