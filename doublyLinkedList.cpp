#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;
        
        node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

void insertAtHead(node* &head, int val){
    
    node* n = new node(val);
    node* temp = head;
    
    if(head==NULL){
        head=n;
        return;
    }
    
    n->next=head;
    head->prev=n;
    head=n;
    
    /*node* n=new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;*/
}

void insertAtTail(node* &head, int val){
    
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next = n;
    n->prev=temp;
}

void display(node* &head){
    node* temp=head;
    cout<<"NULL <-> ";
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main() {
    
    node* n=NULL;
    insertAtTail(n,1);
    insertAtTail(n,2);
    insertAtTail(n,3);
    insertAtTail(n,4);
    insertAtTail(n,5);
    insertAtTail(n,6);
    display(n);
    return 0;
}
