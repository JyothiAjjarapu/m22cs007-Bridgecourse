#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
}*head = NULL;

void displayDoubleLinkedList(struct node*);
int main(){
    int n; 

    printf("Double Linked List:\n");
    printf("*******************\n");
    printf("Please enter the number of nodes you want to create in the double linkedlist\n");
    scanf("%d",&n);

    //Allocating memory for the first or head node of the DLL.
    head = (struct node*)malloc(sizeof(struct node));
    int d; 
    printf("Enter the data part of the first node:\n");
    scanf("%d",&d);

    //Setting the data part of first node, next and prev are set to null.
    head->data = d;
    head->prev = NULL;
    head->next = NULL;

    //Will use this node to keep track of the last node in the double linkedlist.
    struct node* temp = head;

    int i; 
    for(i = 2; i<=n; i++){
        //Allocating memory for the new node to be created.
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        int newData;
        printf("Enter the data part for the %d th node in the Double Linked List:\n",i);
        scanf("%d",&newData);

        //Setting data of new Node.
        newNode->data = newData;
        //New Node is going to be the last hence newnode-next is null and newnode-prev should 
        //be previous last node(which is temp)
        newNode->next = NULL;
        newNode->prev = temp;

        //previous lastNode's next should be newly created node
        temp->next = newNode;
        //Need to update the lastNode of the doublelinkedlist which would be the newly created one.
        temp = newNode;
    } 
    displayDoubleLinkedList(head);

}

void displayDoubleLinkedList(struct node* head){

    struct node* temp = head;

    printf("The LinkedList is as follows\n");
    //Traversing the linkedlist till the end.
    while(temp!=NULL){
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
