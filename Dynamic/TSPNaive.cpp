#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define V 4
int Tsp(int graph[][V], int s)
{
    vector<int> temp;
    for (int i = 0; i < V; i++)
    {
        if (i != s)
        {
            temp.push_back(i);
        }
    }
    int min_dis = INT_MAX;
    do
    {
        int k = s;
        int curr_weight = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            curr_weight += graph[k][temp[i]];
            k = temp[i];
        }
        curr_weight += graph[k][s];
        min_dis = min(min_dis, curr_weight);
    } while (next_permutation(temp.begin(), temp.end()));
    return min_dis;
}

int main()
{
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout << Tsp(graph, s) << endl;
}