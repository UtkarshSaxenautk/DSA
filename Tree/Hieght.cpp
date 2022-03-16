#include <iostream>
using namespace std ;


class Node {
 public:
    Node* right ;
    Node* left ;
    int key ;
    Node(int i) {
        key = i ;
        right = NULL ;
        left = NULL ;
    }
};

int heightbyloop(Node* root){
    Node* curr1 = root ;
    Node* curr2 = root ;
    int count = 0 ;
    int count1 = 0 ;
    while(curr1 != NULL){
        curr1 = curr1->left ;
        count++ ;
    }
    while(curr2 != NULL){
        curr2 = curr2->right ;
        count1++ ;
    }

    return max(count1 , count);

}


int height(Node* root) {
   if(root == NULL){
       return 0 ;
   }
   else{
       return 1 + max(height(root->left) , height(root->right));
   }
}


int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
   // root->left->left = new Node(3);
   // root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
  //  root->right->right->left = new Node(8);
   // root->right->right->right = new Node(9);
    cout << height(root) << "\n"; 
    cout << heightbyloop(root) << "\n";
}