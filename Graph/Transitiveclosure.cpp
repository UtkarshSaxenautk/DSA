#include <iostream>
#include <vector>
using namespace std;

#define V 4

void Print_Transitive(int initial[V][V])
{
    int result[V][V];

    // Initial Graph
    cout << "Initially : "
         << "\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << initial[i][j] << "  ";
        }
        cout << "\n";
    }

    // Initially copying data of initial graph to final graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            result[i][j] = initial[i][j];
        }
    }

    // Now we will change matrix V times

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                result[i][j] = result[i][j] || (result[i][k] && result[k][j]);
            }
        }
    }
    cout << "\n"
         << "Transitive closure : "
         << "\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << result[i][j] << "  ";
        }
        cout << "\n";
    }
}

int main()
{
    int graph[V][V] = {{1, 1, 0, 1},
                       {0, 1, 1, 0},
                       {0, 0, 1, 1},
                       {0, 0, 0, 1}};
    Print_Transitive(graph);
}