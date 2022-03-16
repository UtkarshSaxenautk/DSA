#include <iostream>
using namespace std ;

class Node
{
   public:
   int data ;
   Node* next ;
   Node* prev ;
   Node()
   {
       data = 0 ; 
       next = NULL ;
       prev = NULL ;
   }
   Node(int d)
   {
       data = d ;
       next = NULL ;
       prev = NULL ;
   }
};

Node* head = NULL ;

void Insert_At_front(int d)
{
    Node* newnode = NULL;
    newnode = new Node(d);
    newnode->data = d ;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL)
    {
        newnode->next = NULL ;
        newnode->prev = NULL;
        head = newnode ;
    }
    else{
        newnode->next = head ;
        newnode->prev = NULL ;
        head = newnode ;
    }
}

void Insert_At_end(int d)
{
    Node* newnode = NULL ;
    newnode = new Node(d);
    newnode->data = d ;
    newnode->next = NULL;
    newnode->prev = NULL;
     if(head == NULL)
    {
        newnode->next = NULL ;
        newnode->prev = NULL;
        head = newnode ;
    }
    else{
        Node* curr = head ;
        while(curr->next != NULL)
        {
            curr= curr->next ;
        }
        curr->next = newnode ;
        newnode->prev = curr ;
        newnode->next = NULL ;
    }
}


void Insert_At_Position(int d , int p)
{
  Node* newnode = NULL ;
  newnode = new Node(d);
  newnode->data = d ;
  newnode->next = NULL;
  newnode->prev = NULL;
  Node* curr = head ;
  int count = 0 ;
  Node* temp = NULL ;
  while(count < p && curr != NULL)
  {
      temp = curr ;
      curr = curr->next ;
      count++ ;
  } 
  newnode->prev = temp ;
  temp->next = newnode ;
  curr->prev = newnode ;
  newnode->next = curr ;
}

void Delete_At_Front()
{
    Node* curr = head ;
    Node* temp = head->next ;
    temp->prev = NULL ;
    head = temp ;
    delete curr ;

}

void Delete_At_End()
{
    Node* curr = head ;
    Node* temp =  NULL ;
    while(curr->next != NULL)
    {
        temp = curr ;
        curr = curr->next ;
    }
    temp->next = NULL;
    delete curr ;
}

void Delete_At_Position(int k)
{
    Node* curr = head ;
    Node* temp = NULL;
    int count = 0 ;
    while(curr->next != NULL && count < k )
    {
        temp = curr ;
        curr = curr->next ;
        count++ ;
    }
    temp->next = curr->next ;
    (curr->next)->prev = temp ;
    delete curr ;
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
        cout << "List :----------" << endl;
        while(curr != NULL)
        {
            cout << curr->data << "  " ;
            curr = curr->next ;
            count++ ;
        }
        cout << "\nNo. of nodes in list : " << count << endl;
    }
}



int main()
{
    Insert_At_front(6);
    Insert_At_front(2);
    Insert_At_front(1);
    Display();
    Insert_At_end(7);
    Insert_At_end(8);
    Display();
    Insert_At_Position(3 ,2);
    Insert_At_Position(4 ,3);
    Insert_At_Position(5 ,4);
    Display();
    Delete_At_Front();
    Display();
    Delete_At_End();
    Display();
    Delete_At_Position(2);
    Display(); 
}
