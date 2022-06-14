#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void dijkstra(vector<pair<int, int>> adj[], int V, int source)
{
    int dist[V];
    bool final[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        final[i] = false;
    }

    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (final[u] == true)
        {
            continue;
        }

        final[u] = true;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
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
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    dijkstra(adj, V, 0);
}