#include <iostream>
#include <vector>
using namespace std ;


class Node {
    public:
    int data ;
    Node* next ; 
    Node(int d) {
      data = d ;
    }
};

class Linked_List : public Node{
    public:
    Node* head = NULL ;
    int size ;
    Linked_List(){
        head = NULL ;
        size = 0 ;
    }
    void insertion(int d) {
       Node* newnode = new Node(d);
       if(head == NULL) {
           head = newnode ;
           return ;
       }
       Node* curr = head ;
       while(curr->next != NULL){
           curr = curr->next ;
       }
       curr->next = newnode ;
       size++ ;
    }
}

int main() {
    int n = 7 ;
    vector<int> arr[n];
    // BY vector
    int key[] = {50 , 21 , 58 , 17 , 15 , 49 , 56 , 22 , 23 , 25};
    for(int i = 0; i < 10 ; i++){
        arr[key[i] % 7].push_back(key[i]);
    }

    for(int x : arr[0]){
        cout << x << "\n";
    }
    
    Linked_List A[n] ;
   // A = new Linked_List();
    for(int i = 0 ; i < 10 ; i++){
        A[key % 7].insertion(key[i]);
    }
   Node* temp = A[0].head ;
   for(int i = 0 ; i < A[0].size ; i++){
       cout << A[0].head->data << "\n";
       A[0].head = A[0].head->next ;
   }
   A[0].head= temp ;
}