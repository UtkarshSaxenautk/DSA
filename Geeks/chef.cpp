#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int least[m], max[m];
        for (int i = 0; i < m; i++)
        {
            cin >> least[i] >> max[i];
        }
        long long temp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (long long j = 0; j <= n; j++)
            {
                temp[i][j] = 0;
            }
        }
        temp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int mk = least[i - 1]; mk <= max[i - 1] && (j - mk) >= 0; mk++)
                {
                    temp[i][j] = (temp[i][j] % mod + temp[i - 1][j - mk] % mod) % mod;
                }
            }
        }
        cout << temp[m][n] << endl;
    }
}