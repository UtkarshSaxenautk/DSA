#include <iostream>
#include <vector>
using namespace std;

class Disjoint
{
private:
    vector<int> arr;
    vector<int> rank;
    int cap;

public:
    Disjoint(int c)
    {
        cap = c;
    }
    void initialize()
    {
        for (int i = 0; i < cap; i++)
        {
            arr.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if (arr[x] == x)
        {
            return x;
        }
        else
        {
            return find(arr[x]);
        }
    }

    void unions(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);

        if (x_rep == y_rep)
        {
            return;
        }
        if (rank[x_rep] < rank[y_rep])
        {
            arr[x_rep] = y_rep;
        }
        else if (rank[y_rep] < rank[x_rep])
        {
            arr[y_rep] = x_rep;
        }
        else
        {
            arr[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

int main()
{
    Disjoint D(5);
    D.initialize();
    D.unions(0, 1);
    D.unions(1, 3);
    // D.unions(0, 5);
    D.unions(2, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << D.find(i) << "\n";
    }
    D.unions(3, 2);
    cout << D.find(2) << "\n";
    cout << D.find(4) << "\n";
}