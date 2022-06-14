#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(int t, vector<int> v)
{
    if (find(v.begin(), v.end(), t) == v.end())
    {
        return true;
    }
    return false;
}
vector<int> maximizeArray(int arr1[], int arr2[], int n)
{
    // code here
    // code here
    int A[n], B[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = arr1[i];
        B[i] = arr2[i];
    }

    sort(arr1, arr1 + n, greater<int>());
    sort(arr2, arr2 + n, greater<int>());
    vector<int> temp1;
    vector<int> temp2;
    vector<int> res;
    int count1 = 0;
    int count2 = 0;
    int count = 0;

    while (count < n)
    {
        // cout << count1 << " " << count2 << " " << count;

        if (arr2[count2] >= arr1[count1])
        {

            if (count1 == 0)
            {
                temp2.push_back(arr2[count2]);
                count2++;
                count++;
                // cout << "got it";
            }
            else
            {
                if (check(arr2[count2], temp1) == true)
                {
                    temp2.push_back(arr2[count2]);
                    count2++;
                    count++;
                    // cout << "check it";
                }
                else
                {
                    count2++;
                }
            }
        }

        else
        {

            if (count2 == 0)
            {
                temp1.push_back(arr1[count1]);
                count1++;
                count++;
                // cout << "got it";
            }
            else
            {
                if (check(arr1[count1], temp2) == true)
                {
                    temp1.push_back(arr1[count1]);
                    count1++;
                    count++;
                    // cout << "check it " << count1 << count;
                }
                else
                {
                    count1++;
                }
            }
        }
    }

    for (int i = 0; i < temp2.size(); i++)
    {
        int a = temp2[i];
        res.push_back(a);
    }
    for (int i = 0; i < temp1.size(); i++)
    {
        int b = temp1[i];
        res.push_back(b);
    }
    // return res;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (find(res.begin(), res.end(), B[i]) != res.end())
        {
            ans.push_back(B[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (find(res.begin(), res.end(), A[i]) != res.end())
        {
            {
                if (check(A[i], ans) == true)
                {

                    ans.push_back(A[i]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> res;
    int arr1[] = {7, 4, 8, 0, 1};
    int arr2[] = {9, 7, 2, 3, 6};
    res = maximizeArray(arr1, arr2, 5);
    cout << res.size();
}