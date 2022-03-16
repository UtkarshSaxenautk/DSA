#include <iostream>
using namespace std ;


class Node
{
  public:
  int data ;
  Node* next ;

};

Node* head = NULL ;
 
void Insert_At_front(int d)
{
    Node* newnode = NULL ;
    newnode = new Node() ;
    newnode->data = d ;
    if(head == NULL)
    {
        newnode->next = NULL ;
        head = newnode ;
    }
    else{
        newnode->next = head ;
        head = newnode ;
    }
}

void Insert_At_back(int d)
{
    Node* newnode= NULL ;
    newnode = new Node();
    newnode->data = d ;
    if(head == NULL)
    {
        newnode->next = NULL ;
        head = newnode ;
    }
    else 
    {
        Node* curr = head ;
        while(curr->next != NULL)
        {
            curr = curr->next ;
        }
        curr->next = newnode ;
        newnode->next = NULL ; 

    }
}


void Insert_At_Position(int p ,int d)
{
    Node* newnode = NULL ;
    newnode = new Node();
    newnode->data = d ;
    newnode->next = NULL ;
    int count = 0 ;
    Node* curr = head ;
    Node* temp = NULL ;
    while(count < p && curr != NULL)
    {
        temp = curr ;
        curr = curr->next ;
        count++ ;
    }
    temp->next = newnode ;
    newnode->next = curr ;
   
}

void Delete_At_front()
{
    if(head == NULL)
    {
        cout << "List is empty" << "\n" ;
    }
    else
    {
        Node* temp = head ;
        head = head->next ;
        delete temp ;
    }
}

void Delete_At_back()
{
    if(head == NULL)
    {
        cout << "List is empty" << "\n" ;
    }
    else{
        Node* curr = head ;
        Node* temp = NULL ;
        while(curr->next != NULL)
        {
             temp = curr ;
            curr = curr->next ;
           

        }
        
        temp->next = NULL ;
        delete curr ;
    }
}

void Delete_At_Position(int k)
{
     if(head == NULL)
    {
        cout << "List is empty" << "\n" ;
    }
    else
    {
        Node* curr = head ;
        Node* temp = NULL ;
        int count = 0 ;
        while(curr->next != NULL && count < k)
        {
            temp = curr ;
            curr = curr->next ;
            count++ ;
        }
        temp->next = (curr->next) ;
        delete curr ;
    }
}

void Display()
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else{
        Node* curr = head ;
        int count = 0 ; 
        while(curr != NULL)
        {
            cout << curr->data << "  " ;
            curr = curr->next ;
            count++ ;
        }
        cout << "\nNo. of nodes in list : " << count << endl;
    }
}

void Insertion_in_Sorted(int d)
{
    Node* newnode = NULL ;
    newnode = new Node();
    newnode->data = d;
    if(head ==  NULL)
    {
        newnode->next = NULL ;
        head = newnode ;
    }
    else 
    {
        Node* curr = head ;
        Node* temp = NULL ;
        while(curr != NULL && curr->data < newnode->data)
        {
            temp = curr ;
            curr = curr->next ;
        }
        newnode->next = curr ;
        temp->next = newnode ;
    }
}


int main()
{
    Insert_At_front(2);
    Insert_At_back(5);
    Insert_At_front(1);
    Display();
    Insert_At_Position(2 , 4);
    
    Display();
    Delete_At_front();
    Display();
    Insert_At_front(1);
    Display();
    Delete_At_back();
    Display();
    Delete_At_Position(2);
    Display();
    Insert_At_back(3);
    Insert_At_back(4);
    Insert_At_back(5);
    Insert_At_back(6);
    Display();
    Delete_At_Position(4);
    Display();
    Delete_At_Position(3);
    Display();
    Insertion_in_Sorted(4);
    Insertion_in_Sorted(5);
    Display();

}