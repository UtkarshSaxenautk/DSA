#include <iostream>
#include <vector>
using namespace std;

bool DFSR(vector<int> adj[], int s, bool visited[], bool temp[])
{
    visited[s] = true;
    temp[s] = true;
    for (int u : adj[s])
    {
        if (visited[u] == false && DFSR(adj, u, visited, temp))
        {
            return true;
        }
        else if (temp[s] == true)
        {
            return true;
        }
    }
    temp[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    bool temp[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        temp[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (DFSR(adj, i, visited, temp) == true)
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    if (DFS(adj, V))
    {
        cout << "We have cycle"
             << "\n";
    }
    else
    {
        cout << "NO cycle found"
             << "\n";
    }
    return 0;
}
