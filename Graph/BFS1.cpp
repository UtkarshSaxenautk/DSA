#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(vector<int> adj[], int v, int s)
{
    bool Visited[v];
    for (int i = 0; i < v; i++)
    {
        Visited[i] = false;
    }
    queue<int> q;
    Visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (Visited[v] == false)
            {
                Visited[v] = true;
                q.push(v);
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

    BFS(adj, 8, 0);
}