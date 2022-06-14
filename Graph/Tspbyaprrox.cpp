#include <iostream>
#include <vector>
using namespace std;

// Let Number of vertices in the graph
#define V 5

// Required answer
vector<int> req_ans;

int minimum_key(int key[], bool visited_mst[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited_mst[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

vector<vector<int>> MST(int parent[], int graph[V][V])
{
    vector<vector<int>> v;
    for (int i = 1; i < V; i++)
    {
        vector<int> temp;
        temp.push_back(parent[i]);
        temp.push_back(i);
        v.push_back(temp);
        temp.clear();
    }
    return v;
}

vector<vector<int>> primMST(int graph[V][V])
{
    int parent[V];
    int key[V];

    // array to check visited vertices
    bool visited_mst[V];

    // initializing key value to INFINITE & false for all visited_mst
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, visited_mst[i] = false;

    // picking up the first vertex and assigning it to 0
    key[0] = 0;
    parent[0] = -1;

    // The Loop
    for (int count = 0; count < V - 1; count++)
    {
        // checking and updating values wrt minimum key
        int u = minimum_key(key, visited_mst);
        visited_mst[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && visited_mst[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    vector<vector<int>> v;
    v = MST(parent, graph);
    return v;
}

// getting the preorder walk of the MST using DFS
void DFS(int **adj_list, int num_nodes, int starting_vertex, bool *visited_nodes)
{
    // adding the node to final answer
    req_ans.push_back(starting_vertex);

    // checking the visited status
    visited_nodes[starting_vertex] = true;

    // using a recursive call
    for (int i = 0; i < num_nodes; i++)
    {
        if (i == starting_vertex)
        {
            continue;
        }
        if (adj_list[starting_vertex][i] == 1)
        {
            if (visited_nodes[i])
            {
                continue;
            }
            DFS(adj_list, num_nodes, i, visited_nodes);
        }
    }
}
int main()
{
    // initial graph
    int graph[V][V] = {{0, 10, 18, 40, 20},
                       {10, 0, 35, 15, 12},
                       {18, 35, 0, 25, 25},
                       {40, 15, 25, 0, 30},
                       {20, 13, 25, 30, 0}};

    vector<vector<int>> v;

    // getting the output as MST
    v = primMST(graph);

    // creating a dynamic matrix
    int **adj_list = new int *[V];
    for (int i = 0; i < V; i++)
    {
        adj_list[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            adj_list[i][j] = 0;
        }
    }

    // setting up MST as adjacency matrix
    for (int i = 0; i < v.size(); i++)
    {
        int first_node = v[i][0];
        int second_node = v[i][1];
        adj_list[first_node][second_node] = 1;
        adj_list[second_node][first_node] = 1;
    }

    // a checker function for the DFS
    bool *visited_nodes = new bool[V];
    for (int i = 0; i < V; i++)
    {
        bool visited_node;
        visited_nodes[i] = false;
    }

    // performing DFS
    DFS(adj_list, V, 0, visited_nodes);

    // adding the source node to the path
    req_ans.push_back(req_ans[0]);

    // printing the path
    for (int i = 0; i < req_ans.size(); i++)
    {
        cout << req_ans[i] << "-";
    }
    return 0;
}
