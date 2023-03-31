#include <iostream>
using namespace std;

void FCFS(int order[], int n)
{
    int total_seektime = order[0] - 50;
    for (int i = 1; i < n; i++)
    {
        // bcout << total_seektime << "\n";
        total_seektime += abs(order[i - 1] - order[i]);
    }
    cout << total_seektime << "\n";
}

int main()
{
    int n = 7;
    int order[] = {82, 170, 43, 140, 24, 16, 190};
    FCFS(order, n);
}