#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cntDistinct(string str)
{
    // Set to store unique characters
    // in the given string
    unordered_set<char> s;

    // Loop to traverse the string
    for (int i = 0; i < str.size(); i++)
    {

        // Insert current character
        // into the set
        s.insert(str[i]);
    }

    // Return Answer
    return s.size();
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool c = true;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[i] == s[j])
                {

                    count++;
                }
            }
            if (count % 2 != 0)
            {
                c = false;
                break;
            }
        }
        if (!c)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            bool ch = true;

            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j = j + 2)
                {
                    if (s[i] == s[j] && i != j)
                    {
                        ch = false;
                        break;
                    }
                }
                if (!ch)
                {
                    break;
                }
            }
            if (!ch)
            {
                cout << "NO"
                     << "\n";
            }
            else
            {
                cout << "YES"
                     << "\n";
            }
        }
        /* code */
    }
    return 0;
}
