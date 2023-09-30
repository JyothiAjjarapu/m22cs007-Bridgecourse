#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head = NULL;


void displayCircularLinkedList(struct node*);
int main(){
    int n; 

    printf("Circular Linked List\n");
    printf("********************\n");
    printf("Please enter the number of nodes you want to create in the circular linkedlist.\n");
    scanf("%d",&n);

    //Allocating memory for the head of the linkedList.
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

    //Since the linkedlist is circular, we need to put the lastnode's next as the firstnode
    //of the linkedlist(which is head)
    temp->next = head;

    displayCircularLinkedList(head);
}


void displayCircularLinkedList(struct node* head){

    struct node* temp = head;

    printf("The LinkedList is as follows\n");
    //Traversing the linkedlist till the end.
    do{
        printf(" %d ->", temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("%d",head->data);
}