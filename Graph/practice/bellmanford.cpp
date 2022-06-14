#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bellmanFord(vector<pair<int, pair<int, int>>> edges, int V, int source)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            if (dist[edges[i].second.first] > dist[edges[i].first] + edges[i].second.second)
            {
                dist[edges[i].second.first] = dist[edges[i].first] + edges[i].second.second;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++)
    {
        if (dist[edges[i].second.first] > dist[edges[i].first] + edges[i].second.second)
        {
            cout << "Negative Cycle exist"
                 << "\n";
            return;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << source << " to " << i << " = " << dist[i] << "\n";
    }
}

int main()
{
    int V = 4;
    vector<pair<int, pair<int, int>>> edge;
    // edge.push_back(make_pair(make_pair(0, 1), 5));
    // edge.push_back(make_pair(make_pair(0, 2), 4));
    // edge.push_back(make_pair(make_pair(1, 3), 3));
    // edge.push_back(make_pair(make_pair(2, 1), 6));
    // edge.push_back(make_pair(make_pair(3, 2), 2));
    // Negative CYcle
    edge.push_back(make_pair(0, make_pair(1, 1)));
    edge.push_back(make_pair(1, make_pair(2, -1)));
    edge.push_back(make_pair(2, make_pair(3, -1)));
    edge.push_back(make_pair(3, make_pair(0, -1)));
    cout << edge.size() << "\n";

    // addEdge(edge, 0, 1, 1);
    // addEdge(edge, 0, 2, 4);
    // addEdge(edge, 1, 2, -3);
    // addEdge(edge, 1, 3, 2);
    // addEdge(edge, 2, 3, 3);
    bellmanFord(edge, V, 0);
}