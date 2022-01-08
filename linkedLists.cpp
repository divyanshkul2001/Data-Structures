#include <iostream>

using namespace std;

class node{
  public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int value){
    node* n = new node(value);
    
    //case 1 - empty linked list
    
    if(head == NULL)
    {
        head = n;
        return;
    }
    
    //case 2 - to insert at tail when there is a linked list present
    
    node* temp = head;
    
    //to traverse through the linked list
    
    while(temp -> next != NULL ){
        temp = temp -> next;
    }
    
    temp -> next = n;
}

void insertAtHead(node* &head, int value){
    node* n = new node(value);
    n -> next = head;
    head = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    /*node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);*/
    
    node* n = new node(1);

    insertAtTail(n,2);
    insertAtTail(n,3);
    display(n);
    insertAtHead(n,4);
    display(n);
    return 0;
}
