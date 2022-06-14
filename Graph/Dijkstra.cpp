#include <iostream>
#include <vector>
using namespace std;
#define V 4

void Dijkstra(int graph[V][V], int source)
{
    int dist[V];
    bool final[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        final[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!final[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        final[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (final[v] == false && graph[u][v] != 0)
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from " << source << " to " << i << " : " << dist[i] << "\n";
    }
}

int main()
{

    int graph[V][V] = {
        {0, 50, 100, 0},
        {50, 0, 30, 200},
        {100, 30, 0, 20},
        {0, 200, 20, 0},
    };
    Dijkstra(graph, 0);
}