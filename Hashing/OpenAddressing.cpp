#include <iostream>
using namespace std;

class Hash
{
public:
    int *arr;
    int cap, size;
    Hash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1;
        }
    }
    int hash(int key)
    {
        return key % cap;
    }

    bool search(int val)
    {
        int h = hash(val);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == val)
            {
                return true;
                break;
            }
            if (i == h)
            {
                return false;
                break;
            }
            i = (i + 1) % cap;
        }
        return false;
    }

    bool insert(int val)
    {
        int i = hash(val);

        if (size == cap)
        {
            return false;
        }
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != val)
        {
            i = (i + 1) % cap;
        }
        if (arr[i] == val)
        {
            return false;
        }
        else
        {
            arr[i] = val;
            size++;
            return true;
        }
    }

    bool deletion(int val)
    {
        int h = hash(val);
        int i = h;

        while (arr[i] != -1)
        {
            if (arr[i] == val)
            {
                arr[i] = -2;
                return true;
            }
            if (i == h)
            {
                return false;
            }
            i = (i + 1) % cap;
        }
        return false;
    }
};

int main()
{
    Hash H(7);
    H.insert(43);
    H.insert(52);
    H.insert(23);
    cout << H.search(44) << "\n";
    H.insert(53);
    cout << H.search(53) << "\n";
    cout << H.search(23) << "\n";

    H.deletion(23);
    cout << H.search(23) << "\n";
}