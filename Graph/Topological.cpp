#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void toplogical(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);

    for (int u = 0; u < v; u++)
    {
        for (int x : adj[u])
            indegree[x]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            // indegree[i] = -1;
        }
    }
    // int u = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : adj[u])
        {
            --indegree[x];
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    toplogical(adj, V);
}