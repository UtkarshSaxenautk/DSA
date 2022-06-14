#include <iostream>
using namespace std;

#define MAX 9999

int n = 4; // Number of the places want to visit

// Next distan array will give Minimum distance through all the position
int distan[10][10] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};
int completed_visit = (1 << n) - 1;

int table[16][4];

int TSP(int temp, int position)
{

    if (temp == completed_visit)
    { // Initially checking whether all
      // the places are visited or not
        return distan[position][0];
    }
    if (table[temp][position] != -1)
    {
        return table[temp][position];
    }

    // Here we will try to go to every other places to take the minimum
    //  answer
    int answer = MAX;

    // Visit rest of the unvisited cities and temp the . Later find the
    // minimum shortest path
    for (int city = 0; city < n; city++)
    {

        if ((temp & (1 << city)) == 0)
        {

            int k = distan[position][city] + TSP(temp | (1 << city), city);
            answer = min(answer, k);
        }
    }

    return table[temp][position] = answer;
}

int main()
{
    /* initialize the table array */
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j] = -1;
        }
    }
    cout << "Required Answer: " << TSP(1, 0);

    return 0;
}
