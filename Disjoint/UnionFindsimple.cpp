#include <iostream>
using namespace std;

class Disjoint_set
{
    int *parent;
    int cap;

public:
    // Disjoint_set()
    // {
    //     parent = NULL;
    //     cap = 0;
    // }
    Disjoint_set(int c)
    {
        this->cap = c;
        parent = new int[cap];
    }
    void initialze()
    {
        for (int i = 0; i < cap; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return find(parent[x]);
        }
    }
    void union_set(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep == y_rep)
        {
            return;
        }
        parent[y_rep] = x_rep;
    }
};

int main()
{
    Disjoint_set D(5);
    D.initialze();
    D.union_set(0, 1);
    D.union_set(1, 3);
    // D.union_set(0, 5);
    D.union_set(2, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << D.find(i) << "\n";
    }
    D.union_set(3, 2);
    cout << D.find(2) << "\n";
    cout << D.find(4) << "\n";
}