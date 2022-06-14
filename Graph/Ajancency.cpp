#include <iostream>
using namespace std;

class Undirected_Graph
{
private:
    int vertices;
    int ajcm[10][10];

public:
    Undirected_Graph(int n)
    {
        vertices = n;
        // ajcm = new int[vertices][vertices];
    }

    void Addedge(int i, int j)
    {
        ajcm[i][j] = 1;
        ajcm[j][i] = 1;
    }
    void Removeedge(int i, int j)
    {
        ajcm[i][j] = 0;
        ajcm[j][i] = 0;
    }

    void Display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << ": ";
            for (int j : ajcm[i])
            {
                if (j == 1)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << "\n";
        }
    }
};

int main()
{
    Undirected_Graph u(5);
    u.Addedge(0, 1);
    u.Addedge(0, 2);
    u.Addedge(1, 2);
    u.Addedge(1, 3);
    u.Addedge(2, 4);
    u.Display();
    cout << "\n\n";
    u.Removeedge(0, 2);
    u.Display();
}
