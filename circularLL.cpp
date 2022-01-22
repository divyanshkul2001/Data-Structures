#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data=val;
            next=NULL;
        }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }

    node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    if(head==NULL){
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void deletion(node* &head, int pos){
    node* toDelete = head;
    
    int count=1;
    while(count<pos){
        toDelete=toDelete->next;
        count++;
    }
    
    node* temp = head;
    while(temp->next!=toDelete){
        temp=temp->next;
    }
    temp->next=toDelete->next;
    
    if(pos==1)
        head=temp->next;        //case when pos=1
    
    delete toDelete;
}

void display(node* &head){
    node* temp=head;

    //do loop used because at first temp==head
    //we have to go until temp!=head because if we go till temp->next!=head
    //then last node will not be printed.
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);
    cout<<endl;
}

int main(){
    node* cHead=NULL;
    insertAtTail(cHead,1);
    insertAtTail(cHead,2);
    insertAtTail(cHead,3);
    insertAtTail(cHead,4);
    insertAtTail(cHead,5);
    insertAtTail(cHead,6);
    insertAtTail(cHead,7);
    //insertAtHead(cHead,0);
    display(cHead);
    deletion(cHead,7);
    display(cHead);
    return 0;
}
