#include <iostream>
using namespace std;

void convert(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    // string s = "";
    int temp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        temp[i][0] = i;
    }
    for (int i = 0; i <= n; i++)
    {
        temp[0][i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                temp[i][j] = temp[i - 1][j - 1];

                // s.push_back(s1[i - 1]);
            }
            else
            {
                temp[i][j] = 1 + min(temp[i - 1][j], min(temp[i][j - 1], temp[i - 1][j - 1]));
            }
        }
    }
    cout << temp[m][n] << "\n";
}

int main()
{
    string s1 = "MONDAY";
    string s2 = "SUNDAY";
    convert(s1, s2);
}