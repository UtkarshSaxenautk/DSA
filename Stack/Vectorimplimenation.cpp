#include <iostream>
#include <vector>
using namespace std ;

class Stack {
    vector<int>v ;
    int sp ; 
    public:
    Stack() {
        sp = -1 ;
    }
    void Push(int x) {
        v.push_back(x);
        sp++ ;
    }
    int Pop() {
        if(sp == -1)
        {
            return -1 ;
        }
        int res = v.back();
        v.pop_back();
        sp-- ;
        return res ;
    }
    int peek() {
        return v[sp];
    }
    int size() {
        return sp + 1 ;
    }
    bool empty() {
        return v.empty();
    }
};


int main() {
    Stack s ;
    s.Push(7);
    s.Push(9);
    s.Push(11);
    s.Push(10);
    cout << s.size() << "\n" ;
    cout << s.empty() << "\n" ;
    cout << s.peek() << "\n" ;
    s.Push(2);
    cout << s.peek() << "\n" ;
    cout << s.Pop() << "\n" ;
    cout << s.Pop() << "\n" ;
    cout << s.Pop() << "\n" ;
    cout << s.Pop() << "\n" ;
    cout << s.Pop() << "\n" ;
    cout << s.Pop() << "\n" ;
     cout << s.size() << "\n" ;
    cout << s.empty() << "\n" ;
}