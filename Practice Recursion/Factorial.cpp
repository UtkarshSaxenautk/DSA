#include <iostream>
using namespace std;

int factorial(int i, int n, int ans)
{
    ans *= i;
    if (i == n)
    {
        return ans;
    }
    return factorial(i + 1, n, ans);
}

int main()
{
    cout << factorial(1, 5, 1);
}