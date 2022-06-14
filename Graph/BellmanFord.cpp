#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<pair<pair<int, int>, int>> edge, int u, int v, int w)
{
    edge.push_back(make_pair(make_pair(u, v), w));
}

void BellmanFord(vector<pair<pair<int, int>, int>> edge, int V, int source)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        for (int i = 0; i < edge.size(); i++)
        {
            if (dist[edge[i].first.second] > dist[edge[i].first.first] + edge[i].second)
            {
                dist[edge[i].first.second] = dist[edge[i].first.first] + edge[i].second;
            }
        }
    }

    bool negativecycle = false;

    for (int i = 0; i < edge.size(); i++)
    {
        if (dist[edge[i].first.second] > dist[edge[i].first.first] + edge[i].second && dist[edge[i].first.first] != INT_MAX)
        {
            negativecycle = true;
            break;
        }
    }

    if (negativecycle)
    {
        cout << "Graph contains the negative cycle"
             << "\n";
    }
    else
    {

        for (int i = 0; i < V; i++)
        {
            cout << source << " to " << i << " = " << dist[i] << "\n";
        }
    }
}

int main()
{
    int V = 4;
    vector<pair<pair<int, int>, int>> edge;
    // edge.push_back(make_pair(make_pair(0, 1), 5));
    // edge.push_back(make_pair(make_pair(0, 2), 4));
    // edge.push_back(make_pair(make_pair(1, 3), 3));
    // edge.push_back(make_pair(make_pair(2, 1), 6));
    // edge.push_back(make_pair(make_pair(3, 2), 2));
    // Negative CYcle
    edge.push_back(make_pair(make_pair(0, 1), 1));
    edge.push_back(make_pair(make_pair(1, 2), -1));
    edge.push_back(make_pair(make_pair(2, 3), -1));
    edge.push_back(make_pair(make_pair(3, 0), -1));
    cout << edge.size() << "\n";

    // addEdge(edge, 0, 1, 1);
    // addEdge(edge, 0, 2, 4);
    // addEdge(edge, 1, 2, -3);
    // addEdge(edge, 1, 3, 2);
    // addEdge(edge, 2, 3, 3);
    BellmanFord(edge, V, 0);
}