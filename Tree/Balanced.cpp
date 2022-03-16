#include <iostream>
using namespace std ;

class Node{
    public:
    int key ;
    Node* right ;
    Node* left ;
    Node(int k){
      key = k ;
      left = NULL ;
      right = NULL ;
    }
};



int height(Node* root){
    if(root == NULL){
        return 0 ;
    }
    else {
        return (1 + max(height(root->left) , height(root->right)));
    }
}

bool isBalanced(Node* root){
    if(root == NULL){
        return true ;
    } 
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh -rh) <=1 && isBalanced(root->left) && isBalanced(root->right));
}

int isbalanced(Node* root) {
    if(root == NULL){
        return 0 ;
    }
    int lh = isbalanced(root->left);
    if(lh == -1){
        return -1 ;
    }
    int rh = isbalanced(root->right);
    if(rh == -1){
        return -1 ;
    }
    if(abs(lh - rh) > 1){
        return -1 ;
    }
    else {
        return max(lh , rh) + 1;
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
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    cout << isBalanced(root) << "\n";
   if(isbalanced(root)) {
       cout << "Is balanced" << "\n";
   }
   else {
       cout << "Is not balanced" << "\n";
   }
}