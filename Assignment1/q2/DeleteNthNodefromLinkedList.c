#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head = NULL;

void displayLinkedList(struct node*);
void deleteNthNode(struct node**);
int main(){
    int n; 

    printf("Deleting nth node from Single Linked List\n");
    printf("********************\n");
    printf("Please enter the number of nodes you want to create in the single linkedlist.\n");
    scanf("%d",&n);

    //allocating the memory for head.
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
    deleteNthNode(&head);
    printf("LinkedList After deleting:\n");
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

void deleteNthNode(struct node** head){
    int n;
    printf("Please enter the position where you want to delete:\n");
    scanf("%d",&n);

    struct node* temp = *head;
    if(n == 1){
        *head = temp->next;
        temp->next = NULL;
        free(temp);
        printf("LinkedList After deleting:\n");
        displayLinkedList(head);
        return;
    }
    else{
        int i;
        //Traversing the temp to the (n-1)th position
        //Since we handled delete at position 1, we need to start from 2
        for(i=2; i<=n-1;i++){
            if(temp==NULL){
                printf("N exceeds the length of the linkedList,Cannot be deleted.");
                return;
            }
            temp =temp->next;
        }
        //Now the temp is at the (n-1)th postion.
        
        if(temp->next == NULL){
            printf("There are only %d elements in the list and hence cannot delete %dth element",n-1,n);
            return;
        }

        struct node* delNode = temp->next;
        temp->next = temp->next->next;
        delNode->next = NULL;
        free(delNode);



    }
}

