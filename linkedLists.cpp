#include <iostream>

using namespace std;

//CREATE A NODE
class node{
  
  public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

//TO INSERT A NODE AT THE TAIL
void insertAtTail(node* &head, int value){
    
    node* n = new node(value);
    
    //CASE 1 - empty linked list
    
    if(head == NULL)
    {
        head = n;
        return;
    }
    
    //CASE 2 - to insert at tail when there is a linked list present
    
    node* temp = head;
    
    //to traverse through the linked list
    
    while(temp -> next != NULL ){
        temp = temp -> next;
    }
    
    temp -> next = n;
}

//TO INSERT A NODE AT THE HEAD
void insertAtHead(node* &head, int value){
    
    node* n = new node(value);
    n -> next = head;
    head = n;
}

//TO DELETE A NODE AT THE HEAD
void deleteAtHead(node* &head){
    
    node* todelete = head;
    head = head -> next;
    delete todelete;
}

//TO DELETE A NODE OTHER THAN HEAD NODE
void deletion(node* &head, int value){
    
    //CASE 1 - when there is no linked list present
    if(head == NULL){
        return;
    }
    
    //CASE 2 - when there is only one node present
    if(head -> next == NULL){
        deleteAtHead(head);
    }
    
    //CASE 3 - when there is a linked list present with multiple nodes
    node* temp = head;
    
    //loop until we reach the node before the deletion node(n-1th node)
    while(temp -> next -> data != value){
        temp = temp -> next;
    }
    
    //store the node to be delete
    node* todelete = temp -> next;
    temp -> next = temp -> next -> next;
    delete todelete;
}

//TO REVERSE A LINKED LIST USING ITERATIVE METHOD
node* reverse(node* &head){
    
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    
    while(currptr != NULL){
        nextptr = currptr -> next;      //to define the next pointer
        currptr -> next = prevptr;       //to link current node to previous node
        
        prevptr = currptr;
        currptr = nextptr;
    }
    
    return prevptr;
}

//REVERSE A LINKED LIST USING RECURSION
node* reverseRecursive(node* &head){
    
    //to check if there is no node or 1 node
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    node* newhead = reverseRecursive(head -> next);
    node* headNext = head -> next;
    headNext -> next = head;
    head -> next = NULL;
    return newhead;
}

//TO DISPLAY THE LINKED LIST
void display(node* head){
    
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    
    /*node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);*/
    
    node* n = new node(1);

    insertAtTail(n,2);
    insertAtTail(n,3);
    insertAtTail(n,5);
    insertAtTail(n,6);
    display(n);
    insertAtHead(n,4);
    display(n);
    
    deletion(n,6);
    deleteAtHead(n);
    display(n);
  
    //node* reverseList = reverse(n);
    node* reverseList = reverseRecursive(n);
    display(reverseList);
    return 0;
}
