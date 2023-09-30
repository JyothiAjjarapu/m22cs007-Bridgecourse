#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}* root = NULL;

struct node* insert(struct node*,int);
void inorderDisplay(struct node*);
void preorderDisplay(struct node*);
void postorderDisplay(struct node*);
struct node* searchNode(struct node*,int);

int main(){

    int c;
    while(1){
        printf("Binary Search Tree:\n 1.Insert\n 2.Display Inorder\n 3.Display PreOrder\n 4. Display PostOrder\n 5. Search\n 6.Exit\n");
        scanf("%d",&c);
        switch(c){
            case 1: int val;
                    printf("Please enter the data to be inserted:\n");
                    scanf("%d",&val);
                    root = insert(root,val);
                    
                    break;
            case 2: printf("Inorder traversal:\n");
                    inorderDisplay(root);
                    printf("\n");
                    break;
            case 3: printf("PreOrder traversal:\n");
                    preorderDisplay(root);
                    printf("\n");
                    break;
            case 4: printf("PostOrder traversal:\n");
                    postorderDisplay(root);
                    printf("\n");
                    break;
            case 5: int val2;
                    printf("Enter the value to be searched:\n");
                    scanf("%d",&val2);
                    struct node* found = searchNode(root,val2);
                    if(found == NULL){
                        printf("No node found\n");
                    }
                    else{
                        printf("Found %d\n",found->data);
                    }
                    break;
            default: exit(1);
                     break;
        }
    }
}

struct node* insert(struct node* root, int data){
    

    if(root == NULL){
        //While traversing left or right, at one point the root becomes null, there we need to insert this.
        struct node* newNode = (struct node*)malloc(sizeof(struct node*));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else{
        //Traverse left or right to the exact position where to insert and then inserts the node.
        if(data < root->data){
            root->left = insert(root->left,data); //Traversing to the left
        }
        else if( data > root->data){
            root->right = insert(root->right,data); //Traversing to the right.
        }

        return root;
    }

}

void inorderDisplay(struct node* root){
    if(root!=NULL){
        inorderDisplay(root->left);
        printf("%d ",root->data);
        inorderDisplay(root->right);
    }
}

void preorderDisplay(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorderDisplay(root->left);
        preorderDisplay(root->right);
    }
}

void postorderDisplay(struct node* root){
    if(root!= NULL){
        postorderDisplay(root->left);
        postorderDisplay(root->right);
        printf("%d ", root->data);
    }
}

struct node* searchNode(struct node* root, int data){

    if(root == NULL){ //Not found case.
        return NULL;
    }

    if(root->data == data){
        return root;
    }

    if(root->data > data){
        return searchNode(root->left,data);
    }
    else{
        return searchNode(root->right,data);
    }
}



