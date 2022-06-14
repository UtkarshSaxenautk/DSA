#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool Cycle(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;
        for (int x : adj[u])
        {
            --indegree[x];
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return (count != v);
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    if (Cycle(adj, V) == true)
    {
        cout << "Cycle exist"
             << "\n";
    }
    else
    {
        cout << "No cycle exist"
             << "\n";
    }
}