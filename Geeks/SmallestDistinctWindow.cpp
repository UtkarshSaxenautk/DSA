#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int SmallestDistinct(string str)
{
    set<int> s;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        s.insert(str[i]);
    }

    int unique_ = s.size(); // geksfor
    int answer = INT_MAX;
    int j = 0;
    unordered_map<char, int> mp; // geeksforgeeks
    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++; // i = 7 , i = 8
        if (mp.size() == unique_)
        {
            while (mp[str[j]] > 1) // for i =7 , j = 0 it will not go inside loop
            {                      // i = 8 , j = 1
                                   // i = 9 , j = 3
                mp[str[j]]--;
                j++;
            }

            answer = min(answer, i - j + 1); // i = 7 ans = 7 - 0 + 1 = 8
                                             // i = 8 , ans = 8 - 1 + 1 = 8
        }                                    // i = 9 , ans = 9 - 3 +1 = 7
    }

    return answer;
}

int main()
{
    string str = "geeksforgeeks";
    cout << SmallestDistinct(str);
}