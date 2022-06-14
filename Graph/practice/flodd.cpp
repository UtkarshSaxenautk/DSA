#include <iostream>
#include <vector>
using namespace std;

#define V 4
#define INF 999999

void Floyd(int graph[V][V])
{
    int res[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            res[i][j] = graph[i][j];
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "result : "
         << "\n";
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (res[i][j] > res[i][k] + res[k][j])
                {
                    res[i][j] = res[i][k] + res[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int graph[V][V] = {{0, 3, INF, 5},
                       {2, 0, INF, 4},
                       {INF, 1, 0, INF},
                       {INF, INF, 2, 0}};
    Floyd(graph);
}