#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void bfs(vector<int> adj[], int V, int source)
{
    bool visited[V];
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << "\n";
        q.pop();
        for (int x : adj[v])
        {
            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    int v = 8;
    vector<int> adj[v];
    addedge(adj, 0, 1);
    addedge(adj, 0, 2);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 2, 3);
    addedge(adj, 1, 4);
    addedge(adj, 4, 5);
    addedge(adj, 4, 6);
    addedge(adj, 5, 6);
    addedge(adj, 2, 6);
    addedge(adj, 3, 5);
    addedge(adj, 0, 4);
    addedge(adj, 0, 6);
    addedge(adj, 1, 5);
    // for this bfs doesnt work out
    addedge(adj, 7, 7);
    bfs(adj, v, 0);
}