#include <iostream>
#include <queue>
using namespace std ;



class Node {
 public:
 int key ;
 Node* left ;
 Node* right ;
 Node(int a) {
     key = a ;
     left = NULL ;
     right = NULL ;
 }
};

void LevelOrder(Node* root) {
    if(root == NULL) {
        return ;
    }
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false) {
        Node* curr = q.front();
        q.pop();
        cout << curr->key << "  " ;
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout << "\n";
}

int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    LevelOrder(root);
}