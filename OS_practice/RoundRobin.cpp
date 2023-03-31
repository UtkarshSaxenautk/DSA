#include <iostream>
#include <vector>
using namespace std;

void RoundRobin(string name[], int burst[], int n)
{
    int quanta = 20;
    int count = 0;
    int waiting = 0;
    while (true)
    {
        if (count == 4)
        {
            break;
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (burst[i] > 0)
            {

                cout << name[i] << " - " << waiting << "\n";
                if (burst[i] < 20)
                {
                    waiting += burst[i];
                }
                else
                {
                    waiting += 20;
                }
                burst[i] -= quanta;
            }
            else
            {
                count++;
            }
        }
    }
}

int main()
{
    int n = 4;
    string name[] = {"first", "second", "third", "forth"};
    int burst[] = {53, 17, 68, 24};
    RoundRobin(name, burst, n);
}