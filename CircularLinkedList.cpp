#include <iostream>
using namespace std ;

class Node
{
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
    int count = 0 ;
    Node* curr = head ;
    do
    {
        /* code */
        curr = curr->next ;
        count++ ;
    } while (curr != head);

    return count ;
    
}

void Insert_At_front(int d)
{
    Node* newnode = NULL ;
    newnode = new Node(d);
    newnode->next = newnode ;
    Node* curr = head ;
    if(head == NULL)
    {
        head = newnode ;
    }
    else{
        while(curr->next != head)
        {
            curr = curr->next ;
        }
        curr->next = newnode ;
        newnode->next = head ;
        head = newnode ;  
    }
}

void Insert_At_end(int d)
{
    Node* newnode = NULL ;
    newnode = new Node(d);
    newnode->next = newnode ;
    if(head == NULL)
    {
        cout << "List was empty : " << "\n" ;
        cout << "Inserting " << d << " in end " << "\n";
    }
    Node* curr = head ;
    while(curr->next != head)
    {
        curr = curr->next ;
    }
    newnode->next = curr->next ;
    curr->next = newnode ;
}


void Insert_At_Position(int d , int p)
{
     Node* newnode = NULL ;
    newnode = new Node(d);
    newnode->next = newnode ;
    if(p == 0)
    {
        Insert_At_front(d);
    }
    else if(p == No_of_Nodes())
    {
       Insert_At_end(d);
    }
    else{
        Node* curr = head ;
        for(int i =0 ; i < p - 1 ; i++)
        {
            curr = curr->next ;
        }
        newnode->next = curr->next ;
        curr->next = newnode ;
    }
}

void Delete_At_front()
{
    Node* curr = head ;
    Node* temp = NULL ;
    while(curr->next != head)
    {
        curr = curr->next ;
    
    }
    temp = curr->next ;
    curr->next = head->next ;
    head = head->next ;
    delete temp ;
}

void Delete_At_End()
{
    Node* curr = head ;
    Node* temp = NULL ;
    while(curr->next != head)
    {
        temp = curr ;
        curr = curr->next ;
    }
    temp->next = curr->next ;
    delete curr ;
}

void Delete_At_position(int p)
{
    Node* curr = head ;
    Node* temp = NULL ;
    for(int i = 0 ; i < p - 1 ; i++)
    {
        curr = curr->next ;
    }
    temp = curr->next ;
    curr->next = temp->next ;
    delete temp ;
}


void Display(Node* curr , int count = 0)
{
    
    if(curr == head)
    {
        count++ ;
    }
    if(count < 2)
    {
        cout << curr->data << " " ;
        Display(curr->next , count);
    }
    else
    {
        return ;
    }
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
       do
        {
            fast = fast->next->next ;
            slow = slow->next ;
        } while(fast != slow);
        return slow ;
    }
    return NULL ;
}

int length_of_loop()
{
    Node* fast = head ;
    Node* slow = head ;
    int count = 0 ;
    if(Loop_OR_Terminating())
    {
       do
        {
            fast = fast->next->next ;
            slow = slow->next ;
            count++ ;
        } while(fast != slow);
        return count ;
    }
    return 0 ;
}


int main()
{
    Insert_At_front(4);
    Insert_At_front(3);
    Insert_At_front(2);
    Insert_At_front(1);
    Display(head , 0);
    cout << "\nNO_of_ nodes = " << No_of_Nodes() << "\n";
    Insert_At_end(5);
    Insert_At_end(6);
    Display(head , 0);
    cout << "\nNO_of_ nodes = " << No_of_Nodes() << "\n";
    Insert_At_Position(7 , 6);
    Insert_At_Position(0 , 0);
    Insert_At_Position(8 , 4);
    Display(head , 0);
    cout << "\nNO_of_ nodes = " << No_of_Nodes() << "\n";    
    Delete_At_front();
    Display(head , 0);
    cout << "\nNO_of_ nodes = " << No_of_Nodes() << "\n";
    Delete_At_End();
    Display(head , 0);
    cout << "\nNO_of_ nodes = " << No_of_Nodes() << "\n";
    Delete_At_position(3);
    Display(head , 0);
    cout << "\nNO_of_ nodes = " << No_of_Nodes() << "\n";
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
    cout << length_of_loop() << " \n" ; 
}