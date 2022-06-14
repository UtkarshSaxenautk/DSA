#include <iostream>
using namespace std;

int countstrings(int n, int s)
{
    if (n == 0)
    {
        return 1;
    }
    int count = 0;

    for (int i = s; i < 5; i++)
    {

        count += countstrings(n - 1, i);
    }
    return count;
}

int answer(int n)
{
    int temp = countstrings(n, 0);
    return temp;
}

int main()
{
    int n;
    cin >> n;
    cout << answer(n) << "\n";
}