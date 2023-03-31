#include <bits/stdc++.h>
using namespace std;

int fact(long long int n)
{
    long long int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }

    return fact[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N, P;
        cin >> N >> P;
        long long int x = fact(3 * N);
        long long int y = pow(6, N);
        cout << (x / y) % P << "\n";
    }
}