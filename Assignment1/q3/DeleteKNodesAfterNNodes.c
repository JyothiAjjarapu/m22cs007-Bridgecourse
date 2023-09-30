#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head = NULL;


void displayLinkedList(struct node*);
void deleteKNodesAfterNNodes(struct node**);
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
    deleteKNodesAfterNNodes(&head);
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

void deleteKNodesAfterNNodes(struct node** head){
    int n;
    int k;
    printf("Please enter the value of K:\n");
    scanf("%d",&k);
    printf("Please enter the value of N:\n");
    scanf("%d",&n);

    struct node* current = *head;

    int i;
    for(i = 2; i<= n; i++){
        //Linkedlist ended before n nodes.
        if(current == NULL){
            return;
        }
        current = current->next;
    }
    //After the for loop the current reaches n nodes. Now we need to delete k nodes after the current.
    struct node* nextNode = current->next;//we will store the node after k nodes in this.
    int j;
    for(int j =1; j<=k; j++){
        if(nextNode == NULL){
            //if the linkedlist ended before k nodes after N.
            current->next = NULL;
            return;
        }
        nextNode = nextNode->next;
    }
    current->next = nextNode;
}