#include <iostream>
using namespace std;

int isSorted(int A[], int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (A[n - 1] < A[n - 2])
    {
        return 0;
    }
    else
    {
        return isSorted(A, n - 1);
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    cout << isSorted(A, 5);
}