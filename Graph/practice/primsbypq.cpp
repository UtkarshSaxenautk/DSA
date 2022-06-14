#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Prims(vector<pair<int, int>> adj[], int V)
{
    int parent[V];
    bool final[V];
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        final[i] = false;
        dist[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, 0));
    dist[0] = 0;

    while (pq.empty() == false)
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

            if (final[v] == false && weight < dist[v])
            {
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < V; i++)
    {
        res += dist[i];
    }

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " --- " << i << "\n";
    }
    cout << "total weight of mst " << res << "\n";
}

void addEdge(int u, int v, int w, vector<pair<int, int>> adj[])
{
    adj[u].push_back(make_pair(v, w));
    // adj[v].push_back(make_pair(u, w));
}

int main()
{
    int V = 4;
    vector<pair<int, int>> adj[V];
    // addEdge(0, 1, 4, adj);
    // addEdge(0, 7, 8, adj);
    // addEdge(1, 2, 8, adj);
    // addEdge(1, 7, 11, adj);
    // addEdge(2, 3, 7, adj);
    // addEdge(2, 8, 2, adj);
    // addEdge(2, 5, 4, adj);
    // addEdge(3, 4, 9, adj);
    // addEdge(3, 5, 14, adj);
    // addEdge(4, 5, 10, adj);
    // addEdge(5, 6, 2, adj);
    // addEdge(6, 7, 1, adj);
    // addEdge(6, 8, 6, adj);
    // addEdge(7, 8, 7, adj);
    addEdge(0, 1, 5, adj);
    addEdge(0, 2, 8, adj);
    addEdge(1, 2, 10, adj);
    addEdge(1, 3, 15, adj);
    addEdge(2, 3, 20, adj);

    Prims(adj, V);
}
