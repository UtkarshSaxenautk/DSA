#include <iostream>
using namespace std;
#include <set>

int main()
{
    int n;
    cout << "Number of processes : ";
    cin >> n;
    set<pair<int, string>> st;
    cout << "Enter process name with burst time"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        int t;
        cin >> s >> t;
        st.insert(make_pair(t, s));
    }

    int temp = 0;
    int i = 0;
    int wait[n];
    for (int i = 0; i < n; i++)
    {
        wait[i] = 0;
    }
    for (set<pair<int, string>>::iterator it = st.begin(); it != st.end(); ++it)
    {
        cout << (*it).second << " :  " << (*it).first << "\n";
        wait[i] += temp;
        temp += (*it).first;
        i++;
    }

    i = 0;
    cout << "Waiting time per process : "
         << "\n";
    for (set<pair<int, string>>::iterator it = st.begin(); it != st.end(); ++it)
    {

        cout << (*it).second << " :  " << wait[i] << "\n";
        i++;
    }

    cout << "Turn around time :  " << temp << "\n";
}