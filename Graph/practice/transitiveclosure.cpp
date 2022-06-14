#include <iostream>
using namespace std;

#define V 4

void tansitive(int graph[V][V])
{
    cout << "Initially : "
         << "\n";
    int result[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            result[i][j] = graph[i][j];
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                result[j][k] = result[j][k] || (result[j][i] && result[i][k]);
            }
        }
    }

    cout << "Result : "
         << "\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << result[i][j] << " ";
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
    tansitive(graph);
}
