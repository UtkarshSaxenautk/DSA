#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int no_of_query;
    cin >> no_of_query;
    int temp[no_of_query][4];
    for (int i = 0; i < no_of_query; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp[i][j] = -1;
        }
    }
    temp[0][0] = 2;
    temp[0][1] = 4;
    temp[0][2] = 4;
    temp[0][3] = 9;

    for (int i = 0; i < no_of_query; i++)
    {
        if (temp[i][0] == -1 || temp[i][0] < 1 || temp[i][0] > 2)
        {
            continue;
        }
        else if (temp[i][0] == 1)
        {
            if (temp[i][1] != -1 && temp[i][2] != -1 && temp[i][3] == 0)
            {
                arr[1] = temp[i][2];
            }
        }
        else
        {
            if (temp[i][1] != -1 && temp[i][2] != -1 && temp[i][3] != -1)
            {
                int count = 0;

                for (int k = temp[i][1]; k <= temp[i][2]; k++)
                {

                    if (__gcd(temp[i][3], arr[k]) == 1)
                    {
                        count++;
                    }
                }
                cout << count << endl;
            }
        }
    }
}