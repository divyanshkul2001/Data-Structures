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

void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    
    delete todelete;
}

void deletion(node* &head, int pos){
    
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    
    temp->prev->next=temp->next;
    
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    
    delete temp;
}

int length(node* &head){
    int l=1;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

node* appendLastk(node* &head, int k){
   
    int l=1;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        l++;
    }
    if(k==l || k==0){
        return head;
    }
    
    node* tail=temp;
    node* newTail;
    node* newHead;
    
    int newtailptr=l-k;
    int newheadptr=l-k+1;
    
    temp=head;
    int count=1;
    while(count!=newtailptr){
        count++;
        temp=temp->next;
    }
    newTail=temp;
    
    temp=head;
    count=1;
    while(count!=newheadptr){
        count++;
        temp=temp->next;
    }
    newHead=temp;
    
    newTail->next=NULL;
    tail->next=head;
    
    return newHead;

    /*
    node* newHead;
    node* newTail;
    node* tail=head;
    int l=length(head);
    k=k%l;  //so that if k>l then also program runs
    
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    
    newTail->next=NULL;
    tail->next=head;
    
    return newHead;
    */
}

int main() {
    
    node* n=NULL;
    insertAtTail(n,1);
    insertAtTail(n,2);
    insertAtTail(n,3);
    insertAtTail(n,4);
    insertAtTail(n,5);
    insertAtTail(n,6);
    insertAtHead(n,0);
    display(n);
    deleteAtHead(n);
    display(n);
    deletion(n,3);
    display(n);
    
    node* newHead=appendLastk(n,2);
    cout<<"\n\nAfter appending last k nodes\n\n";
    display(newHead);
    return 0;
}
