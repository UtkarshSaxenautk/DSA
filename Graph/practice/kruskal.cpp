#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge
{
public:
    int source, destination, weight;
};

bool comparison(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int find(int x, int parent[])
{
    if (x == parent[x])
    {
        return x;
    }
    parent[x] = find(parent[x], parent);
    return parent[x];
}

void union_(int u, int v, int parent[], int rank[])
{
    int u_rep = find(u, parent);
    int v_rep = find(v, parent);
    if (u_rep == v_rep)
    {
        return;
    }
    if (rank[u_rep] > rank[v_rep])
    {
        parent[v_rep] = u_rep;
    }
    else if (rank[v_rep] > rank[u_rep])
    {
        parent[u_rep] = v_rep;
    }
    else
    {
        parent[v_rep] = u_rep;
        rank[u_rep]++;
    }
}

void Kruskal(Edge arr[], Edge output[], int V, int E)
{
    int rank[V + 1];
    int parent[V + 1];
    int res = 0;
    for (int i = 0; i <= V; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }

    sort(arr, arr + E, comparison);
    for (int i = 0; i < E; i++)
    {
        cout << arr[i].weight << "  ";
    }
    cout << "\n";

    for (int i = 0, s = 0; i < E && s < V - 1; i++)
    {
        Edge e = arr[i];
        int x_rep = find(e.destination, parent);
        int y_rep = find(e.source, parent);
        if (x_rep != y_rep)
        {
            output[s] = e;
            s++;
            union_(x_rep, y_rep, parent, rank);

            res += e.weight;
        }
    }

    cout << res << "\n";
}

int main()
{
    int V = 5;
    int E = 7;
    Edge *arr;
    arr = new Edge[E];
    arr[0].source = 0;
    arr[0].destination = 1;
    arr[0].weight = 10;
    arr[1].source = 0;
    arr[1].destination = 2;
    arr[1].weight = 8;
    arr[2].source = 1;
    arr[2].destination = 2;
    arr[2].weight = 8;
    arr[3].source = 1;
    arr[3].destination = 3;
    arr[3].weight = 3;
    arr[4].source = 2;
    arr[4].destination = 3;
    arr[4].weight = 4;
    arr[5].source = 2;
    arr[5].destination = 4;
    arr[5].weight = 12;
    arr[6].source = 3;
    arr[6].destination = 4;
    arr[6].weight = 15;
    Edge *output;
    output = new Edge[V - 1];

    Kruskal(arr, output, V, E);
    for (int i = 0; i < V - 1; i++)
    {
        cout << output[i].source << " " << output[i].destination << "\n";
    }
}