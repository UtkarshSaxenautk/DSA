#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Articulate(vector<int> adj[], int u, bool visited[], int disc[], int low[], int parent[], bool Ap[])
{
    static int time = 0;
    int child = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            child++;
            parent[v] = u;
            Articulate(adj, v, visited, disc, low, parent, Ap);
            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && child > 1)
            {
                Ap[u] = true;
            }
            if (parent[u] != -1 && low[v] >= disc[u])
            {
                Ap[u] = true;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void articulatePoints(vector<int> adj[], int V)
{
    bool visited[V];
    int disc[V];
    int low[V];
    int parent[V];
    bool Ap[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        Ap[i] = false;
        disc[i] = -2;
        low[i] = -3;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            Articulate(adj, i, visited, disc, low, parent, Ap);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (Ap[i] == true)
        {
            cout << i << "\n";
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    articulatePoints(adj, V);
}