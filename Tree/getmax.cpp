#include <iostream>
#include <queue>
using namespace std ;


class Node {
   public:
   int key ;
   Node* left ;
   Node* right ;
   Node(int k){
       key = k ;
       left = NULL ;
       right = NULL ;
   }
};


int getmax(Node* root){
    if(root == NULL){
        return -1 ;
    }
    else {
        return max(root->key , max(getmax(root->left) , getmax(root->right)));
    }
}



int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    cout << getmax(root);
}