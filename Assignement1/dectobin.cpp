#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// For 32 bit with O(1) time complexity
string Resultbyoperators(int n)
{
    string s = "";
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
        {
            s += "1";
        }
        else
        {
            s += "0";
        }
    }
    return s;
}

int main()
{
    // Enter given number
    int n;
    cin >> n;
    int t = n; // copy of n

    // let a string to store intermediate results
    string s = "";
    while (n > 0)
    {
        string temp = to_string(n % 2);
        s += temp;
        n /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;

    // In 32 bit
    cout << "In 32 bit" << endl;
    string res = Resultbyoperators(t);
    cout << res << endl;
    // Using bitset library
    cout << "In 64 bit" << endl;
    string str_by_bitset = bitset<64>(t).to_string();
    cout << str_by_bitset << endl;
}