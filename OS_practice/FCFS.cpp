#include <iostream>
#include <vector>
using namespace std;

void FCFS(string name[], int burst[], int n)
{

    int avturnaround = 0;
    int avwaiting = 0;
    int waiting = 0;
    int turnaround = 0;

    for (int i = 0; i < n; i++)
    {
        turnaround += burst[i];
        avturnaround += turnaround;
        cout << i << ")  " << name[i] << "   " << burst[i] << "   " << turnaround << "   " << waiting
             << "\n";
        avwaiting += waiting;
        waiting += burst[i];
    }

    cout << "Average Turnaround time : " << avturnaround / n << "\n";
    cout << "Average Waiting Time : " << avwaiting / n << "\n";
}

int main()
{
    int n = 3;
    string name[] = {"first", "second", "third"};
    int burst[] = {10, 5, 8};
    FCFS(name, burst, n);
}