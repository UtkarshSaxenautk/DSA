#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "a1c1e1";
    for (int i = 1; i < s.length(); i = i + 2)
    {

        int temp = s[i] - '0';
        char ch = s[i - 1] + temp;
        s[i] = ch;
    }

    cout << s << "\n";
    char v = 'a' + 1;
    cout << v;
}