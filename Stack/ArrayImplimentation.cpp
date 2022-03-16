#include <iostream>
using namespace std ;


class Stack {
    int *arr ;
    int capacity ;
    int sp ;
    void ensurecapacity() {
        if( sp >= capacity)
        {
         int * old = arr ;
         capacity = sp * 2 ;
         arr = new int[sp * 2];
         for( int i = 0 ; i < sp ; i++)
         {
          arr[i] = old[i];
         }
          delete [] old ;
        }
    }
    
    public:
    Stack(int c) {
        capacity = c ;
        sp = -1 ;
        arr = new int[capacity];
    }
    void Push(int x) {
        ensurecapacity() ;
        sp++ ;
        arr[sp] = x ;
    }
    int pop() {
        if(sp == -1) {
            return -1 ;
        }
        int res = arr[sp] ;
        sp-- ;
        return res ;
    }

    int peek() {
         if(sp == -1) {
            return -1 ;
        }
        return arr[sp];
    }
    int size() {
        return sp + 1 ;
    }
    bool isempty() {
        if(sp == -1) {
            return true ;
        }
        return false ;
    }
};


int main() {
    Stack s(4) ;
    s.Push(7);
    s.Push(9);
    s.Push(11);
    s.Push(10);
    cout << s.peek() << "\n" ;
     cout << s.size() << "\n" ;
    cout << s.isempty() << "\n" ;
    s.Push(2);
    cout << s.peek() << "\n" ;
    cout << s.pop() << "\n" ;
    cout << s.pop() << "\n" ;
    cout << s.pop() << "\n" ;
    cout << s.pop() << "\n" ;
    cout << s.pop() << "\n" ;
    cout << s.pop() << "\n" ;
     cout << s.size() << "\n" ;
    cout << s.isempty() << "\n" ;
}