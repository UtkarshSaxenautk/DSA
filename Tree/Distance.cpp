#include <iostream>
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


void printDist(Node* root , int k){
    if(root == NULL){
        return ;
    }
    if(k == 0){
        cout << root->key << " " ;
    }
    else {
        printDist(root->left , k -1);
        printDist(root->right , k-1);
    }
}



int main(){
    //  Node* root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(3);
    // root->left->right = new Node(4);
    // root->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(8);
    // root->right->right->right = new Node(9);
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    printDist(root , 2);
}