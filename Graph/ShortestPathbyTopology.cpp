#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define INF 999

class AdjListNode

{
public:
    int v;
    int weight;
    AdjListNode(int vn, int w)
    {
        v = vn;
        weight = w;
    }
};

class Graph
{
public:
    int V;
    vector<AdjListNode> *adj;
    Graph(int vertices)
    {
        this->V = vertices;
        adj = new vector<AdjListNode>[V];
    }
    void addEdge(int u, int v, int w)
    {
        AdjListNode node(v, w);
        adj[u].push_back(node);
    }

    void topological(int v, bool visited[], stack<int> &st)
    {
        visited[v] = true;
        for (AdjListNode t : adj[v])
        {
            if (visited[t.v] == false)
            {
                topological(t.v, visited, st);
            }
        }
        st.push(v);
    }

    void shortest(int s)
    {
        stack<int> st;
        bool visited[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        int dis[V];
        for (int i = 0; i < V; i++)
        {
            dis[i] = INF;
        }
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                topological(i, visited, st);
            }
        }
        dis[s] = 0;
        while (st.empty() == false)
        {
            int u = st.top();
            st.pop();

            if (dis[u] != INF)
            {
                for (AdjListNode x : adj[u])
                {
                    if (dis[x.v] > dis[u] + x.weight)
                    {
                        dis[x.v] = dis[u] + x.weight;
                    }
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dis[i] == INF)
            {
                cout << "INF"
                     << "\n";
            }
            else
            {
                cout << dis[i] << "\n";
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);
    int s = 0;
    g.shortest(s);
}