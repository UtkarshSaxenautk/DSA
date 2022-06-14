#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Number of processes : ";
    cin >> n;

    string process[n];
    int bursttime[n];
    cout << "Enter Process name with burst time "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i] >> bursttime[i];
    }

    int temp = 0;
    int waitingtime[n];
    for (int i = 0; i < n; i++)
    {
        waitingtime[i] = temp;
        temp += bursttime[i];
    }
    cout << "Waiting Time of proceses : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << " : " << waitingtime[i] << "\n";
    }

    cout << "Turn Around time : " << temp << "\n";
}