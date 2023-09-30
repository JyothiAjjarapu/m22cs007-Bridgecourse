#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head = NULL;

void displayLinkedList(struct node*);
void reverseofaLinkedList(struct node**);
int main(){
    int n; 

    printf("Reversing a Single Linked List\n");
    printf("********************\n");
    printf("Please enter the number of nodes you want to create in the single linkedlist.\n");
    scanf("%d",&n);

    //Allocating the memory to the head of the linkedlist
    head = (struct node*)malloc(sizeof(struct node));
    int d;
    printf("Enter the data for first Node:\n");
    scanf("%d",&d);

    //setting the data part for the first node.
    head->data = d;
    head->next = NULL;

    //will use this to keep track of the last node in the linkedlist.
    struct node* temp = head;

    int i;
    for(i = 2; i<=n; i++){
        //Allocating memory for the new node to be created.
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        int newData;
        printf("Enter the data part for the %d th node\n",i);
        scanf("%d",&newData);
        //Setting the data and next for newly created Node.
        newNode->data = newData;
        newNode->next = NULL;

        //Adding new node to the last Node of the linkedList.
        temp->next = newNode;
        //Updating the last node as the newly created Node.
        temp = newNode;
    }

    displayLinkedList(head);
    reverseofaLinkedList(&head);
    printf("LinkedList after reversing is:\n");
    displayLinkedList(head);
}


void displayLinkedList(struct node* head){

    struct node* temp = head;

    printf("The LinkedList is as follows\n");
    //Traversing the linkedlist till the end.
    while(temp!=NULL){
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseofaLinkedList(struct node** head){

    struct node* current = *head;
    struct node* prev = NULL;
    struct node* next = NULL;
    while(current!=NULL){
        //Store the next pointer
        next = current->next;

        //Current next should be the prev pointer(as we are reversing)
        current->next = prev;

        //Move the prev and current pointers one position ahead.
        prev = current;
        current =next;
    }
    //Finally after breaking the loop, current will be null and prev will be at the last.
    //But since the linkedlist is reversed, head should point to the last node(which is prev)
    *head = prev;
    
}