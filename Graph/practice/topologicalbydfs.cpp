#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], int source, bool Visited[], stack<int> &s)
{
    Visited[source] = true;
    for (int x : adj[source])
    {
        if (Visited[x] == false)
        {
            DFS(adj, x, Visited, s);
        }
    }
    s.push(source);
}

void Topological(vector<int> adj[], int V)
{
    stack<int> s;
    bool Visited[V];
    for (int i = 0; i < V; i++)
    {
        Visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (Visited[i] == false)
        {
            DFS(adj, i, Visited, s);
        }
    }

    while (s.empty() == false)
    {
        cout << s.top() << "\n";
        s.pop();
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
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 3);

    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    Topological(adj, V);
}