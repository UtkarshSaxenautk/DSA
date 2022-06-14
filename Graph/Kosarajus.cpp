#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void DFSR(vector<int> adj[], int u, bool visited[], stack<int> &st)
{
    visited[u] = true;
    for (int x : adj[u])
    {
        if (visited[x] == false)
        {
            DFSR(adj, x, visited, st);
        }
    }
    st.push(u);
}

void DFS(vector<int> adj[], int V, stack<int> &st)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            DFSR(adj, i, visited, st);
        }
    }
}

void Dfsr(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int x : adj[s])
    {
        if (visited[x] == false)
        {
            Dfsr(adj, x, visited);
        }
    }
}

void Dfs(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            Dfsr(adj, i, visited);
            cout << "\n";
        }
    }
}

void kosaraju(vector<int> adj[], int V)
{
    vector<int> tempadj;
    stack<int> st;
    DFS(adj, V, st);
    while (st.empty() == false)
    {
        int u = st.top();
        // cout << u << "\n";
        tempadj.push_back(u);
        st.pop();
    }
    vector<int> temp[V];
    for (int i = 0; i < tempadj.size(); i++)
    {
        for (int x : adj[i])
        {
            addEdge(temp, x, i);
        }
    }
    Dfs(temp, V);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);

    kosaraju(adj, V);
}
