#include <iostream>
using namespace std ;

class Node {
 public:
 Node* left;
 Node* right;
 int key ;
 Node(int i) {
     left = NULL ;
     right = NULL ;
     key = i ;
 }
};

#define SIZE 100
 
// Class
// To represent stack using template by class
// taking class in template
template <class T> class Stack {
    // Public access modifier
public:
    // Empty constructor
    Stack();
 
    // Method 1
    // To add element to stack which can be any type
    // using stack push() operation
    void push(T k);
 
    // Method 2
    // To remove top element from stack
    // using pop() operation
    T pop();
 
    // Method 3
    // To print top element in stack
    // using peek() method
    T topElement();
 
    // Method 4
    // To check whether stack is full
    // using isFull() method
    bool isFull();
 
    // Method 5
    // To check whether stack is empty
    // using isEmpty() method
    bool isEmpty();
 
private:
    // Taking data member top
    int top;
 
    // Initialising stack(array) of given size
    T st[SIZE];
};
 
// Method 6
// To initialise top to
// -1(default constructor)
template <class T> Stack<T>::Stack() { top = -1; }
 
// Method 7
// To add element element k to stack
template <class T> void Stack<T>::push(T k)
{
 
    // Checking whether stack is completely filled
    if (isFull()) {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }
 
    // Inserted element
   // cout << "Inserted element " << k << endl;
 
    // Incrementing the top by unity as element
    // is to be inserted
    top = top + 1;
 
    // Now, adding element to stack
    st[top] = k;
}
 
// Method 8
// To check if the stack is empty
template <class T> bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
 
// Utility methods
 
// Method 9
// To check if the stack is full or not
template <class T> bool Stack<T>::isFull()
{
    // Till top in inside the stack
    if (top == (SIZE - 1))
        return 1;
    else
 
        // As top can not exceeds th size
        return 0;
}
 
// Method 10
template <class T> T Stack<T>::pop()
{
    // Initialising a variable to store popped element
    T popped_element = st[top];
 
    // Decreasing the top as
    // element is getting out from the stack
    top--;
 
    // Returning the element/s that is/are popped
    return popped_element;
}
 
// Method 11
template <class T> T Stack<T>::topElement()
{
    // Initialising a variable to store top element
    T top_element = st[top];
 
    // Returning the top element
    return top_element;
}

void Preorder(Node* root) {
    if(root != NULL){
    cout << root->key << "\n";
    Preorder(root->left);
    Preorder(root->right);
    }
}

void Preorderloop(Node* root) {
    if(root == NULL) {
        return ;
    }
    Stack<Node* > s ;
    Node* curr = root ;
    while(s.isEmpty() == false || curr != NULL) {
        while(curr != NULL){
            cout << curr->key << " ";
            if(curr->right){
                s.push(curr->right);
            }
            curr = curr->left ;
        }
        if(s.isEmpty() == false){
            curr = s.topElement();
            s.pop();
        }
    }
}

int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Preorder(root);
    Preorderloop(root);
}
 