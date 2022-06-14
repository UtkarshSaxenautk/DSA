#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFS(vector<int> adj[], int u, stack<int> &s, bool visited[])
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == false)
        {
            DFS(adj, v, s, visited);
        }
    }
    s.push(u);
}

void TopologicalSort(vector<int> adj[], int v)
{
    stack<int> st;
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            DFS(adj, i, st, visited);
        }
    }
    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        cout << x << " ";
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
    // addEdge(adj, 0, 2);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    TopologicalSort(adj, V);
}