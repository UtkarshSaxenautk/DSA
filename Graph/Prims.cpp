#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define INF 999

#define V 4

int primsMst(int graph[V][V])
{
    int key[V];
    int res = 0;
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
    }
    bool mset[V];
    key[0] = 0;

    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mset[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mset[u] = true;
        res += key[u];

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && mset[v] == false)
            {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return res;
}

int main()
{
    // cin >> V;
    int graph[V][V] = {{0, 5, 8, 0}, {5, 0, 10, 15}, {8, 10, 0, 20}, {0, 15, 20, 0}};

    cout << primsMst(graph);
}