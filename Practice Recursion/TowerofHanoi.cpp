#include <iostream>
using namespace std;

void TowerofHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {

        cout << "Move disk 1 from " << from << " to " << to << "\n";
        return;
    }

    TowerofHanoi(n - 1, from, aux, to);

    cout << "Move disk " << n << " from " << from << " to " << to << "\n";

    TowerofHanoi(n - 1, aux, to, from);
}

int main()
{
    TowerofHanoi(3, 'A', 'B', 'C');
}