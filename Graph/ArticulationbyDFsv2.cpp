#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSR(vector<int> adj[], int s, bool visited[], int count[])
{
    // count[s]++;

    visited[s] = true;
    // cout << s << " ";
    for (int u : adj[s])
    {
        count[u] = count[u] + 1;
        if (visited[u] == false)
        {
            DFSR(adj, u, visited, count);
        }
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    bool visited[V];
    int count[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        count[i] = 0;
    }
    DFSR(adj, 0, visited, count);

    for (int i = 0; i < V; i++)
    {
        if (count[i] > 2)
        {
            cout << i << "\n";
        }
    }
}