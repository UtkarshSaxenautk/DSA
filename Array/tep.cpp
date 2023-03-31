#include <iostream>
using namespace std;
int main()
{
    if (true)
    {
        cout << "Hello, world!" << endl;
    }
    else
    {
        cout << "Hello, planet!" << endl;
    }
    int i;
    for (i = 0; i <= 5; i++)
        ;

    printf("%d", i);
    i = 0;
    for (++i; ++i; i++)
    {
        printf("%d", i);
        if (i == 4)
        {
            break;
        }
    }
}