#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head = NULL;


void displayLinkedList(struct node*);
void removeDuplicates(struct node**);
int main(){
    int n; 

    printf("Single Linked List\n");
    printf("********************\n");
    printf("Please enter the number of nodes you want to create in the single linkedlist.\n");
    scanf("%d",&n);

    //Creating the head of the linkedList and allocating the memory.
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
    removeDuplicates(&head);
    printf("LinkedList After removing duplicates:\n");
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

void removeDuplicates(struct node** head){
    //Pointer for traversing
    struct node* current = *head;
    //We will set this to the deleting node's next node.
    struct node* next = NULL;

    while(current->next != NULL){
        //Compare the current node with next node. if Same, delete the next node.
        if(current->data == current->next->data){
            //In this case, current->next has to be deleted.
            next = current->next->next;
            free(current->next);
            current->next = next;
        }
        else{
            //If the nodes are not same, then move 1 postion forward.
            current = current->next;
        }
    }
}