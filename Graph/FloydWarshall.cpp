#include <iostream>
using namespace std;

#define V 4
#define INF 999

void FloydWarshall(int graph[][V])
{
    int temp[V][V], i, j, k;
    // Initially graph :

    cout << "Initially graph was : "
         << "\n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            cout << graph[i][j] << "  ";
        }
        cout << "\n";
    }

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            temp[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (temp[i][k] + temp[k][j] < temp[i][j])
                {
                    temp[i][j] = temp[i][k] + temp[k][j];
                }
            }
        }
    }
    cout << "Finally graph was : "
         << "\n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            cout << temp[i][j] << "  ";
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
    FloydWarshall(graph);
}