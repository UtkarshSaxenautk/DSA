#include <iostream>
using namespace std ;

class Node {
   public:
   int data ;
   Node* next ;
   Node()
   {
       data = 0 ;
       next = NULL ;
   }
   Node(int d)
   {
       data = d ;
       next = NULL ;
   }
};
Node* head = NULL ;

int No_of_Nodes()
{
   Node* curr = head ;
   int count = 0 ;
   while(curr != NULL)
   {
       count++ ;
       curr = curr->next ;
   }
   return count ;
}

void Insert_At_beginning(int d)
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


Node* Nth_from_End(int n)
{
    Node* curr = head ;
    int index = No_of_Nodes() - n - 1 ;
    for(int i =0 ; i <= index ; i++)
    {
        curr = curr->next ;
    }
    return curr ;
}

Node* Nth_from_End_2nd_way(int n)
{
    Node* temp = head ;
    Node* curr = head ;
    for(int i = 0 ; i < n ; i++)
    {
        temp = temp->next ;
    }
    while(temp != NULL)
    {
        curr = curr->next ;
        temp = temp->next ;
    }
    return curr ;
}


bool Loop_OR_Terminating()
{
   Node* slow = head ;
   Node* fast = head ;
   while(fast != NULL)
   {
       slow = slow->next ;
       fast = fast->next->next ;
       if(slow == fast)
       {
           return true ;
           break ;
       }
    
   }
   return false ; 
}


Node* start_of_loop()
{
    Node* fast = head ;
    Node* slow = head ;
    if(Loop_OR_Terminating())
    {
        while(fast != slow)
        {
            fast = fast->next->next ;
            slow = slow->next ;
        }
        return slow ;
    }
    return NULL ;
}


int main()
{
    Insert_At_beginning(1);
    Insert_At_beginning(2);
    Insert_At_beginning(3);
    Insert_At_back(4);
    Insert_At_back(5);
    Insert_At_back(6);
    Display();
    cout << Nth_from_End(2)->data << endl;
    cout << Nth_from_End_2nd_way(2)->data << endl;
    if(Loop_OR_Terminating() == true)
    {
        cout << "Cyclic : " << "\n" ;
    }
    else{
        cout << "Terminating by NULL" << "\n" ;
    }

    if(start_of_loop() == NULL)
    {
        cout << "Loop does not exist " << "\n" ;
    }
    else{
        cout << start_of_loop()->data << "\n" ;
    }
}






