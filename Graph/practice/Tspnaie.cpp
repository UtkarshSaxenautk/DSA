#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define V 4

int TSP(int graph[][V], int source)
{
    vector<int> temp;
    for (int i = 0; i < V; i++)
    {
        if (i != source)
        {
            temp.push_back(i);
        }
    }

    int min_distance = INT_MAX;
    do
    {
        int k = source;
        int currweight = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            currweight += graph[k][temp[i]];
            k = temp[i];
        }
        currweight += graph[k][source];
        min_distance = min(min_distance, currweight);
    } while (next_permutation(temp.begin(), temp.end()));

    return min_distance;
}

int main()
{
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << TSP(graph, s) << endl;
}
