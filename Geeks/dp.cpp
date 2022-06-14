#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int MaxGold(vector<vector<int>> &matrix)
    {
        // Code here
        // int m = matrix[][0].size();
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        if (m > 2)
        {

            for (int i = 0; i < n; i++)
            {
                if (matrix[m - 2][i] != -1)
                {
                    if (i == 0)
                    {
                        if (matrix[m - 1][i] != 1 || matrix[m - 1][i + 1] != -1)
                        {
                            matrix[m - 2][i] += max(matrix[m - 1][i], matrix[m - 1][i + 1]);
                        }
                    }
                    else if (i == n - 1)
                    {
                        if (matrix[m - 1][i] != -1 || matrix[m - 1][i - 1] != -1)
                        {
                            matrix[m - 2][i] += max(matrix[m - 1][i], matrix[m - 1][i - 1]);
                        }
                    }
                    else
                    {
                        if (matrix[m - 1][i] != -1 || matrix[m - 1][i - 1] != -1 || matrix[m - 1][i + 1] != -1)
                        {
                            matrix[m - 2][i] += max(matrix[m - 1][i], max(matrix[m - 1][i + 1], matrix[m - 1][i - 1]));
                        }
                    }
                }
            }

            for (int i = m - 3; i >= 0; i--)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] != -1)
                    {
                        if (j == 0)
                        {
                            if (matrix[i + 1][j] != -1 || matrix[i + 1][j + 1] != -1)
                            {
                                matrix[i][j] = matrix[i][j] + max(matrix[i + 1][j], matrix[i + 1][j + 1]);
                            }
                        }
                        else if (j == n - 1)
                        {
                            if (matrix[i + 1][j] != -1 || matrix[i + 1][j - 1] != -1)
                            {
                                matrix[i][j] = matrix[i][j] + max(matrix[i + 1][j], matrix[i + 1][j - 1]);
                            }
                        }
                        else
                        {
                            if (matrix[i + 1][j] != -1 || matrix[i + 1][j + 1] != -1 || matrix[i][j - 1] != -1)
                            {
                                matrix[i][j] = matrix[i][j] + max(matrix[i + 1][j], max(matrix[i + 1][j + 1], matrix[i + 1][j - 1]));
                            }
                        }
                    }
                }
            }

            int max = 0;
            for (int i = 0; i < n; i++)
            {
                if (matrix[0][i] > max)
                {
                    max = matrix[0][i];
                }
            }
            res = max;
        }
        else if (m == 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (matrix[m - 2][i] != -1)
                {
                    if (i == 0)
                    {
                        if (matrix[m - 1][i] != 1 || matrix[m - 1][i + 1] != -1)
                        {
                            matrix[m - 2][i] += max(matrix[m - 1][i], matrix[m - 1][i + 1]);
                        }
                    }
                    else if (i == n - 1)
                    {
                        if (matrix[m - 1][i] != -1 || matrix[m - 1][i - 1] != -1)
                        {
                            matrix[m - 2][i] += max(matrix[m - 1][i], matrix[m - 1][i - 1]);
                        }
                    }
                    else
                    {
                        if (matrix[m - 1][i] != -1 || matrix[m - 1][i - 1] != -1 || matrix[m - 1][i + 1] != -1)
                        {
                            matrix[m - 2][i] += max(matrix[m - 1][i], max(matrix[m - 1][i + 1], matrix[m - 1][i - 1]));
                        }
                    }
                }
            }
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                if (matrix[0][i] > max)
                {
                    max = matrix[0][i];
                }
            }
            res = max;
        }
        else
        {
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                if (matrix[0][i] > max)
                {
                    max = matrix[0][i];
                }
            }
            res = max;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        Solution obj;
        int ans = obj.MaxGold(matrix);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends