#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int search(int arr[] , int start, int end, char value){
    for(int i = start; i<=end; i++){
        if( arr[i] == value){
            return i;
        }
    }
}
struct node* createNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node*));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* buildTree(int inor[], int preor[], int instart, int inend){
    static int preindex = 0;
    if(instart > inend){
        return NULL;
    }

    struct node* newNode = createNode(preor[preindex++]);


    //if this node has no children, then this will be the case
    if(instart == inend){
        return newNode;
    }

    //Find the index of the same element in the inorder
    int inorderIndex = search(inor,instart,inend,newNode->data);

    //Need to build the left tree from the inindex left side and right tree from inindex right side
    newNode->left = buildTree(inor,preor,instart,inorderIndex-1);
    newNode->right = buildTree(inor,preor,inorderIndex+1, inend);

    return newNode;
    
}

void inorder(struct node* root){
    if(root== NULL){
        return;
    }

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


int main(){
    int inor[] = { 4,2,5,1,6,3};
    int preor[] = { 1,2,4,5,3,6};

    int len = sizeof(inor) / sizeof(inor[0]);

    struct node* root = buildTree(inor,preor, 0, len-1);

    printf("Inorder traversal:");
    inorder(root);

}