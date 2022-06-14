#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Edge
{
public:
    int src, des, w;
    // Edge(int s, int d, int we)
    // {
    //     src = s;
    //     des = d;
    //     w = we;
    // }
};

bool comparison(Edge E1, Edge E2)
{
    return E1.w < E2.w;
}

int find(int x, int parent[])
{
    if (x == parent[x])
    {
        return x;
    }
    else
    {
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
}

void union_set(int x, int y, int parent[], int rank[])
{
    int x_rep = find(x, parent);
    int y_rep = find(y, parent);
    if (x_rep == y_rep)
    {
        return;
    }
    if (rank[x_rep] > rank[y_rep])
    {
        parent[y_rep] = x_rep;
    }
    else if (rank[x_rep] < rank[y_rep])
    {
        parent[x_rep] = y_rep;
    }
    else
    {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

void kruskal(Edge arr[], int parent[], int rank[], Edge output[], int v)
{
    sort(arr, arr + 7, comparison);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i].w << " ";
    }
    cout << "\n";
    int res = 0;
    int s = 0;

    for (int i = 0, s = 0; s < v - 1; i++)
    {
        Edge e = arr[i];
        int x = find(e.src, parent);
        int y = find(e.des, parent);
        if (x != y)
        {
            res += e.w;
            output[s] = e;
            union_set(x, y, parent, rank);
            s++;
        }
    }
    cout << res << endl;
}

int main()
{
    int v = 5;
    Edge *arr;
    arr = new Edge[7];
    arr[0].src = 0;
    arr[0].des = 1;
    arr[0].w = 10;
    arr[1].src = 0;
    arr[1].des = 2;
    arr[1].w = 8;
    arr[2].src = 1;
    arr[2].des = 2;
    arr[2].w = 8;
    arr[3].src = 1;
    arr[3].des = 3;
    arr[3].w = 3;
    arr[4].src = 2;
    arr[4].des = 3;
    arr[4].w = 4;
    arr[5].src = 2;
    arr[5].des = 4;
    arr[5].w = 12;
    arr[6].src = 3;
    arr[6].des = 4;
    arr[6].w = 15;
    // arr[0].src = 0;
    // arr[0].des = 1;
    // arr[0].w = 10;
    // arr[1].src = 0;
    // arr[1].des = 2;
    // arr[1].w = 6;
    // arr[2].src = 0;
    // arr[2].des = 3;
    // arr[2].w = 5;
    // arr[3].src = 1;
    // arr[3].des = 3;
    // arr[3].w = 15;
    // arr[4].src = 2;
    // arr[4].des = 3;
    // arr[4].w = 4;
    Edge *output;
    output = new Edge[v - 1];
    int parent[v + 1];
    int rank[v + 1];
    for (int i = 0; i < v + 1; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    kruskal(arr, parent, rank, output, v);
    for (int i = 0; i < v - 1; i++)
    {
        cout << output[i].src << " " << output[i].des << "\n";
    }
}