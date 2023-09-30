#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;

}*head = NULL;


void displayList(struct node*);
void addOne(struct node*);
int main()
{
    int n;
    printf("Enter number of nodes\n");
    scanf("%d",&n);    
    head = (struct node*)malloc(sizeof(struct node));
    int d;
    printf("Enter first Node:\n");
    scanf("%d",&d);
    head->data = d;
    head->next = NULL;    
    struct node* temp = head;

    int i;
    for(i = 2; i<=n; i++)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        int newData;
        printf("Enter the data %d th node\n",i);
        scanf("%d",&newData);       
        newNode->data = newData;
        newNode->next = NULL;      
        temp->next = newNode;       
        temp = newNode;
    }

    displayList(head);
    addOne(head);
}


void displayList(struct node* head)
{

    struct node* temp = head;
    printf("LinkedList is\n");   
    while(temp!=NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
/*void reverselist(struct node* head)
{
    node * prev = NULL;
	node * temp = head;
	node * next;
	while (temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev =temp;
		temp = next;
	}
	return prev;

}*/

void addOne(struct node* head)
{
    int x=0;
    struct node* temp = head; 
    while(temp->next!=NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    x=temp->data+1;
        
    printf(" %d ", temp->data+1);
}