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

//REVERSE K NODES IN A LINKED LIST
node* reversek(node* &head, int k){
    
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    
    //loop until k times and until currptr is NULL
    int count=0;
    while(currptr != NULL && count < k){
        nextptr = currptr -> next;
        currptr -> next = prevptr;
        
        prevptr = currptr;
        currptr = nextptr;
        
        count++;
    }
    
    //using recursion for the remaining nodes
    if(nextptr != NULL){
        head -> next = reversek(nextptr, k);
    }
    return prevptr;    
}


//TO DETECT AND REMOVE A CYCLE IN A LINKED LIST

//TO CREATE A CYCLE IN A LINKED LIST
void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;
    
    int count = 1;
    while(temp->next!=NULL){
        
        if(count == pos)
        {    
            startNode = temp;
            
        }
        
        temp = temp -> next;
        count++;
    }
    temp -> next = startNode;
}

/* FUNCTION TO REMOVE LOOP. */
void removeLoop(node*, node*);

/* THIS FUNCTION DETECTS A LOOP IN THE LIST
IF LOOP IS THERE IT RETURNS 1 OTHERWISE RETURNS 0 */
int detectAndRemoveLoop(node* list)
{
    node *slow_p = list, *fast_p = list;

    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);

            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }

    /* Return 0 to indicate that there is no loop*/
    return 0;
}

/* FUNCTINO TO REMOVE LOOP.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(node* loop_node, node* head)
{
    node* ptr1 = loop_node;
    node* ptr2 = loop_node;

    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }

    // Fix one pointer to head
    ptr1 = head;

    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;

    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;

    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
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
    insertAtTail(n,4);
    insertAtTail(n,5);
    insertAtTail(n,6);
    display(n);
    
    /*insertAtHead(n,4);
    display(n);
    
    deletion(n,6);
    //deleteAtHead(n);
    display(n);*/
    
    makeCycle(n,3);
    //display(n);
    
    detectAndRemoveLoop(n);

    cout << "Linked List after removing loop \n";
    display(n);
    
    return 0;
}
