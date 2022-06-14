#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INFINITY 9999

void addEdge(int u, int v, int w, vector<pair<int, int>> adj[])
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void prims(vector<pair<int, int>> adj[], int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int source = 0;
    int res = 0;

    int key[V];
    int parent[V];
    bool inMst[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INFINITY;
        parent[i] = -1;
        inMst[i] = false;
    }

    pq.push(make_pair(0, source));
    key[source] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMst[u] == true)
        {
            continue;
        }

        inMst[u] = true;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (inMst[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        res += key[i];
    }

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " ----- " << i
             << "\n";
    }
    cout << res << "\n";
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

    prims(adj, V);
}