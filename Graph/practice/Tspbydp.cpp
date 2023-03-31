#include <iostream>
#include <vector>

using namespace std;

int n = 4;
vector<int> v;
int dist[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

int max_travel = (1 << n) - 1;

int table[16][4];
bool visited[4];

int TSP(int temp, int position)
{
    if (visited[position] == false)
    {
        v.push_back(position);
        visited[position] = true;
    }
    if (temp == max_travel)
    {

        return dist[position][0];
    }

    if (table[temp][position] != -1)
    {
        return table[temp][position];
    }

    int answer = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((temp & (1 << city)) == 0)
        {

            int k = dist[position][city] + TSP(temp | (1 << city), city);

            answer = min(answer, k);
        }
    }
    return table[temp][position] = answer;
}

int main()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

        cout << "answer : " << TSP(1, 0) << "\n";
    v.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\n";
}