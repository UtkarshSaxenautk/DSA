#include <iostream>
using namespace std;

int getCount(int coins[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    int res = getCount(coins, n - 1, sum);
    if (coins[n - 1] <= sum)
    {
        res += getCount(coins, n, sum - coins[n - 1]);
    }
    return res;
}

int main()
{
    int coins[] = {1, 2, 3}, sum = 4, n = 3;
    cout << getCount(coins, n, sum);
}