#include <iostream>
using namespace std ;


class Node {
     public:
 int data ;
 Node* next ;

 Node() {
     data = 0 ;
     next = NULL ;
 }
 Node(int d) {
     data = d ;
     next = NULL ;
 }
};

class Stack {
    Node* head ;
    int size ;
    public:
    Stack() {
        head = NULL ;
        size = 0 ;
    }
    void Push(int x) {
        Node* temp = new Node(x) ;
        temp->next = head ;
        head = temp ;
        size++ ;
    }
    int Pop() {
        if(head == NULL) {
            return -1 ;
        }
        else {
            Node* temp = head ;
            int res = head->data ;
            head = head->next ;
            delete(temp);
            size-- ;
            return res ;
        }
    }
    int peek() {
        if(head == NULL) {
            return -1 ;
        }
        return head->data ;
    }
    int Size() {
        return size ;
    }
    bool empty() {
        return head == NULL ;
    }
};


int main() {
    Stack s ;
    s.Push(7);
    s.Push(9);
    s.Push(11);
    s.Push(10);
    cout << s.Size() << "\n" ;
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
     cout << s.Size() << "\n" ;
    cout << s.empty() << "\n" ;
}