#include <iostream>
#include <cmath>
using namespace std;

int check(long long int n)
{
    int ans = 0;
    long long int sum = 1;
    for (long long int i = 2; pow(i, 2.0) <= n; i++)
    {
        if (n % i == 0)
        {
            if (pow(i, 2.0) != n)
            {
                sum = sum + i + n / i;
            }
            else
            {
                sum = sum + i;
            }
        }
    }

    if (sum == n)
    {
        ans = 1;
    }
    else if (n != 1)
    {
        ans = 1;
    }
    return ans;
}

int main()
{
    long long int n;
    cin >> n;
    cout << check(n) << "\n";
}