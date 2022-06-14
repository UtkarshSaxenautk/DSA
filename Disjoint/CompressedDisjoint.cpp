#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    int cap;

public:
    DisjointSet(int c)
    {
        cap = c;
    }
    void intialize()
    {
        for (int i = 0; i < cap; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_set(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep == y_rep)
        {
            return;
        }
        if (rank[x_rep] < rank[y_rep])
        {
            parent[x_rep] = y_rep;
        }
        else if (rank[x_rep] > rank[y_rep])
        {
            parent[y_rep] = x_rep;
        }
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

int main()
{
    DisjointSet D(5);
    D.intialize();
    D.union_set(0, 2);
    D.union_set(1, 3);
    D.union_set(3, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << D.find(i) << "\n";
    }
    cout << "\n";
    D.union_set(4, 2);
    for (int i = 0; i < 5; i++)
    {
        cout << D.find(i) << "\n";
    }
}